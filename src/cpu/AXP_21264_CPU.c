/*
 * Copyright (C) Jonathan D. Belanger 2017-2018.
 * All Rights Reserved.
 *
 * This software is furnished under a license and may be used and copied only
 * in accordance with the terms of such license and with the inclusion of the
 * above copyright notice.  This software or any other copies thereof may not
 * be provided or otherwise made available to any other person.  No title to
 * and ownership of the software is hereby transferred.
 *
 * The information in this software is subject to change without notice and
 * should not be construed as a commitment by the author or co-authors.
 *
 * The author and any co-authors assume no responsibility for the use or
 * reliability of this software.
 *
 * Description:
 *
 *	This source file contains the functions needed to create and initialize
 *	the CPU structure and create each of the threads that implement all the
 *	functionality of a Digital Alpha AXP 21264 CPU.
 *
 *	Revision History:
 *
 *	V01.000		17-Nov-2017	Jonathan D. Belanger
 *	Initially written.
 *
 *	V01.001		01-Jan-2018	Jonathan D. Belanger
 *	Added a call to pthread_once to make sure the mutex handling code has been
 *	initialized.
 */
#include "AXP_21264_CPUDefs.h"

/*
 * AXP_21264_AlloateCPU
 * 	This function is called to allocate and initialize the CPU structure.  Some
 * 	of the initialization will be performed by the Cbox, but after all the
 * 	threads have been created in here.
 *
 * Input Parameters:
 * 	None.
 *
 * Output Parameters:
 * 	None.
 *
 * Return Value:
 * 	NULL:	An error occurred allocating and initializing the CPU structure.
 * 	!NULL:	Normal successful completion.
 */
AXP_21264_CPU * AXP_21264_AllocateCPU(void)
{
	AXP_21264_CPU	*cpu = NULL;
	int				pthreadRet;
	int				ii;
	bool			qRet = true;

	cpu = AXP_Allocate_Block(AXP_21264_CPU_BLK);
	if (cpu != NULL)
	{

		/*
		 * First things first.  Create all the mutexes and condition variables.
		 *
		 * Let's start with all the mutexes.
		 */
		pthreadRet = pthread_mutex_init(&cpu->cpuMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->iBoxMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->iBoxIPRMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->iCacheMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->itbMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->eBoxMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->fBoxMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->mBoxMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->mBoxIPRMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->dCacheMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->dtagMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->lqMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->sqMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->dtbMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->cBoxInterfaceMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->cBoxIPRMutex, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_mutex_init(&cpu->bCacheMutex, NULL);

		/*
		 * Let's create the condition variables.
		 */
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->cpuCond, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->iBoxCondition, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->eBoxCondition, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->fBoxCondition, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->mBoxCondition, NULL);
		if (pthreadRet == 0)
			pthreadRet = pthread_cond_init(&cpu->cBoxInterfaceCond, NULL);
		else
			qRet = false;

		/*
		 * Let's initialize the condition queues (these have both a mutex and a
		 * condition variable.  We also have to initialize the preallocated
		 * queue entries.
		 */
		if (qRet == true)
		{
			AXP_INIT_CQUE(cpu->iq, AXP_IQ_LEN);
		}
		if (qRet == true)
		{
			for(ii = 0; ii < AXP_IQ_LEN; ii++)
			{
				AXP_INIT_CQENTRY(cpu->iqEntries[ii].header, cpu->iq);
				cpu->iqEntries[ii].ins = NULL;
				cpu->iqEntries[ii].index = ii;
			}
		}
		if (qRet == true)
		{
			AXP_INIT_CQUE(cpu->fq, AXP_IQ_LEN);
		}
		if (qRet == true)
		{
			for(ii = 0; ii < AXP_FQ_LEN; ii++)
			{
				AXP_INIT_CQENTRY(cpu->fqEntries[ii].header, cpu->fq);
				cpu->fqEntries[ii].ins = NULL;
				cpu->fqEntries[ii].index = ii;
			}
		}

		/*
		 * At this point everything should be initialize.  Time to create all
		 * the threads.
		 */
		if ((pthreadRet == 0) || (qRet == true))
		{
			pthreadRet = pthread_create(
							&cpu->iBoxThreadID,
							NULL,
							AXP_21264_IboxMain,
							cpu);
#if 0
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->eBoxU0ThreadID,
								NULL,
								(void *(void *)) AXP_21264_EboxU0Main,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->eBoxU1ThreadID,
								NULL,
								(void *(void *)) AXP_21264_eBoxU1Main,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->eBoxL0ThreadID,
								NULL,
								(void *(void *)) AXP_21264_EboxL0Main,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->eBoxL1ThreadID,
								NULL,
								(void *(void *)) AXP_21264_EboxL1Main,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->fBoxMulThreadID,
								NULL,
								(void *(void *)) AXP_21264_FboxMulMain,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->fBoxOthThreadID,
								NULL,
								(void *(void *)) AXP_21264_FboxOthMain,
								cpu);
#endif
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->mBoxThreadID,
								NULL,
								AXP_21264_MboxMain,
								cpu);
			if (pthreadRet == 0)
				pthreadRet = pthread_create(
								&cpu->cBoxThreadID,
								NULL,
								AXP_21264_CboxMain,
								cpu);
		}

		/*
		 * If anything happened in error, then deallocate the CPU block just
		 * allocated and return NULL to the caller.
		 */
		if ((cpu != NULL) && ((pthreadRet != 0) || (qRet != true)))
		{
			AXP_Deallocate_Block((AXP_BLOCK_DSC *) cpu);
			cpu = NULL;
		}
	}
	return(cpu);
}

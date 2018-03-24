/*
 * Copyright (C) Jonathan D. Belanger 2018.
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
 *	This source file the System interface functions.
 *
 * Revision History:
 *
 *	V01.000		21-JAN-2018	Jonathan D. Belanger
 *	Initially written.
 */
#include "AXP_Configure.h"
#include "AXP_Utility.h"
#include "AXP_21264_CPU.h"
#include "AXP_21264_CboxDefs.h"
#include "AXP_21274_System.h"

AXP_21274_SYSTEM *sys;

/*
 * AXP_System_CommandSend
 */
void AXP_System_CommandSend(
					AXP_21264_TO_SYS_CMD sysCmd,
					bool miss2,
					int entry,
					bool rqValid,
					u64 mask,
					bool cacheHit,
					u64 pa,
					u8 *sysData,
					int sysDataLen)
{
	AXP_21274_RQ_ENTRY rq = &sys->rq[sys->rqEnd];

	/*
	 * Copy the values into the next request buffer for the Cchip.
	 */
	rq->cmd = sysCmd;
	rq->miss2 = miss2;
	rq->entry = entry;
	rq->rqValid = rqValid;
	rq->mask = mask;
	rq->cacheHit = cacheHit;
	rq->pa = pa;
	memcpy(rq->sysData, sysData, sysDataLen);
	rq->sysDataLen = sysDataLen;

	/*
	 * Set the index to the next location to be filled in by a request.
	 */
	sys->rqEnd++;
	return;
}

/*
 * AXP_System_ProbeResponse
 */
void AXP_System_ProbeResponse(
					bool dataMovement,
					bool victimSent,
					u8 vdbID,
					bool mafAddrSent,
					u8 mafID,
					AXP_21264_PROBE_STAT status)
{

	printf("\n%%DECAXP-I-PRBRSP, AXP_System_ProbeResponse Called.\n");
	return;
}

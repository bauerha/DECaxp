/*
 * Copyright (C) Jonathan D. Belanger 2017.
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
 *	This header file contains the function definitions implemented in the
 *	AXP_21264_Ebox.c module.
 *
 * Revision History:
 *
 *	V01.000		19-Jun-2017	Jonathan D. Belanger
 *	Initially written.
 *
 *	V01.001		29-Jun-2017	Jonathan D. Belanger
 *	Added instruction function prototypes.
 *
 *  V01.002		19-Jul-2017 Jonathan D. Belanger
 *  Added VAX Compatibility and Multimedia instruction prototypes.
 *
 *	V01.003		20-Jul-2017	Jonathan D. Belanger
 *	Added the Miscellaneous instruction prototypes.
 */
#ifndef _AXP_21264_EBOX_DEFS_
#define _AXP_21264_EBOX_DEFS_

#include "AXP_Utility.h"
#include "AXP_Base_CPU.h"
#include "AXP_21264_CPU.h"

/*
 * Ebox Instruction Prototypes
 *
 * Byte Manipulation
 */
AXP_EXCEPTIONS AXP_CMPBGE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTWL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTLL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTQL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTWH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTLH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXTQH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSWL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSLL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSQL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSWH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSLH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_INSQH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKWL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKLL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKQL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKWH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKLH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MSKQH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SEXTB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SEXTW(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SEXTL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ZAP(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ZAPNOT(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Integer Control
 */
AXP_EXCEPTIONS AXP_BEQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BGE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BGT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BLBC(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BLBS(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BLE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BLT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BNE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BR(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BSR(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_JMP(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Integer Arithmetic
 */
AXP_EXCEPTIONS AXP_ADDL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ADDL_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ADDQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ADDQ_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S4ADDL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S8ADDL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S4ADDQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S8ADDQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S4ADDL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMPEQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMPLE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMPLT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMPULE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CTLZ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CTTZ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MULL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MULL_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MULQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MULQ_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_UMULH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SUBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SUBL_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SUBQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SUBQ_V(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S4SUBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S8SUBL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S4SUBQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_S8SUBQ(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Integer Load/Store
 */
AXP_EXCEPTIONS AXP_LDA(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDAH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDBU(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDWU(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDQ_U(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDL_L(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_LDQ_L(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STL_C(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STQ_C(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STW(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_STQ_U(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Integer Logical/Shift
 */
AXP_EXCEPTIONS AXP_AND(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BIS(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_XOR(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_BIC(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ORNOT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EQV(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVEQ(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVGE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVGT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVLBC(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVLBS(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVLE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVLT(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CMOVNE(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SLL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SRL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_SRA(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Miscellaneous Instructions
 */
AXP_EXCEPTIONS AXP_AMASK(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_CALL_PAL(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_ECB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_EXCB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_FETCH(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_FETCH_M(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_IMPLVER(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_RPCC(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_TRAPB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_WH64(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_WH64EN(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_WMB(AXP_21264_CPU *, AXP_INSTRUCTION *);


/*
 * VAX Compatibility
 */
AXP_EXCEPTIONS AXP_RC(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_RS(AXP_21264_CPU *, AXP_INSTRUCTION *);

/*
 * Multimedia (Graphics & Audio)
 */
AXP_EXCEPTIONS AXP_MINUB8(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MINSB8(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MINUW4(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MINSW4(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MAXUB8(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MAXSB8(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MAXUW4(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_MAXSW4(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_PERR(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_PKLB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_PKWB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_UNPKLB(AXP_21264_CPU *, AXP_INSTRUCTION *);
AXP_EXCEPTIONS AXP_UNPKWB(AXP_21264_CPU *, AXP_INSTRUCTION *);

#endif /* _AXP_21264_EBOX_DEFS_ */


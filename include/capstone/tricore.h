#ifndef CAPSTONE_TRICORE_H
#define CAPSTONE_TRICORE_H

/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2014 */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_MSC_VER) || !defined(_KERNEL_MODE)
#include <stdint.h>
#endif

#include "cs_operand.h"
#include "platform.h"

#ifdef _MSC_VER
#pragma warning(disable : 4201)
#endif

/// Operand type for instruction's operands
typedef enum tricore_op_type {
	TRICORE_OP_INVALID = CS_OP_INVALID, ///< CS_OP_INVALID (Uninitialized).
	TRICORE_OP_REG = CS_OP_REG,	    ///< CS_OP_REG (Register operand).
	TRICORE_OP_IMM = CS_OP_IMM,	    ///< CS_OP_IMM (Immediate operand).
	TRICORE_OP_MEM = CS_OP_MEM,	    ///< CS_OP_MEM (Memory operand).
} tricore_op_type;

/// Instruction's operand referring to memory
/// This is associated with TRICORE_OP_MEM operand type above
typedef struct tricore_op_mem {
	uint8_t base; ///< base register
	int64_t disp; ///< displacement/offset value
} tricore_op_mem;

/// Instruction operand
typedef struct cs_tricore_op {
	tricore_op_type type;	    ///< operand type
	union {
		unsigned int reg;   ///< register value for REG operand
		int64_t imm;	    ///< immediate value for IMM operand
		tricore_op_mem mem; ///< base/disp value for MEM operand
	};
	/// This field is combined of cs_ac_type.
	/// NOTE: this field is irrelevant if engine is compiled in DIET mode.
	uint8_t access; ///< How is this operand accessed? (READ, WRITE or READ|WRITE)
} cs_tricore_op;

#define NUM_TRICORE_OPS 8

/// Instruction structure
typedef struct cs_tricore {
	uint8_t op_count; ///< number of operands of this instruction.
	cs_tricore_op
		operands[NUM_TRICORE_OPS]; ///< operands for this instruction.
	/// TODO: Mark the modified flags register in td files and regenerate inc files
	bool update_flags; ///< whether the flags register is updated.
} cs_tricore;

/// TriCore registers
typedef enum tricore_reg {
	// generated content <TriCoreGenCSRegEnum.inc> begin
	// clang-format off

	TRICORE_REG_INVALID = 0,
	TRICORE_REG_FCX = 1,
	TRICORE_REG_PC = 2,
	TRICORE_REG_PCXI = 3,
	TRICORE_REG_PSW = 4,
	TRICORE_REG_A0 = 5,
	TRICORE_REG_A1 = 6,
	TRICORE_REG_A2 = 7,
	TRICORE_REG_A3 = 8,
	TRICORE_REG_A4 = 9,
	TRICORE_REG_A5 = 10,
	TRICORE_REG_A6 = 11,
	TRICORE_REG_A7 = 12,
	TRICORE_REG_A8 = 13,
	TRICORE_REG_A9 = 14,
	TRICORE_REG_A10 = 15,
	TRICORE_REG_A11 = 16,
	TRICORE_REG_A12 = 17,
	TRICORE_REG_A13 = 18,
	TRICORE_REG_A14 = 19,
	TRICORE_REG_A15 = 20,
	TRICORE_REG_D0 = 21,
	TRICORE_REG_D1 = 22,
	TRICORE_REG_D2 = 23,
	TRICORE_REG_D3 = 24,
	TRICORE_REG_D4 = 25,
	TRICORE_REG_D5 = 26,
	TRICORE_REG_D6 = 27,
	TRICORE_REG_D7 = 28,
	TRICORE_REG_D8 = 29,
	TRICORE_REG_D9 = 30,
	TRICORE_REG_D10 = 31,
	TRICORE_REG_D11 = 32,
	TRICORE_REG_D12 = 33,
	TRICORE_REG_D13 = 34,
	TRICORE_REG_D14 = 35,
	TRICORE_REG_D15 = 36,
	TRICORE_REG_E0 = 37,
	TRICORE_REG_E2 = 38,
	TRICORE_REG_E4 = 39,
	TRICORE_REG_E6 = 40,
	TRICORE_REG_E8 = 41,
	TRICORE_REG_E10 = 42,
	TRICORE_REG_E12 = 43,
	TRICORE_REG_E14 = 44,
	TRICORE_REG_P0 = 45,
	TRICORE_REG_P2 = 46,
	TRICORE_REG_P4 = 47,
	TRICORE_REG_P6 = 48,
	TRICORE_REG_P8 = 49,
	TRICORE_REG_P10 = 50,
	TRICORE_REG_P12 = 51,
	TRICORE_REG_P14 = 52,
	TRICORE_REG_A0_A1 = 53,
	TRICORE_REG_A2_A3 = 54,
	TRICORE_REG_A4_A5 = 55,
	TRICORE_REG_A6_A7 = 56,
	TRICORE_REG_A8_A9 = 57,
	TRICORE_REG_A10_A11 = 58,
	TRICORE_REG_A12_A13 = 59,
	TRICORE_REG_A14_A15 = 60,
	TRICORE_REG_ENDING, // 61

	// clang-format on
	// generated content <TriCoreGenCSRegEnum.inc> end
} tricore_reg;

/// TriCore instruction
typedef enum tricore_insn {
	// generated content <TriCoreGenCSInsnEnum.inc> begin
	// clang-format off

	TRICORE_INS_INVALID,
	TRICORE_INS_ABSDIFS_B,
	TRICORE_INS_ABSDIFS_H,
	TRICORE_INS_ABSDIFS,
	TRICORE_INS_ABSDIF_B,
	TRICORE_INS_ABSDIF_H,
	TRICORE_INS_ABSDIF,
	TRICORE_INS_ABSS_B,
	TRICORE_INS_ABSS_H,
	TRICORE_INS_ABSS,
	TRICORE_INS_ABS_B,
	TRICORE_INS_ABS_DF,
	TRICORE_INS_ABS_F,
	TRICORE_INS_ABS_H,
	TRICORE_INS_ABS,
	TRICORE_INS_ADDC,
	TRICORE_INS_ADDIH_A,
	TRICORE_INS_ADDIH,
	TRICORE_INS_ADDI,
	TRICORE_INS_ADDSC_AT,
	TRICORE_INS_ADDSC_A,
	TRICORE_INS_ADDS_BU,
	TRICORE_INS_ADDS_B,
	TRICORE_INS_ADDS_H,
	TRICORE_INS_ADDS_HU,
	TRICORE_INS_ADDS_U,
	TRICORE_INS_ADDS,
	TRICORE_INS_ADDX,
	TRICORE_INS_ADD_A,
	TRICORE_INS_ADD_B,
	TRICORE_INS_ADD_DF,
	TRICORE_INS_ADD_F,
	TRICORE_INS_ADD_H,
	TRICORE_INS_ADD,
	TRICORE_INS_ANDN_T,
	TRICORE_INS_ANDN,
	TRICORE_INS_AND_ANDN_T,
	TRICORE_INS_AND_AND_T,
	TRICORE_INS_AND_EQ,
	TRICORE_INS_AND_GE_U,
	TRICORE_INS_AND_GE,
	TRICORE_INS_AND_LT_U,
	TRICORE_INS_AND_LT,
	TRICORE_INS_AND_NE,
	TRICORE_INS_AND_NOR_T,
	TRICORE_INS_AND_OR_T,
	TRICORE_INS_AND_T,
	TRICORE_INS_AND,
	TRICORE_INS_BISR,
	TRICORE_INS_BMERGE,
	TRICORE_INS_BSPLIT,
	TRICORE_INS_CACHEA_I,
	TRICORE_INS_CACHEA_WI,
	TRICORE_INS_CACHEA_W,
	TRICORE_INS_CACHEI_I,
	TRICORE_INS_CACHEI_WI,
	TRICORE_INS_CACHEI_W,
	TRICORE_INS_CADDN_A,
	TRICORE_INS_CADDN,
	TRICORE_INS_CADD_A,
	TRICORE_INS_CADD,
	TRICORE_INS_CALLA,
	TRICORE_INS_CALLI,
	TRICORE_INS_CALL,
	TRICORE_INS_CLO_B,
	TRICORE_INS_CLO_H,
	TRICORE_INS_CLO,
	TRICORE_INS_CLS_B,
	TRICORE_INS_CLS_H,
	TRICORE_INS_CLS,
	TRICORE_INS_CLZ_B,
	TRICORE_INS_CLZ_H,
	TRICORE_INS_CLZ,
	TRICORE_INS_CMOVN,
	TRICORE_INS_CMOV,
	TRICORE_INS_CMPSWAP_W,
	TRICORE_INS_CMP_DF,
	TRICORE_INS_CMP_F,
	TRICORE_INS_CRC32B_W,
	TRICORE_INS_CRC32L_W,
	TRICORE_INS_CRC32_B,
	TRICORE_INS_CRCN,
	TRICORE_INS_CSUBN_A,
	TRICORE_INS_CSUBN,
	TRICORE_INS_CSUB_A,
	TRICORE_INS_CSUB,
	TRICORE_INS_DEBUG,
	TRICORE_INS_DEXTR,
	TRICORE_INS_DFTOF,
	TRICORE_INS_DFTOIN,
	TRICORE_INS_DFTOIZ,
	TRICORE_INS_DFTOI,
	TRICORE_INS_DFTOLZ,
	TRICORE_INS_DFTOL,
	TRICORE_INS_DFTOULZ,
	TRICORE_INS_DFTOUL,
	TRICORE_INS_DFTOUZ,
	TRICORE_INS_DFTOU,
	TRICORE_INS_DIFSC_A,
	TRICORE_INS_DISABLE,
	TRICORE_INS_DIV64_U,
	TRICORE_INS_DIV64,
	TRICORE_INS_DIV_DF,
	TRICORE_INS_DIV_F,
	TRICORE_INS_DIV_U,
	TRICORE_INS_DIV,
	TRICORE_INS_DSYNC,
	TRICORE_INS_DVADJ,
	TRICORE_INS_DVINIT_BU,
	TRICORE_INS_DVINIT_B,
	TRICORE_INS_DVINIT_HU,
	TRICORE_INS_DVINIT_H,
	TRICORE_INS_DVINIT_U,
	TRICORE_INS_DVINIT,
	TRICORE_INS_DVSTEP_U,
	TRICORE_INS_DVSTEP,
	TRICORE_INS_ENABLE,
	TRICORE_INS_EQANY_B,
	TRICORE_INS_EQANY_H,
	TRICORE_INS_EQZ_A,
	TRICORE_INS_EQ_A,
	TRICORE_INS_EQ_B,
	TRICORE_INS_EQ_H,
	TRICORE_INS_EQ_W,
	TRICORE_INS_EQ,
	TRICORE_INS_EXTR_U,
	TRICORE_INS_EXTR,
	TRICORE_INS_FCALLA,
	TRICORE_INS_FCALLI,
	TRICORE_INS_FCALL,
	TRICORE_INS_FRET,
	TRICORE_INS_FTODF,
	TRICORE_INS_FTOHP,
	TRICORE_INS_FTOIN,
	TRICORE_INS_FTOIZ,
	TRICORE_INS_FTOI,
	TRICORE_INS_FTOQ31Z,
	TRICORE_INS_FTOQ31,
	TRICORE_INS_FTOUZ,
	TRICORE_INS_FTOU,
	TRICORE_INS_GE_A,
	TRICORE_INS_GE_U,
	TRICORE_INS_GE,
	TRICORE_INS_HPTOF,
	TRICORE_INS_IMASK,
	TRICORE_INS_INSERT,
	TRICORE_INS_INSN_T,
	TRICORE_INS_INS_T,
	TRICORE_INS_ISYNC,
	TRICORE_INS_ITODF,
	TRICORE_INS_ITOF,
	TRICORE_INS_IXMAX_U,
	TRICORE_INS_IXMAX,
	TRICORE_INS_IXMIN_U,
	TRICORE_INS_IXMIN,
	TRICORE_INS_JA,
	TRICORE_INS_JEQ_A,
	TRICORE_INS_JEQ,
	TRICORE_INS_JGEZ,
	TRICORE_INS_JGE_U,
	TRICORE_INS_JGE,
	TRICORE_INS_JGTZ,
	TRICORE_INS_JI,
	TRICORE_INS_JLA,
	TRICORE_INS_JLEZ,
	TRICORE_INS_JLI,
	TRICORE_INS_JLTZ,
	TRICORE_INS_JLT_U,
	TRICORE_INS_JLT,
	TRICORE_INS_JL,
	TRICORE_INS_JNED,
	TRICORE_INS_JNEI,
	TRICORE_INS_JNE_A,
	TRICORE_INS_JNE,
	TRICORE_INS_JNZ_A,
	TRICORE_INS_JNZ_T,
	TRICORE_INS_JNZ,
	TRICORE_INS_JZ_A,
	TRICORE_INS_JZ_T,
	TRICORE_INS_JZ,
	TRICORE_INS_J,
	TRICORE_INS_LDLCX,
	TRICORE_INS_LDMST,
	TRICORE_INS_LDUCX,
	TRICORE_INS_LD_A,
	TRICORE_INS_LD_BU,
	TRICORE_INS_LD_B,
	TRICORE_INS_LD_DA,
	TRICORE_INS_LD_D,
	TRICORE_INS_LD_HU,
	TRICORE_INS_LD_H,
	TRICORE_INS_LD_Q,
	TRICORE_INS_LD_W,
	TRICORE_INS_LEA,
	TRICORE_INS_LHA,
	TRICORE_INS_LOOPU,
	TRICORE_INS_LOOP,
	TRICORE_INS_LTODF,
	TRICORE_INS_LT_A,
	TRICORE_INS_LT_B,
	TRICORE_INS_LT_BU,
	TRICORE_INS_LT_H,
	TRICORE_INS_LT_HU,
	TRICORE_INS_LT_U,
	TRICORE_INS_LT_W,
	TRICORE_INS_LT_WU,
	TRICORE_INS_LT,
	TRICORE_INS_MADDMS_H,
	TRICORE_INS_MADDMS_U,
	TRICORE_INS_MADDMS,
	TRICORE_INS_MADDM_H,
	TRICORE_INS_MADDM_Q,
	TRICORE_INS_MADDM_U,
	TRICORE_INS_MADDM,
	TRICORE_INS_MADDRS_H,
	TRICORE_INS_MADDRS_Q,
	TRICORE_INS_MADDR_H,
	TRICORE_INS_MADDR_Q,
	TRICORE_INS_MADDSUMS_H,
	TRICORE_INS_MADDSUM_H,
	TRICORE_INS_MADDSURS_H,
	TRICORE_INS_MADDSUR_H,
	TRICORE_INS_MADDSUS_H,
	TRICORE_INS_MADDSU_H,
	TRICORE_INS_MADDS_H,
	TRICORE_INS_MADDS_Q,
	TRICORE_INS_MADDS_U,
	TRICORE_INS_MADDS,
	TRICORE_INS_MADD_DF,
	TRICORE_INS_MADD_F,
	TRICORE_INS_MADD_H,
	TRICORE_INS_MADD_Q,
	TRICORE_INS_MADD_U,
	TRICORE_INS_MADD,
	TRICORE_INS_MAX_B,
	TRICORE_INS_MAX_BU,
	TRICORE_INS_MAX_DF,
	TRICORE_INS_MAX_F,
	TRICORE_INS_MAX_H,
	TRICORE_INS_MAX_HU,
	TRICORE_INS_MAX_U,
	TRICORE_INS_MAX,
	TRICORE_INS_MFCR,
	TRICORE_INS_MIN_B,
	TRICORE_INS_MIN_BU,
	TRICORE_INS_MIN_DF,
	TRICORE_INS_MIN_F,
	TRICORE_INS_MIN_H,
	TRICORE_INS_MIN_HU,
	TRICORE_INS_MIN_U,
	TRICORE_INS_MIN,
	TRICORE_INS_MOVH_A,
	TRICORE_INS_MOVH,
	TRICORE_INS_MOVZ_A,
	TRICORE_INS_MOV_AA,
	TRICORE_INS_MOV_A,
	TRICORE_INS_MOV_D,
	TRICORE_INS_MOV_U,
	TRICORE_INS_MOV,
	TRICORE_INS_MSUBADMS_H,
	TRICORE_INS_MSUBADM_H,
	TRICORE_INS_MSUBADRS_H,
	TRICORE_INS_MSUBADR_H,
	TRICORE_INS_MSUBADS_H,
	TRICORE_INS_MSUBAD_H,
	TRICORE_INS_MSUBMS_H,
	TRICORE_INS_MSUBMS_U,
	TRICORE_INS_MSUBMS,
	TRICORE_INS_MSUBM_H,
	TRICORE_INS_MSUBM_Q,
	TRICORE_INS_MSUBM_U,
	TRICORE_INS_MSUBM,
	TRICORE_INS_MSUBRS_H,
	TRICORE_INS_MSUBRS_Q,
	TRICORE_INS_MSUBR_H,
	TRICORE_INS_MSUBR_Q,
	TRICORE_INS_MSUBS_H,
	TRICORE_INS_MSUBS_Q,
	TRICORE_INS_MSUBS_U,
	TRICORE_INS_MSUBS,
	TRICORE_INS_MSUB_DF,
	TRICORE_INS_MSUB_F,
	TRICORE_INS_MSUB_H,
	TRICORE_INS_MSUB_Q,
	TRICORE_INS_MSUB_U,
	TRICORE_INS_MSUB,
	TRICORE_INS_MTCR,
	TRICORE_INS_MULMS_H,
	TRICORE_INS_MULM_H,
	TRICORE_INS_MULM_U,
	TRICORE_INS_MULM,
	TRICORE_INS_MULR_H,
	TRICORE_INS_MULR_Q,
	TRICORE_INS_MULS_U,
	TRICORE_INS_MULS,
	TRICORE_INS_MUL_DF,
	TRICORE_INS_MUL_F,
	TRICORE_INS_MUL_H,
	TRICORE_INS_MUL_Q,
	TRICORE_INS_MUL_U,
	TRICORE_INS_MUL,
	TRICORE_INS_NAND_T,
	TRICORE_INS_NAND,
	TRICORE_INS_NEG_DF,
	TRICORE_INS_NEG_F,
	TRICORE_INS_NEZ_A,
	TRICORE_INS_NE_A,
	TRICORE_INS_NE,
	TRICORE_INS_NOP,
	TRICORE_INS_NOR_T,
	TRICORE_INS_NOR,
	TRICORE_INS_NOT,
	TRICORE_INS_ORN_T,
	TRICORE_INS_ORN,
	TRICORE_INS_OR_ANDN_T,
	TRICORE_INS_OR_AND_T,
	TRICORE_INS_OR_EQ,
	TRICORE_INS_OR_GE_U,
	TRICORE_INS_OR_GE,
	TRICORE_INS_OR_LT_U,
	TRICORE_INS_OR_LT,
	TRICORE_INS_OR_NE,
	TRICORE_INS_OR_NOR_T,
	TRICORE_INS_OR_OR_T,
	TRICORE_INS_OR_T,
	TRICORE_INS_OR,
	TRICORE_INS_PACK,
	TRICORE_INS_PARITY,
	TRICORE_INS_POPCNT_W,
	TRICORE_INS_Q31TOF,
	TRICORE_INS_QSEED_DF,
	TRICORE_INS_QSEED_F,
	TRICORE_INS_REM64_U,
	TRICORE_INS_REM64,
	TRICORE_INS_RESTORE,
	TRICORE_INS_RET,
	TRICORE_INS_RFE,
	TRICORE_INS_RFM,
	TRICORE_INS_RSLCX,
	TRICORE_INS_RSTV,
	TRICORE_INS_RSUBS_U,
	TRICORE_INS_RSUBS,
	TRICORE_INS_RSUB,
	TRICORE_INS_SAT_BU,
	TRICORE_INS_SAT_B,
	TRICORE_INS_SAT_HU,
	TRICORE_INS_SAT_H,
	TRICORE_INS_SELN_A,
	TRICORE_INS_SELN,
	TRICORE_INS_SEL_A,
	TRICORE_INS_SEL,
	TRICORE_INS_SHAS,
	TRICORE_INS_SHA_B,
	TRICORE_INS_SHA_H,
	TRICORE_INS_SHA,
	TRICORE_INS_SHUFFLE,
	TRICORE_INS_SH_ANDN_T,
	TRICORE_INS_SH_AND_T,
	TRICORE_INS_SH_B,
	TRICORE_INS_SH_EQ,
	TRICORE_INS_SH_GE_U,
	TRICORE_INS_SH_GE,
	TRICORE_INS_SH_H,
	TRICORE_INS_SH_LT_U,
	TRICORE_INS_SH_LT,
	TRICORE_INS_SH_NAND_T,
	TRICORE_INS_SH_NE,
	TRICORE_INS_SH_NOR_T,
	TRICORE_INS_SH_ORN_T,
	TRICORE_INS_SH_OR_T,
	TRICORE_INS_SH_XNOR_T,
	TRICORE_INS_SH_XOR_T,
	TRICORE_INS_SH,
	TRICORE_INS_STLCX,
	TRICORE_INS_STUCX,
	TRICORE_INS_ST_A,
	TRICORE_INS_ST_B,
	TRICORE_INS_ST_DA,
	TRICORE_INS_ST_D,
	TRICORE_INS_ST_H,
	TRICORE_INS_ST_Q,
	TRICORE_INS_ST_T,
	TRICORE_INS_ST_W,
	TRICORE_INS_SUBC,
	TRICORE_INS_SUBSC_A,
	TRICORE_INS_SUBS_BU,
	TRICORE_INS_SUBS_B,
	TRICORE_INS_SUBS_HU,
	TRICORE_INS_SUBS_H,
	TRICORE_INS_SUBS_U,
	TRICORE_INS_SUBS,
	TRICORE_INS_SUBX,
	TRICORE_INS_SUB_A,
	TRICORE_INS_SUB_B,
	TRICORE_INS_SUB_DF,
	TRICORE_INS_SUB_F,
	TRICORE_INS_SUB_H,
	TRICORE_INS_SUB,
	TRICORE_INS_SVLCX,
	TRICORE_INS_SWAPMSK_W,
	TRICORE_INS_SWAP_A,
	TRICORE_INS_SWAP_W,
	TRICORE_INS_SYSCALL,
	TRICORE_INS_TLBDEMAP,
	TRICORE_INS_TLBFLUSH_A,
	TRICORE_INS_TLBFLUSH_B,
	TRICORE_INS_TLBMAP,
	TRICORE_INS_TLBPROBE_A,
	TRICORE_INS_TLBPROBE_I,
	TRICORE_INS_TRAPSV,
	TRICORE_INS_TRAPV,
	TRICORE_INS_ULTODF,
	TRICORE_INS_UNPACK,
	TRICORE_INS_UPDFL,
	TRICORE_INS_UTODF,
	TRICORE_INS_UTOF,
	TRICORE_INS_WAIT,
	TRICORE_INS_XNOR_T,
	TRICORE_INS_XNOR,
	TRICORE_INS_XOR_EQ,
	TRICORE_INS_XOR_GE_U,
	TRICORE_INS_XOR_GE,
	TRICORE_INS_XOR_LT_U,
	TRICORE_INS_XOR_LT,
	TRICORE_INS_XOR_NE,
	TRICORE_INS_XOR_T,
	TRICORE_INS_XOR,

	// clang-format on
	// generated content <TriCoreGenCSInsnEnum.inc> end
	TRICORE_INS_ENDING, // <-- mark the end of the list of instructions
} tricore_insn;

/// Group of TriCore instructions
typedef enum tricore_insn_group {
	TRICORE_GRP_INVALID, ///< = CS_GRP_INVALID
	/// Generic groups
	TRICORE_GRP_CALL,   ///< = CS_GRP_CALL
	TRICORE_GRP_JUMP,   ///< = CS_GRP_JUMP
	TRICORE_GRP_ENDING, ///< mark the end of the list of groups
} tricore_insn_group;

typedef enum tricore_feature_t {
	TRICORE_FEATURE_INVALID = 0,
	// generated content <TriCoreGenCSFeatureEnum.inc> begin
	// clang-format off

	TRICORE_FEATURE_HASV110 = 128,
	TRICORE_FEATURE_HASV120,
	TRICORE_FEATURE_HASV130,
	TRICORE_FEATURE_HASV131,
	TRICORE_FEATURE_HASV160,
	TRICORE_FEATURE_HASV161,
	TRICORE_FEATURE_HASV162,
	TRICORE_FEATURE_HASV180,
	TRICORE_FEATURE_HASV120_UP,
	TRICORE_FEATURE_HASV130_UP,
	TRICORE_FEATURE_HASV131_UP,
	TRICORE_FEATURE_HASV160_UP,
	TRICORE_FEATURE_HASV161_UP,
	TRICORE_FEATURE_HASV162_UP,
	TRICORE_FEATURE_HASV180_UP,
	TRICORE_FEATURE_HASV120_DN,
	TRICORE_FEATURE_HASV130_DN,
	TRICORE_FEATURE_HASV131_DN,
	TRICORE_FEATURE_HASV160_DN,
	TRICORE_FEATURE_HASV161_DN,
	TRICORE_FEATURE_HASV162_DN,
	TRICORE_FEATURE_HASV180_DN,

	// clang-format on
	// generated content <TriCoreGenCSFeatureEnum.inc> end
	TRICORE_FEATURE_ENDING, ///< mark the end of the list of features
} tricore_feature;

#ifdef __cplusplus
}
#endif

#endif

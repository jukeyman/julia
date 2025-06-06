// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef JL_APINT_C_H
#define JL_APINT_C_H

#include "julia.h"
#include "dtypes.h"
#include "llvm-version.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__cplusplus) && defined(LLVM_VERSION_MAJOR)
using integerPart = llvm::APInt::WordType;
#else
typedef void integerPart;
#endif

JL_DLLEXPORT void LLVMNeg(unsigned numbits, integerPart *pa, integerPart *pr);
JL_DLLEXPORT void LLVMByteSwap(unsigned numbits, integerPart *pa, integerPart *pr);

JL_DLLEXPORT void LLVMAdd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMSub(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMMul(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMSDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMUDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMSRem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMURem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

JL_DLLEXPORT void LLVMAnd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMOr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMXor(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMShl(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMLShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMAShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void LLVMFlipAllBits(unsigned numbits, integerPart *pa, integerPart *pr);

JL_DLLEXPORT int LLVMICmpEQ(unsigned numbits, integerPart *pa, integerPart *pr);
JL_DLLEXPORT int LLVMICmpNE(unsigned numbits, integerPart *pa, integerPart *pb);
JL_DLLEXPORT int LLVMICmpSLT(unsigned numbits, integerPart *pa, integerPart *pb);
JL_DLLEXPORT int LLVMICmpULT(unsigned numbits, integerPart *pa, integerPart *pb);
JL_DLLEXPORT int LLVMICmpSLE(unsigned numbits, integerPart *pa, integerPart *pb);
JL_DLLEXPORT int LLVMICmpULE(unsigned numbits, integerPart *pa, integerPart *pb);

JL_DLLEXPORT int LLVMAdd_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMAdd_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMSub_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMSub_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMMul_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMMul_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMDiv_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMDiv_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMRem_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT int LLVMRem_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

JL_DLLEXPORT unsigned LLVMPopcount(unsigned numbits, integerPart *pa);
JL_DLLEXPORT unsigned LLVMCountr_one(unsigned numbits, integerPart *pa);
JL_DLLEXPORT unsigned LLVMCountr_zero(unsigned numbits, integerPart *pa);
JL_DLLEXPORT unsigned LLVMCountl_one(unsigned numbits, integerPart *pa);
JL_DLLEXPORT unsigned LLVMCountl_zero(unsigned numbits, integerPart *pa);

JL_DLLEXPORT void LLVMFPtoSI(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMFPtoUI(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMSItoFP(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMUItoFP(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMSExt(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMZExt(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT void LLVMTrunc(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);

JL_DLLEXPORT int LLVMFPtoSI_exact(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);
JL_DLLEXPORT int LLVMFPtoUI_exact(jl_datatype_t *ty, integerPart *pa, jl_datatype_t *oty, integerPart *pr);

JL_DLLEXPORT void jl_LLVMSMod(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
JL_DLLEXPORT void jl_LLVMFlipSign(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

JL_DLLEXPORT unsigned countr_zero_8(uint8_t Val);
JL_DLLEXPORT unsigned countr_zero_16(uint16_t Val);
JL_DLLEXPORT unsigned countr_zero_32(uint32_t Val);
JL_DLLEXPORT unsigned countr_zero_64(uint64_t Val);

//uint8_t getSwappedBytes_8(uint8_t Value); // no-op
//uint16_t getSwappedBytes_16(uint16_t Value);
//uint32_t getSwappedBytes_32(uint32_t Value);
//uint64_t getSwappedBytes_64(uint64_t Value);


#ifdef __cplusplus
}
#endif

#endif

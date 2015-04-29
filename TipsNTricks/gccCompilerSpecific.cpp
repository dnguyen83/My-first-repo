#include "gccCompilerSpecific.h"

void getCompiler()
{
#if defined(__clang__)
	/* Clang/LLVM. ---------------------------------------------- */
	TIPS_TRACE("Compiler: Clang/LLVM");
#elif defined(__ICC) || defined(__INTEL_COMPILER)
	/* Intel ICC/ICPC. ------------------------------------------ */
	TIPS_TRACE("Compiler: ICC/ICPC");
#elif defined(__GNUC__) || defined(__GNUG__)
	/* GNU GCC/G++. --------------------------------------------- */
	TIPS_TRACE("Compiler: GNU GCC/G++");
#elif defined(__HP_cc) || defined(__HP_aCC)
	/* Hewlett-Packard C/aC++. ---------------------------------- */
	TIPS_TRACE("Compiler: Hewlett-Packard C/aC++");
#elif defined(__IBMC__) || defined(__IBMCPP__)
	/* IBM XL C/C++. -------------------------------------------- */
	TIPS_TRACE("Compiler: IBM XL C/C++");
#elif defined(_MSC_VER)
	/* Microsoft Visual Studio. --------------------------------- */
	TIPS_TRACE("Compiler: Microsoft Visual Studio");
#elif defined(__PGI)
	/* Portland Group PGCC/PGCPP. ------------------------------- */
	TIPS_TRACE("Compiler: Portland Group PGCC/PGCPP");
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
	/* Oracle Solaris Studio. ----------------------------------- */
	TIPS_TRACE("Compiler: Oracle Solaris Studio");
#endif
}

void branchPrediction()
{
	//More of a trick of the GCC compiler, but you can give branch indication hints to the compiler (common in the Linux kernel)
#if defined(__GNUC__) || defined(__GNUG__)
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

	if (unlikely(1 == 0)) {
		TIPS_TRACE("unlikely");
		return;
	}
	TIPS_TRACE("likely");
#endif
}
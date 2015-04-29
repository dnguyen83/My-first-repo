#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_
#include "headers.h"

#define TIPS_DEBUG_TRACE
#define TIPS_DEBUG_ERROR
#define BEGIN_MACRO do {
#define END_MACRO	} while(0)

#define TIPS_PREFIX			"[IduDaemon] "
#define TIPS_PRINTF(...)		printf(__VA_ARGS__)

#ifdef TIPS_DEBUG_TRACE
#define TIPS_TRACE(...)		do { TIPS_PRINTF("%s", TIPS_PREFIX); TIPS_PRINTF(__VA_ARGS__); TIPS_PRINTF("\n");} while(0)
#define TIPS_FTRACE(...)		do { TIPS_PRINTF(TIPS_PREFIX "%s(%d) %s: ", __FILE__,__LINE__,__FUNCTION__); TIPS_PRINTF(__VA_ARGS__); } while(0)
#define TIPS_STRACE(_a)		TIPS_FTRACE("%s = {%s}\n", #_a, _a ? _a : "(NULL)")
#define TIPS_XTRACE(_a)		TIPS_FTRACE("%s = {0x%08x}\n", #_a, _a)
#define TIPS_BTRACE(_a)		TIPS_FTRACE("%s = {%s}\n", #_a, _a ? "true" : "false")
#else
#define TIPS_TRACE(...)
#define TIPS_FTRACE(...)
#define TIPS_STRACE(...)
#define TIPS_XTRACE(...)
#define TIPS_BTRACE(...)
#endif

#ifdef TIPS_DEBUG_ERROR
#define TIPS_ISOK(x)			if (x < 0) { printf(TIPS_PREFIX "%s(%d) %s: TIPS_ISOK::0x%x\n",__FILE__,__LINE__,__FUNCTION__, x); return x; }
#define TIPS_ISOK2(x)		if (x < 0) { printf(TIPS_PREFIX "%s(%d) %s: TIPS_ISOK::0x%x->0x%x\n",__FILE__,__LINE__,__FUNCTION__, x, sceKernelError(errno)); return sceKernelError(errno); }
#define TIPS_ISOK_RES(x, y)	if (x < 0) { printf(TIPS_PREFIX "%s(%d) %s: TIPS_ISOK::0x%x->0x%x\n",__FILE__,__LINE__,__FUNCTION__, x, y); return y; }
#define TIPS_RTRACE(x)		if (x < 0) { printf(TIPS_PREFIX "%s(%d) %s: TIPS_RTRACE::0x%x\n",__FILE__,__LINE__,__FUNCTION__, x); }
#define TIPS_RTRACE2(x)		if (x < 0) { printf(TIPS_PREFIX "%s(%d) %s: TIPS_RTRACE::0x%x->0x%x\n",__FILE__,__LINE__,__FUNCTION__, x, sceKernelError(errno)); }
#define TIPS_CHECK(x, y)		if (!(x))  { printf(TIPS_PREFIX "%s(%d) %s: TIPS_CHECK::0x%x (%s value is NULL)\n",__FILE__,__LINE__,__FUNCTION__, y, #x); return y; }
#define TIPS_ASSERT assert
#else
#define TIPS_ISOK(x)			if (x < 0) { return x; }
#define TIPS_ISOK2(x)		if (x < 0) { return sceKernelError(errno); }
#define TIPS_ISOK_RES(x, y)	if (x < 0) { return y; }
#define TIPS_RTRACE(x)		if (x < 0) { }
#define TIPS_RTRACE2(x)		if (x < 0) { }
#define TIPS_CHECK(x, y)		if (!(x))  { return y; }
#define TIPS_ASSERT(...)
#endif

#define TIPS_CALL(_exp)				do { TIPS_FTRACE("CALL %s\n", #_exp); SceInt32 _res = _exp; TIPS_ISOK(_res); } while(0)
#define TIPS_CALL_RES(_exp, _res)	do { TIPS_FTRACE("CALL %s\n", #_exp); SceInt32 _tmp = _exp; TIPS_ISOK_RES(_tmp, _res); } while(0)
#define TIPS_CALL_SET(_exp, _res)	do { TIPS_FTRACE("CALL %s\n", #_exp); _res = _exp; } while(0)

void runPreprocessor();

#endif // endof _PREPROCESSOR_H_
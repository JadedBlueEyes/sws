#ifndef _H_SWS_UTILITY_H_
#define _H_SWS_UTILITY_H_
#include <Windows.h>
inline long long sws_milliseconds_now() {
    LARGE_INTEGER s_frequency;
    BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    }
    else {
        return GetTickCount();
    }
}
#endif
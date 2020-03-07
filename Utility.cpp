#include "Utility.h"
#include <stdio.h>
#include <time.h>

#ifdef PLATFORM_WIN
#include <Windows.h>


int print_log(const char* format, ...)
{
	static char s_printf_buf[1024];
	va_list args;
	va_start(args, format);
	_vsnprintf_s(s_printf_buf, sizeof(s_printf_buf), format, args);
	va_end(args);
	OutputDebugStringA(s_printf_buf);
	return 0;
}
#else
int print_log(const char* format, ...)
{
	return 0;
}
#endif

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

long GetTime()
{
	return clock() / CLOCKS_PER_MS;
};

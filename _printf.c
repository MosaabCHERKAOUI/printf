#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	va_end(args);
}

#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i, sum;

	va_start(args, format);

	for (i = 0; i < 2; i++)
	{
		sum = va_arg(args, int);
	}
	va_end(args);
	return (sum);
}

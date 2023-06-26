#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - my printf
 * @format: strings
 * @...: s, c, %
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0, fix = 0, lenn = 0;
	char *s, c, modu, bracket = ']', *newline = "\n";

	va_start(args, format);
	while (format[len])
		len++;


	for (i = 0; i < len; i++)
		if (format[i] == '%')
		{
			fix = i;
		}

	write(1, format, fix);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char*);
			lenn = strlen(s);
			write(1, s, lenn);
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &modu, 1);
		}
	}
	write(1, &bracket, 1);
	write(1, newline, 1);
	va_end(args);

	return (0);
}

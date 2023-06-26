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
	int i, len = 0, fix = 0, lenn = 0, len3 = 0;
	char *s, c, bracket = ']', *newline = "\n";

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
			len3++;
			write(1, &c, 1);
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char*);
			len3 = strlen(s);
			lenn = strlen(s);
			write(1, s, lenn);
		}
	}
	write(1, &bracket, 1);
	write(1, newline, 1);
	va_end(args);

	return (len - 2 + len3);
}

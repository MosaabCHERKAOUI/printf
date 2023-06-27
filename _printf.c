#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * _printf - my own printf
 * @format: is character string
 *
 * Return: lenght
 */
int _printf(const char *format, ...)
{
	int sum = 0, len = 0, i;
	va_list args;
	char c, *s;

	va_start(args, format);

	len = strlen(format);

	for (i = 0; i < len - 1; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			sum++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char*);
			write(1, s, strlen(s));
			sum += strlen(s);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			sum++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			sum++;
			i++;
		}
	}
	_putchar('\n');

	va_end(args);
	return (sum);
}

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
	int c, sum = 0, len = 0, i, len1 = 0, o;
	va_list args;
	char *s;

	va_start(args, format);
	len = strlen(format);
	if (format == NULL || (format[0] == '%' && format[1] == NULL))
		return (-1);
	for (i = 0; i < len; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			sum++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char *);
			len1 = strlen(s);
			for (o = 0; o < len1; o++)
			{
				_putchar(s[o]);
				sum++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			_putchar(c);
			sum++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			sum++;
			i++;
		}
	}
	va_end(args);
	return (sum);
}

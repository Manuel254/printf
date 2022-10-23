#include "main.h"

/**
 * _printf - prints ouput
 * @format: character string
 *
 * Return: length of buffer
 */
int _printf(const char *format, ...)
{
	char buffer[100], *str_arg;
	unsigned int i, j, k, len, len_arg;
	va_list arg;

	j = 0;
	len = strlen(format);

	va_start(arg, format);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				buffer[j] = '%';
				j++;
			}
			else if (format[i] == 'c')
			{
				buffer[j] = (char)va_arg(arg, int);
				j++;
			}
			else if (format[i] == 's')
			{
				str_arg = va_arg(arg, char*);
				len_arg = strlen(str_arg);

				for (k = 0; k < len_arg; k++)
				{
					buffer[j] = str_arg[k];
					j++;
				}
			}
			else
			{
				continue;
				j++;
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
	}
	buffer[j] = '\0';

	va_end(arg);
	write(1, buffer, strlen(buffer));

	return (strlen(buffer));
}

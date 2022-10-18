
#include "main.h"

/**
* _printf - A function that produces output according to a format.
* @format: param to use for formatting
* Return: the number of characters printed
* (excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
unsigned int i;
int identifierPrinted = 0, charPrinted = 0;
va_list arg;

va_start(arg, format);
if (format == NULL)
return (-1);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
_putchar(format[i]);
charPrinted++;
continue;
}
if (format[i + 1] == '%')
{
_putchar('%');
charPrinted++;
i++;
continue;
}
if (format[i + 1] == '\0')
return (-1);

identifierPrinted = printIdentifiers(format[i + 1], arg);
if (identifierPrinted == -1 || identifierPrinted != 0)
i++;
if (identifierPrinted > 0)
charPrinted += identifierPrinted;

if (identifierPrinted == 0)
{
_putchar('%');
charPrinted++;
}
}
va_end(arg);
return (charPrinted);
}

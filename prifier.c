#include "main.h"

/**
* printIdentifiers - prints special characters
* @next: character after the %
* @arg: argument for the indentifier
* Return: the number of characters printed
* (excluding the null byte used to end output to strings)
*/

int printIdentifiers(char next, va_list arg)
{
int functsIndex;

identifierStruct functs[] = {
{"c", print_char},
{"s", print_str},
{"d", print_int},
{"i", print_int},
{"u", print_unsigned},
{"b", print_unsignedToBinary},
{"o", print_oct},
{"x", print_hex},
{"X", print_HEX},
{"S", print_STR},
{NULL, NULL}
};

for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
{
if (functs[functsIndex].indentifier[0] == next)
return (functs[functsIndex].printer(arg));
}
return (0);
}

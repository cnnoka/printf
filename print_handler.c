#include "main.h"
/**
 * print_handler - Prints an argument based on its type
 * @fmtstr: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @index: index at which the number starts in the buffer
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @preci: specification of the precision
 * @size: specification of the size
 * Return: 1 or 2;
 */
int print_handler(const char *fmtstr, int *index, va_list list, char buffer[],
        int flags, int width, int preci, int size)
{
        int a, unknow_len = 0, printed_chars = -1;
        fmtstr_t fmtstr_types[] = {
                {'c', print_char}, {'s', print_string}, {'%', print_percent},
                {'i', print_int}, {'d', print_int}, {'b', print_binary},
                {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
                {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
                {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
        };
        for (i = 0; fmtstr_types[i].fmtstr != '\0'; i++)
                if (fmtstr[*index] == fmtstr_types[i].fmtstr)
                        return (fmtstr_types[i].fn(list, buffer, flags, width, preci, size));


        if (fmtstr_types[i].fmtstr == '\0')
        {
                if (fmtstr[*index] == '\0')
                        return (-1);
                unknow_len += write(1, "%%", 1);
                if (fmtstr[*index - 1] == ' ')
                        unknow_len += write(1, " ", 1);
                else if (width)
                {
                        --(*index);
                        while (fmtstr[*index] != ' ' && fmtstr[*index] != '%')
                                --(*index);
                        if (fmtstr[*index] == ' ')
                                --(*index);
                        return (1);
                }
                unknow_len += write(1, &fmtstr[*index], 1);
                return (unknow_len);
        }
        return (printed_chars);
}

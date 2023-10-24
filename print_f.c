#include "main.h"


void print_buffer(char buffer[], int *buff_index);


/**
 * printf_ - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int printf_(const char *format, ...)
{
        int a, printed = 0, printed_chars = 0;
        int flags, width, precision, size, buff_index = 0;
        va_list list;
        char buffer[BUFF_SIZE];


        if (format == NULL)
                return (-1);


        va_start(list, format);


        for (a = 0; format && format[a] != '\0'; a++)
        {
                if (format[a] != '%')
                {
                        buffer[buff_index++] = format[a];
                        if (buff_index == BUFF_SIZE)
                                print_buffer(buffer, &buff_index);
                        /* write(1, &format[a], 1);*/
                        printed_chars++;
                }
                else
                {
                        buffer_printer(buffer, &buff_index);
                        flags = attain_flags(format, &a);
                        width = attain_width(format, &a, list);
                        precision = attain_precision(format, &a, list);
                        size = attain_size(format, &a);
                        ++a;
                        printed = handle_print(format, &a, list, buffer,
                                flags, width, precision, size);
                        if (printed == -1)
                                return (-1);
                        printed_chars += printed;
                }
        }


        buffer_printer(buffer, &buff_index);


        va_end(list);


        return (printed_chars);
}


/**
 * buffer_printer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void buffer_printer(char buffer[], int *buff_index)
{
        if (*buff_index > 0)
                write(1, &buffer[0], *buff_index);


        *buff_index = 0;
}

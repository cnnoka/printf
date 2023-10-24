#include "main.h"


/**
 * attain_width - Calculates the width to be printed
 * @format: Formatted string in which to print the arguments.
 * @a: List of arguments to be printed.
 * @list_args: list of arguments.
 *
 * Return: width.
 */
int attain_width(const char *format, int *a, va_list list_args)
{
        int curr_a;
        int width = 0;


        for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
        {
                if (be_digit(format[curr_a]))
                {
                        width *= 10;
                        width += format[curr_a] - '0';
                }
                else if (format[curr_a] == '*')
                {
                        curr_a++;
                        width = va_arg(list_args, int);
                        break;
                }
                else
                        break;
        }


        *a = curr_a - 1;


        return (width);
}

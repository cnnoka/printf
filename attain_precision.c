#include "main.h"


/**
 * attain_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @a: List of arguments to be printed.
 * @list_args: list of arguments.
 *
 * Return: Precision.
 */
int attain_precision(const char *format, int *a, va_list list_args)
{
        int curr_a = *a + 1;
        int precision = -1;


        if (format[curr_a] != '.')
                return (precision);


        precision = 0;


        for (curr_a += 1; format[curr_a] != '\0'; curr_a++)
        {
                if (be_digit(format[curr_a]))
                {
                        precision *= 10;
                        precision += format[curr_a] - '0';
                }
                else if (format[curr_a] == '*')
                {
                        curr_a++;
                        precision = va_arg(list_args, int);
                        break;
                }
                else
                        break;
        }


        *a = curr_a - 1;


        return (precision);
}

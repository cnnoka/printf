#include "main.h"


/************************* PRINT CHAR *************************/


/**
 * char_printer - Prints a char
 * @typs: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int char_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        char c = va_arg(typs, int);


        return (write_handle_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * string_printer - Prints a string
 * @typs: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int string_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        int length = 0, a;
        char *str = va_arg(typs, char *);


        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);
        if (str == NULL)
        {
                str = "(null)";
                if (precision >= 6)
                        str = "      ";
        }


        while (str[length] != '\0')
                length++;


        if (precision >= 0 && precision < length)
                length = precision;


        if (width > length)
        {
                if (flags & F_MINUS)
                {
                        write(1, &str[0], length);
                        for (a = width - length; a > 0; a--)
                                write(1, " ", 1);
                        return (width);
                }
                else
                {
                        for (a = width - length; a > 0; a--)
                                write(1, " ", 1);
                        write(1, &str[0], length);
                        return (width);
                }
        }


        return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * percent_printer - Prints a percent sign
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attain width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int percent_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        UNUSED(typs);
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);
        return (write(1, "%%", 1));
}


/************************* PRINT INT *************************/
/**
 * int_printer - Print int
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attain width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int int_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        int a = BUFF_SIZE - 2;
        int be_negative = 0;
        long int n = va_arg(typs, long int);
        unsigned long int num;


        n = size_number_converter(n, size);


        if (n == 0)
                buffer[a--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)n;


        if (n < 0)
        {
                num = (unsigned long int)((-1) * n);
                be_negative = 1;
        }


        while (num > 0)
        {
                buffer[a--] = (num % 10) + '0';
                num /= 10;
        }


        a++;


        return (number_writing(be_negative, a, buffer, flags, width, precision, size));
}


/************************* PRINT BINARY *************************/
/**
 * binary_printer - Prints an unsigned number
 * @typs: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attains width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int binary_printer(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        unsigned int n, m, a, sum;
        unsigned int i[32];
        int count;


        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);


        n = va_arg(types, unsigned int);
        m = 2147483648; /* (2 ^ 31) */
        i[0] = n / m;
        for (a = 1; a < 32; a++)
        {
                m /= 2;
                i[a] = (n / m) % 2;
        }
        for (a = 0, sum = 0, count = 0; a < 32; a++)
        {
                sum += i[a];
                if (sum || a == 31)
                {
                        char z = '0' + i[a];


                        write(1, &z, 1);
                        count++;
                }
        }
        return (count);
}

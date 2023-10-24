#include "main.h"


/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * unsigned_printer - Prints an unsigned number
 * @typs: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attain width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int unsigned_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        int a = BUFF_SIZE - 2;
        unsigned long int num = va_arg(typs, unsigned long int);


        num = size_unsigned_converter(num, size);


        if (num == 0)
                buffer[a--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)
        {
                buffer[a--] = (num % 10) + '0';
                num /= 10;
        }


        a++;


        return (unsigned_writing(0, a, buffer, flags, width, precision, size));
}


/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * octal_printer - Prints an unsigned number in octal notation
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width:  attain width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int octal_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{


        int a = BUFF_SIZE - 2;
        unsigned long int num = va_arg(typs, unsigned long int);
        unsigned long int init_num = num;


        UNUSED(width);


        num = size_unsigned_converter(num, size);


        if (num == 0)
                buffer[a--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)
        {
                buffer[a--] = (num % 8) + '0';
                num /= 8;
        }


        if (flags & F_HASH && init_num != 0)
                buffer[a--] = '0';


        a++;


        return (unsigned_writing(0, a, buffer, flags, width, precision, size));
}


/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * hexadecimal_printer - Prints an unsigned number in hexadecimal notation
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexadecimal_printer(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return (hexa_print(types, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size));
}


/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * hexa_upper_printer - Prints an unsigned number in upper hexadecimal notation
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attain width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_upper_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        return (hexa_print(typs, "0123456789ABCDEF", buffer,
                flags, 'X', width, precision, size));
}


/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * hexa_print - Prints a hexadecimal number in lower or upper
 * @typs: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates all flags
 * @flag_ch: Calculates active flags
 * @width: calculate width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_print(va_list typs, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size)
{
        int a = BUFF_SIZE - 2;
        unsigned long int num = va_arg(typs, unsigned long int);
        unsigned long int init_num = num;


        UNUSED(width);


        num = size_unsgnd_converter(num, size);


        if (num == 0)
                buffer[a--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)
        {
                buffer[a--] = map_to[num % 16];
                num /= 16;
        }


        if (flags & F_HASH && init_num != 0)
        {
                buffer[a--] = flag_ch;
                buffer[a--] = '0';
        }


        a++;


        return (unsigned_writing(0, a, buffer, flags, width, precision, size));
}

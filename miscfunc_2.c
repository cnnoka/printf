#include "main.h"


/****************** POINTER PRINTER ******************/
/**
 * pointer_printer - Prints the value of a pointer variable
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates all  active flags
 * @width: attains width
 * @precision: specifies precision
 * @size: Specifies size
 * Return: Number of chars printed.
 */
int pointer_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        char extra_ch = 0, paddi = ' ';
        int index = BUFF_SIZE - 2, length = 2, paddi_start = 1; /* length=2, for '0x' */
        unsigned long num_addrs;
        char map_to[] = "0123456789abcdef";
        void *addrs = va_arg(typs, void *);


        UNUSED(width);
        UNUSED(size);


        if (addrs == NULL)
                return (write(1, "(nil)", 5));


        buffer[BUFF_SIZE - 1] = '\0';
        UNUSED(precision);


        num_addrs = (unsigned long)addrs;


        while (num_addrs > 0)
        {
                buffer[index--] = map_to[num_addrs % 16];
                num_addrs /= 16;
                length++;
        }


        if ((flags & F_ZERO) && !(flags & F_MINUS))
                paddi = '0';
        if (flags & F_PLUS)
                extra_ch = '+', length++;
        else if (flags & F_SPACE)
                extra_ch = ' ', length++;


        index++;


        /*return (write(1, &buffer[a], BUFF_SIZE - a - 1));*/
        return (pointer_writing(buffer, index, length,
                width, flags, padd, extra_ch, paddi_start));
}


/************************* PRINT NON PRINTABLE CHARS *************************/
/**
 * non_printable_chars - Prints ascii codes in hexa of non printable chars
 * @typs: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates all active flags
 * @width: attain  width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int non_printable_chars(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        int a = 0, offset = 0;
        char *str = va_arg(typs, char *);


        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);


        if (str == NULL)
                return (write(1, "(null)", 6));


        while (str[a] != '\0')
        {
                if (be_printable(str[a]))
                        buffer[a + offset] = str[a];
                else
                        offset += append_hexa_code(str[a], buffer, a + offset);


                a++;
        }


        buffer[a + offset] = '\0';


        return (write(1, buffer, a + offset));
}


/************************* PRINT IN  REVERSE *************************/
/**
 * reverse_printing - Prints string in reverse.
 * @typs: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */


int reverse_printing(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        char *str;
        int a, count = 0;


        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(size);


        str = va_arg(typs, char *);


        if (str == NULL)
        {
                UNUSED(precision);


                str = ")Null(";
        }
        for (i = 0; str[i]; i++)
                ;


        for (i = i - 1; i >= 0; i--)
        {
                char z = str[i];


                write(1, &z, 1);
                count++;
        }
        return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * rot13string_printer - Print a string in rot13.
 * @typs: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: attain width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int rot13string_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size)
{
        char x;
        char *str;
        unsigned int a, b;
        int count = 0;
        char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";


        str = va_arg(typs, char *);
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);


        if (str == NULL)
                str = "(AHYY)";
        for (a = 0; str[a]; a++)
        {
                for (b = 0; in[b]; b++)
                {
                        if (in[b] == str[a])
                        {
                                x = out[b];
                                write(1, &x, 1);
                                count++;
                                break;
                        }
                }
                if (!in[b])
                {
                        x = str[a];
                        write(1, &x, 1);
                        count++;
                }
        }
        return (count);
}

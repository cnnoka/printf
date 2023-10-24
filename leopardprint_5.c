#include "main.h"


/**
 * be_printable - verifies if a char is printable
 * @m: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int be_printable(char m)
{
        if (m >= 32 && m < 127)
                return (1);


        return (0);
}


/**
 * append_hexa - Append ascci in hexadecimal code to buffer
 * @chairs: Array of chars.
 * @a: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa(char ascii_code, char chairs[], int a)
{
        char map_to[] = "0123456789ABCDEF";
        /* The hexa format code is always 2 digits long */
        if (ascii_code < 0)
                ascii_code *= -1;


        chairs[a++] = '\\';
        chairs[a++] = 'x';


        chairs[a++] = map_to[ascii_code / 16];
        chairs[a] = map_to[ascii_code % 16];


        return (3);
}


/**
 * be_digit - Verifies if a char is a digit
 * @m: Char to be evaluated
 *
 * Return: 1 if m is a digit, 0 otherwise
 */
int be_digit(char m)
{
        if (m >= '0' && m <= '9')
                return (1);


        return (0);
}


/**
 * size_number_converter - converts a number to the specified size
 * @dig: Number to be converted.
 * @size: Number indicating the type to be converted.
 *
 * Return: Converted value of num
 */
long int size_number_converter(long int dig, int size)
{
        if (size == S_LONG)
                return (dig);
        else if (size == S_SHORT)
                return ((short)dig);


        return ((int)dig);
}


/**
 * size_unsigned_converter - Converts a number to the specified size
 * @dig: Number to be converted
 * @size: Number indicating the type to be converted
 *
 * Return: Converted  value of num
 */
long int size_unsigned_converter(unsigned long int dig, int size)
{
        if (size == S_LONG)
                return (dig);
        else if (size == S_SHORT)
                return ((unsigned short)dig);


        return ((unsigned int)dig);
}

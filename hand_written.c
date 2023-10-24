#include "main.h"


/************************* HANDLES WRITTEN *************************/
/**
 * write_handle_char - Prints a string
 * @ct: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Identifies and Calculates active flags.
 * @width: Calculates width.
 * @preci: specifies precision, if any
 * @size: Specifies size
 *
 * Return: Number of chars printed.
 */
int write_handle_char(char ct, char buffer[],
        int flag, int width, int preci, int size)
{ /* char is stored at left and paddind at buffer's right */
        int a = 0;
        char padd = ' ';


        UNUSED(preci);
        UNUSED(size);


        if (flag & F_ZERO)
                padd = '0';


        buffer[a++] = ct;
        buffer[a] = '\0';


        if (width > 1)
        {
                buffer[BUFF_SIZE - 1] = '\0';
                for (a = 0; a < width - 1; a++)
                        buffer[BUFF_SIZE - a - 2] = padd;


                if (flag & F_MINUS)
                        return (write(1, &buffer[0], 1) +
                                        write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
                else
                        return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
                                        write(1, &buffer[0], 1));
        }


        return (write(1, &buffer[0], 1));
}


/************************* WRITE NUMBER *************************/
/**
 * number_writing - Prints a string
 * @arguments: Lists of arguments
 * @cht: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculates width.
 * @preci: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int number_writing(int arguments, int cht, char buffer[],
        int flags, int width, int preci, int size)
{
        int length = BUFF_SIZE - cht - 1;
        char padd = ' ', extra_ch = 0;


        UNUSED(size);


        if ((flags & F_ZERO) && !(flags & F_MINUS))
                padd = '0';
        if (arguments)
                extra_ch = '-';
        else if (flags & F_PLUS)
                extra_ch = '+';
        else if (flags & F_SPACE)
                extra_ch = ' ';


        return (write_num(cht, buffer, flags, width, preci,
                length, padd, extra_ch));
}


/**
 * write_num - Write a number using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @preci: Specifies precision
 * @length: Number length
 * @paddi: represents Pading char
 * @extra_ch: represents extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int index, char buffer[],
        int flags, int width, int preci,
        int length, char paddi, char extra_ch)
{
        int a, paddi_start = 1;


        if (preci == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
                return (0); /* printf(".0d", 0)  no char is printed */
        if (preci == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
                buffer[index] = paddi = ' '; /* width is displayed with padding ' ' */
        if (preci > 0 && preci < length)
                paddi = ' ';
        while (preci > length)
                buffer[--index] = '0', length++;
        if (extra_c != 0)
                length++;
        if (width > length)
        {
                for (a = 1; a < width - length + 1; a++)
                        buffer[a] = paddi;
                buffer[a] = '\0';
                if (flags & F_MINUS && paddi == ' ')/* Asign extra char to left of buffer */
                {
                        if (extra_ch)
                                buffer[--index] = extra_ch;
                        return (write(1, &buffer[index], length) + write(1, &buffer[1], a - 1));
                }
                else if (!(flags & F_MINUS) && paddi == ' ')/* extra char to left of buff */
                {
                        if (extra_ch)
                                buffer[--index] = extra_ch;
                        return (write(1, &buffer[1], a - 1) + write(1, &buffer[index], length));
                }
                else if (!(flags & F_MINUS) && paddi == '0')/* extra char to left of padd */
                {
                        if (extra_ch)
                                buffer[--paddi_start] = extra_ch;
                        return (write(1, &buffer[paddi_start], a - paddi_start) +
                                write(1, &buffer[index], length - (1 - paddi_start)));
                }
        }
        if (extra_ch)
                buffer[--index] = extra_ch;
        return (write(1, &buffer[index], length));
}


/**
 * unsigned_writing - Writes an unsigned number
 * @are_negative: indicates if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Calculates width
 * @preci: Specifies Precision
 * @size: Specifies Size
 *
 * Return: Number of written chars.
 */
int unsigned_writing(int are_negative, int index,
        char buffer[],
        int flags, int width, int preci, int size)
{
        /* The number is stored at the buffer's right and starts at position i */
        int length = BUFF_SIZE - ind - 1, i = 0;
        char paddi = ' ';


        UNUSED(are_negative);
        UNUSED(size);


        if (preci == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
                return (0); /* printf(".0d", 0)  no char is printed */


        if (preci > 0 && preci < length)
                paddi = ' ';


        while (preci > length)
        {
                buffer[--index] = '0';
                length++;
        }


        if ((flags & F_ZERO) && !(flags & F_MINUS))
                paddi = '0';


        if (width > length)
        {
                for (i = 0; i < width - length; i++)
                        buffer[i] = paddi;


                buffer[i] = '\0';


                if (flags & F_MINUS) /* Assign extra char to left of buffer [buffer>padd]*/
                {
                        return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
                }
                else /* Assign extra char to left of padding [padd>buffer]*/
                {
                        return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
                }
        }


        return (write(1, &buffer[index], length));
}


/**
 * pointer_writing - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Specifies the width
 * @flags: Identifies and specifies flags
 * @paddi: Char representing the padding
 * @extra_ch: Char representing extra char
 * @paddi_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int pointer_writing(char buffer[], int index, int length,
        int width, int flags, char paddi, char extra_ch, int paddi_start)
{
        int a;


        if (width > length)
        {
                for (a = 3; a < width - length + 3; a++)
                        buffer[a] = paddi;
                buffer[a] = '\0';
                if (flags & F_MINUS && paddi == ' ')/* Assign extra char to left of buffer */
                {
                        buffer[--index] = 'x';
                        buffer[--index] = '0';
                        if (extra_ch)
                                buffer[--index] = extra_ch;
                        return (write(1, &buffer[index], length) + write(1, &buffer[3], a - 3));
                }
                else if (!(flags & F_MINUS) && paddi == ' ')/* extra char to left of buffer */
                {
                        buffer[--index] = 'x';
                        buffer[--index] = '0';
                        if (extra_ch)
                                buffer[--index] = extra_ch;
                        return (write(1, &buffer[3], a - 3) + write(1, &buffer[index], length));
                }
                else if (!(flags & F_MINUS) && paddi == '0')/* extra char to left of padd */
                {
                        if (extra_ch)
                                buffer[--paddi_start] = extra_ch;
                        buffer[1] = '0';
                        buffer[2] = 'x';
                        return (write(1, &buffer[paddi_start], a - paddi_start) +
                                write(1, &buffer[index], length - (1 - paddi_start) - 2));
                }
        }
        buffer[--index] = 'x';
        buffer[--index] = '0';
        if (extra_ch)
                buffer[--index] = extra_ch;
        return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

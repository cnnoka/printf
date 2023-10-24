#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


/* SIZES */
#define S_LONG 2
#define S_SHORT 1


/**
 * struct fmtstr - Struct op
 *
 * @fmtstr The format.
 * @fn: The function associated.
 */
struct fmtstr
{
        char fmtstr;
        int (*fn)(va_list, char[], int, int, int, int);
};




/**
 * typedef struct fmtstr fmtstr_t - Struct op
 *
 * @fmtstr: The format.
 * @fmtstr_t: The function associated.
 */
typedef struct fmtstr fmtstr_t;


int printf_(const char *format, ...);
int print_handler(const char *fmtstr, int *i,
va_list list, char buffer[], int flags, int width, int preci, int size);


/****************** FUNCTIONS ******************/


/* Funtions to print chars and strings */
int char_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int string_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int percent_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


/* Functions to print numbers */
int int_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int binary_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int unsigned_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int octal_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int hexadecimal_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);
int hexa_upper_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


int hexa_print(va_list typs, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Function to print non printable characters */
int non_printable_chars(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


/* Funcion to print memory address */
int pointer_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


/* Funciotns to handle other specifiers */
int attain_flags(const char *format, int *a);
int attain_width(const char *format, int *a, va_list list_args);
int attain_precision(const char *format, int *a, va_list list_args);
int attain_size(const char *format, int *a);


/*Function to print string in reverse*/
int reverse_printing(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


/*Function to print a string in rot 13*/
int rot13string_printer(va_list typs, char buffer[],
        int flags, int width, int precision, int size);


/* width handler */
int write_handle_char(char ct, char buffer[],
        int flags, int width, int preci, int size);
int number_writing(int arguments, int cht, char buffer[],
        int flags, int width, int preci, int size);
int write_num(int index, char bff[], int flags, int width, int preci,
        int length, char paddi, char extra_ch);
int pointer_writing(char buffer[], int index, int length,
        int width, int flags, char paddi, char extra_ch, int paddi_start);


int unsigned_writing(int are_negative, int index,
char buffer[],
        int flags, int width, int preci, int size);


/******************Leopard print  ******************/
int be_printable(char);
int append_hexa(char, char[], int);
int be_digit(char);


long int size_number_converter(long int num, int size);
long int size_unsigned_converter(unsigned long int num, int size);


#endif /* MAIN_H */

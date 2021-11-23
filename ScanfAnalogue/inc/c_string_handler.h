#pragma once
#ifndef SCANFANALOGUE_C_STRING_HANDLER_H
#define SCANFANALOGUE_C_STRING_HANDLER_H

#include <cstdio>
#include <cstdlib>

constexpr auto ERR_WRITE             = "There was an error writing to standard out\n";
constexpr auto ERR_CONVERSION        = "There was a string conversion error\n";
constexpr auto ERR_WRITE_LENGTH      = get_string_length(ERR_WRITE);
constexpr auto ERR_CONVERSION_LENGTH = get_string_length(ERR_CONVERSION);

/**
 * The reason for using UNSIGNED CHAR instead
 * of UNSIGNED INT or UNSIGNED SHORT is the minimum
 * memory required for each character.
 *
 * CHAR  takes  8  bits (of memory for a character),
 * SHORT -      16 bits,
 * INT   -      32 bits (minimum)
 *
 * There is MAX LENGTH of STRING_T is 255 characters
 * It can be increased by changing UNSIGNED CHAR to a
 * different UNSIGNED 'type'
 */

typedef struct string_structure
{
             char * string_data;
    unsigned char   string_length;
    unsigned char   takes_memory;
} string_t;


string_t * create_string_t(unsigned char length)              // CONSTRUCTOR
{
    if(length == 0)
    {
        return nullptr;
    }
    else
    {
        string_t * string[sizeof(string_t)];

        string -> string_data   = char data[length];
        string -> string_length = length;
        string -> takes_memory  = 0;
    }

    return string;
}

string_t * create_string_t(const char * copy_string)        // COPY CONSTRUCTOR
{
    if(get_string_length(copy_string) == 0)
    {
        return nullptr;
    }
    else
    {
        string_t * new_string =
            create_string(
                get_string_length(
                    copy_string
                )
            );

        memcpy(
            new_string -> data,                             // buffer
            copy_string,                                    // data
            new_string -> length                            // length
        );

        new_string -> takes_memory = new_string -> length;

        return new_string;
    }
}

string_t * create_string_t(const char ** move_string)         // MOVE CONSTRUCTOR
{
    if(get_string_length(move_string) != 0)
    {
        string_t * new_string = * move_string;
// TODO: transmit a pointer
//        delete [] move_string;

        return new_string;
    }

    return nullptr;
}

string_t * convert_string_to_string_t(const char * string)
{
    unsigned int string_len = get_string_length(string);

    if (string_len != 0)
    {
        string_t * converted_string[string_len];

        converted_string -> string_data   = char data[string_len];
        converted_string -> string_length = string_len;
        converted_string -> takes_memory  = 0;

        return converted_string;
    }

    write(STDERR_FILENO, ERR_CONVERSION, ERR_CONVERSION_LENGTH);

    return nullptr;
}

unsigned int get_string_length(char * string)
{
    unsigned int length = 0;

    while ( *(string + length) != '\0')
    {
        length++;
    }

    return length;
}

unsigned char get_string_t_length(string_t * string)
{
    return string == nullptr ? 0 : string -> string_length;
}

unsigned char get_string_t_data(string_t * string)
{
    return string == nullptr ? nullptr : string -> data;
}


int print_string(const char * string)
{
    unsigned int string_len = get_string_length(string);

    if (string_len == 0)
    {
        write(STDERR_FILENO, ERR_WRITE, ERR_WRITE_LENGTH);
        return -1;
    }

    return
        write(
            STDOUT_FILENO,
            str,
            string_len
        )
}


int print_string_t(string_t * string)
{
    if (       string                      == nullptr
            || get_string_t_length(string) == nullptr
            || get_string_t_data(string)   == nullptr
        )
    {
        write(STDERR_FILENO, ERR_WRITE, ERR_WRITE_LENGTH);
        return -1;
    }

    return
        write(
            STDOUT_FILENO,
            get_string_t_data(string),
            get_string_t_length(string)
        )
}

#endif //SCANFANALOGUE_C_STRING_HANDLER_H

#pragma once
#ifndef C_STRING_HANDLER_H
#define C_STRING_HANDLER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

constexpr auto ERR_WRITE             = "There was an error writing to standard out\n";
constexpr auto ERR_CONVERSION        = "There was a string conversion error\n";
constexpr auto ERR_WRITE_LENGTH      = 44;
constexpr auto ERR_CONVERSION_LENGTH = 37;

/**
 * The reason for using UNSIGNED CHAR instead
 * of UNSIGNED INT or UNSIGNED SHORT is the minimum
 * memory required for each character.
 *
 * CHAR  takes  8  bits (of memory for a character),
 * SHORT -      16 bits,
 * INT   -      32 bits (minimum)
 *
 * There is MAX LENGTH of STRING_T is 1024 characters
 * It can be increased by changing UNSIGNED CHAR to a
 * different UNSIGNED 'type'
 */

typedef struct String_structure
{
             char * string_data;
    unsigned char   string_length;
    unsigned char   takes_memory;
} String_t;

unsigned int get_string_length(const char * string);

// CONSTRUCTORS
String_t *   create_string_t(unsigned int    length);       // CONSTRUCTOR
String_t *   create_string_t(const    char * copy_string);  // COPY CONSTRUCTOR

// DESTRUCTOR
void clean_memory(String_t * string);

String_t * convert_string_to_string_t(const char * string);

unsigned char   get_string_t_length(String_t * string);
const    char * get_string_t_data  (String_t * string);

// PRINTERS
int print_string  (const char * string);
int print_string_t(String_t   * string);

#endif // C_STRING_HANDLER_H

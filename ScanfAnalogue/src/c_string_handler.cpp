#include "c_string_handler.h"

unsigned int get_string_length(const char * string)
{
    unsigned int length = 0;

    while ( *(string + length) != '\0')
    {
        length++;
    }

    return length;
}

String_t * create_string_t(unsigned int length)              // CONSTRUCTOR
{
    if(length == 0)
    {
        return nullptr;
    }
    else
    {
        auto * string           = (String_t *) malloc(sizeof (String_t));

        string -> string_data   = (char *) malloc(sizeof (length));
        string -> string_length = length;
        string -> takes_memory  = 0;

        return string;
    }
}

String_t * create_string_t(const char * copy_string)        // COPY CONSTRUCTOR
{
    if(get_string_length(copy_string) == 0)
    {
        return nullptr;
    }
    else
    {
        String_t * new_string =
            create_string_t(
                get_string_length(
                    copy_string
                )
            );

        memcpy(
            new_string -> string_data,                      // buffer
            copy_string,                                    // data
            new_string -> string_length                     // length
        );

        new_string -> takes_memory = new_string -> string_length;

        return new_string;
    }
}

String_t * convert_string_to_string_t(const char * string)
{
    unsigned int string_len = get_string_length(string);

    if (string_len != 0)
    {
        return create_string_t(string);
    }

    write(STDERR_FILENO, ERR_CONVERSION, ERR_CONVERSION_LENGTH);

    return nullptr;
}

void clean_memory(String_t * string)
{
    free(string -> string_data);
    free(string);
}

unsigned char get_string_t_length(String_t * string)
{
    return string == nullptr ? 0 : string -> string_length;
}

const char * get_string_t_data(String_t * string)
{
    return string -> string_data;
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
            string,
            string_len
        );
}


int print_string_t(String_t * string)
{
    if (       string                     == nullptr
           || get_string_t_length(string) == 0
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
        );
}

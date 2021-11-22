#pragma once

#ifndef MAIN_H
#define MAIN_H

#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif

#include <unistd.h>
#include <cstdlib>

const int STDOUT_FILENO = 1;

constexpr auto word = "Hello, world!\n";

#ifndef USE_GET_LENGTH_FUNCTION

    int print(const char * str, int length)
    {
        return write(STDOUT_FILENO, str, length);
    }

#else

    int getStringLength(const char * string)
    {
        int counter = 0;

        while (string[counter] != '\0')
        {
            counter++;
        }

        return counter;
    }

    int print(const char * str)
    {
        return write(STDOUT_FILENO, str, getStringLength(str));
    }

#endif

int scan()
{
    char character;

    puts("Введите символ, символ точки - выход('.'):");
    do
    {
        character = getchar();
        putchar (character);   // вывести этот символ
    } while (character != '\0');
    return 0;

    auto ch = getchar();
    int sign = 0;
    int number = 0;




    while (ch >= '0' && ch <= '9' || !sign)
    {
        if (!sign)
        {
            sign = ch == '-' ? -1 : 1;
            if (ch != '-')
            {
                number = number * 10 + sign * (ch - '0');
            }
        } else
        {
            number = number * 10 + sign * (ch - '0');
        }
        ch = getchar_unlocked();
    }
    return number;
}

#endif // MAIN_H
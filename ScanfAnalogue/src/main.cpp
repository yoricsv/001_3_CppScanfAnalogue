#include "main.h"

//    print(5325);
//    int input = {0};
//    int is_true = 1;
//
//    while (!is_true)
//    {
//        puts(word);
//        scanf("%d", &input);
//
//        if(input < 0 || input > 99)
//        {
//
//            printf(answer);
//            print(input);
//
//            is_true = 0;
//        }
//        else
//        {
//            printf(err);
//        }
//    }
//
//    std::default_random_engine engine{0};
//    std::uniform_int_distribution<int> uniform_dist(0, input);
//
//    printf("%d", uniform_dist(engine));
//
//    int scan_string()
//    {
//        char character;
//
//        puts("Enter your number: ");
//        do
//        {
//            character = getchar();
//            putchar (character);
//        } while (character != '\0');
//        return 0;
//
//    auto ch = getchar();
//    int sign = 0;
//    int number = 0;
//    }




int main(int argc, char * argv[])
{
    int exit_code = print_string(word);

    return
           exit_code == -1
        || exit_code != get_string_length(word) ?
                EXIT_FAILURE : EXIT_SUCCESS;
}


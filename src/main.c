/*
** EPITECH PROJECT, 2022
** 103 cipher
** File description:
** 103 cipher
*/

#include "../my.h"

int main(int ac, char **av)
{
    fct_struct_t fstruct;
    if (ac == 1)
        return 84;
    print_help(av[1]);
    extra_messages(av[1], av[2], av[3], ac);
    if (av[3][0] == '0') {
        key_to_matrice(av[2], &fstruct);
        message_to_matrice(av[1], &fstruct);
        encryption(&fstruct);
    }
    if (av[3][0] == '1') {
        key_to_matrice_decryption(av[2], &fstruct);
        determinant(&fstruct);
        key_matrix_invert(&fstruct);
        str_to_word_array(&fstruct, av[1]);
        decryption(&fstruct);
    }
    ac++;
    return 0;
}

void print_help(char *av)
{
    if (strcmp(av, "-h") == 0) {
        printf("%s", "USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\tmessage\t\ta message, made of ASCII characters\n\tkey\t\tthe encrypton key, made of ASCII characters\n\tflag\t\t0 for the message to be encrypted, 1 to be decrypted\n");
        exit(0);
    }
    return;
}

int extra_messages(char* arg1, char* arg2, char* arg3, int numberarg)
{
    if (numberarg != 4 || strlen(arg1) == 0 || strlen(arg2) == 0 || strlen(arg3) == 0 || strlen(arg2) > 25) {
        printf("%s", "USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\tmessage\t\ta message, made of ASCII characters\n\tkey\t\tthe encrypton key, made of ASCII characters\n\tflag\t\t0 for the message to be encrypted, 1 to be decrypted\n");
        exit (84);
    }
    if (strcmp(arg3, "0") != 0 && strcmp(arg3, "1") != 0) {
        printf("%s", "USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\tmessage\t\ta message, made of ASCII characters\n\tkey\t\tthe encrypton key, made of ASCII characters\n\tflag\t\t0 for the message to be encrypted, 1 to be decrypted\n");
        exit(84);
    }
    print_help(arg1);
    return 0;
}

int my_getnbr(char *input)
{
    int i = 0;
    int output = 0;
    int negative = 0;

    if (input[0] == '-') {
        i++;
        negative = 1;
    }
    while (input[i] != '\0') {
        output = ((output * 10) + (input[i] - 48));
        i++;
    }
    if (negative == 1)
        output = -output;
    return (output);
}
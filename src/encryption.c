/*
** EPITECH PROJECT, 2022
** 103 cipher
** File description:
** 103 cipher
*/

#include "../my.h"

void key_to_matrice(char *string, fct_struct_t *fstruct)
{
    int **matrice;
    int len = strlen(string);
    int str_index = 0;

    if (len <= 25) {
        fstruct->key_matrice_dim = 5;
    }
    if (len <= 16) {
        fstruct->key_matrice_dim = 4;
    }
    if (len <= 9) {
        fstruct->key_matrice_dim = 3;
    }
    if (len <= 4) {
        fstruct->key_matrice_dim = 2;
    }
    if (len == 1) {
        fstruct->key_matrice_dim = 1;
    }
    matrice = malloc(sizeof(int*) * fstruct->key_matrice_dim + 1);
    if (matrice == NULL)
        exit(84);
    for (int i = 0; i < fstruct->key_matrice_dim; i++) {
        matrice[i] = malloc(sizeof(int) * fstruct->key_matrice_dim + 1);
        for (int j = 0; j < fstruct->key_matrice_dim; j++) {
            if (str_index < len) {
                matrice[i][j] = (int)string[str_index];
                str_index++;
            } else {
                matrice[i][j] = 0;
            }
            if (j == 5)
                j = 0;
        }
    }
    printf("Key matrix:\n");
    for (int i = 0; i < fstruct->key_matrice_dim; i++) {
        for (int j = 0; j < fstruct->key_matrice_dim; j++) {
            printf("%i", matrice[i][j]);
            if (j < fstruct->key_matrice_dim - 1)
                putchar('\t');
        }
        putchar('\n');
    }
    fstruct->matrice_key = matrice;
}

void message_to_matrice(char *string, fct_struct_t *fstruct)
{
    int **matrice;
    int len = strlen(string);
    int str_index = 0;
    int nb_lines = len / fstruct->key_matrice_dim;

    if (nb_lines % fstruct->key_matrice_dim != 0)
        nb_lines++;
    matrice = malloc(sizeof(int*) * nb_lines + 1);
    for (int i = 0; i < nb_lines; i++) {
        matrice[i] = malloc(sizeof(int) * fstruct->key_matrice_dim + 1);
        for (int j = 0; j < fstruct->key_matrice_dim; j++) {
            if (str_index < len) {
                matrice[i][j] = (int)string[str_index];
                str_index++;
            } else {
                matrice[i][j] = 0;
            }
            if (j == 5)
                j = 0;
        }
    }
    fstruct->matrice_message = matrice;
    fstruct->nb_line_msg_matrix = nb_lines;
}

void encryption(fct_struct_t *fstruct)
{
    int **encrypted_message;
    int i = 0;
    int j = 0;
    int k = 0;
    
    encrypted_message = malloc(sizeof(int*) * fstruct->nb_line_msg_matrix + 1);
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        encrypted_message[i] = malloc(sizeof(int) * fstruct->key_matrice_dim + 1);
    }
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        for (j = 0; j < fstruct->key_matrice_dim; j++) {
            for (k = 0; k < fstruct->key_matrice_dim; k++) {
                encrypted_message[i][j] = encrypted_message[i][j] + (fstruct->matrice_message[i][k] * fstruct->matrice_key[k][j]);
            }
        }
    }
    fstruct->encrypted_message = encrypted_message;
    printf("\nEncrypted message:\n");
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        for (j = 0; j < fstruct->key_matrice_dim; j++) {
            printf("%i", encrypted_message[i][j]);
            if (j < fstruct->key_matrice_dim - 1)
                putchar(' ');
        }
        if (i < fstruct->nb_line_msg_matrix - 1)
                putchar(' ');
    }
    putchar('\n');
}

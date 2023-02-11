/*
** EPITECH PROJECT, 2022
** 103 cipher
** File description:
** 103 cipher
*/

#include "../my.h"

void determinant(fct_struct_t *fstruct)
{
    float determinant = 0;

    if (fstruct->key_matrice_dim == 2) {
        determinant = (fstruct->matrice_key_decrypt[0][0] * fstruct->matrice_key_decrypt[1][1]) - (fstruct->matrice_key_decrypt[1][0] * fstruct->matrice_key_decrypt[0][1]);
    }
    if (fstruct->key_matrice_dim == 3) {
        determinant = fstruct->matrice_key_decrypt[0][0]*((fstruct->matrice_key_decrypt[1][1] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[1][2] * fstruct->matrice_key_decrypt[2][1])) -
                        fstruct->matrice_key_decrypt[0][1]*((fstruct->matrice_key_decrypt[1][0] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[1][2] * fstruct->matrice_key_decrypt[2][0])) +
                        fstruct->matrice_key_decrypt[0][2]*((fstruct->matrice_key_decrypt[1][0] * fstruct->matrice_key_decrypt[2][1]) - (fstruct->matrice_key_decrypt[1][1] * fstruct->matrice_key_decrypt[2][0]));
    }
    if (determinant == 0)
        exit(84);
    fstruct->determinant = determinant;
}

void key_matrix_invert(fct_struct_t *fstruct)
{   
    float **matrice = malloc(sizeof(int*) * fstruct->key_matrice_dim);
    for (int i = 0; i < fstruct->key_matrice_dim; i++) {
        matrice[i] = malloc(sizeof(int) * fstruct->key_matrice_dim);
    }

    if (fstruct->key_matrice_dim == 2) {
        matrice[0][0] = (fstruct->matrice_key_decrypt[1][1]/fstruct->determinant);
        matrice[0][1] = (fstruct->matrice_key_decrypt[0][1]/fstruct->determinant) * -1;
        matrice[1][0] = (fstruct->matrice_key_decrypt[1][0]/fstruct->determinant) * -1;
        matrice[1][1] = (fstruct->matrice_key_decrypt[0][0]/fstruct->determinant);
    }

    if (fstruct->key_matrice_dim == 3) {
        matrice[0][0] = ((fstruct->matrice_key_decrypt[1][1] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[1][2] * fstruct->matrice_key_decrypt[2][1])) /fstruct->determinant;
        matrice[0][1] = ((fstruct->matrice_key_decrypt[0][1] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[0][2] * fstruct->matrice_key_decrypt[2][1])) /fstruct->determinant * -1;
        matrice[0][2] = ((fstruct->matrice_key_decrypt[0][1] * fstruct->matrice_key_decrypt[1][2]) - (fstruct->matrice_key_decrypt[0][2] * fstruct->matrice_key_decrypt[1][1])) /fstruct->determinant;

        matrice[1][0] = ((fstruct->matrice_key_decrypt[1][0] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[1][2] * fstruct->matrice_key_decrypt[2][0])) /fstruct->determinant * -1;
        matrice[1][1] = ((fstruct->matrice_key_decrypt[0][0] * fstruct->matrice_key_decrypt[2][2]) - (fstruct->matrice_key_decrypt[0][2] * fstruct->matrice_key_decrypt[2][0])) /fstruct->determinant;
        matrice[1][2] = ((fstruct->matrice_key_decrypt[0][0] * fstruct->matrice_key_decrypt[1][2]) - (fstruct->matrice_key_decrypt[0][2] * fstruct->matrice_key_decrypt[1][0])) /fstruct->determinant * -1;

        matrice[2][0] = ((fstruct->matrice_key_decrypt[1][0] * fstruct->matrice_key_decrypt[2][1]) - (fstruct->matrice_key_decrypt[1][1] * fstruct->matrice_key_decrypt[2][0])) /fstruct->determinant;
        matrice[2][1] = ((fstruct->matrice_key_decrypt[0][0] * fstruct->matrice_key_decrypt[2][1]) - (fstruct->matrice_key_decrypt[0][1] * fstruct->matrice_key_decrypt[2][0])) /fstruct->determinant * -1;
        matrice[2][2] = ((fstruct->matrice_key_decrypt[0][0] * fstruct->matrice_key_decrypt[1][1]) - (fstruct->matrice_key_decrypt[0][1] * fstruct->matrice_key_decrypt[1][0])) /fstruct->determinant;

    }
    fstruct->matrice_key_decrypt = matrice;
    printf("Key matrix:\n");
    for (int i = 0; i < fstruct->key_matrice_dim; i++) {
        for (int j = 0; j < fstruct->key_matrice_dim; j++) {
            if (matrice[i][j] / 2 == 0)
                printf("%.1f", 0.0);
            else
                printf("%.3f", matrice[i][j]);
            if (j < fstruct->key_matrice_dim - 1)
                putchar('\t');
        }
        putchar('\n');
    }
}

void key_to_matrice_decryption(char *string, fct_struct_t *fstruct)
{
    float **matrice;
    int len = strlen(string);
    int str_index = 0;

    if (len > 9) {
        exit(84);
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
    fstruct->matrice_key_decrypt = matrice;
}

void str_to_word_array(fct_struct_t *fstruct, char *list_input)
{
    int count_nbr = 1;
    int index = 0;
    int index_case = 0;
    char **list;

    while (list_input[index] != '\0') {
        if (list_input[index] == ' ') {
            count_nbr++;
            index++;
        } else {
            index++;
        }
    }
    list = malloc(sizeof(char*) * count_nbr + 1);
    fstruct->count_nbr = count_nbr;
    index = 0;
    while (index < (int)strlen(list_input)) {
        list[index_case] = malloc(sizeof(char) * 10);
        for (int i = 0; list_input[index] != ' ' && list_input[index] != '\0'; i++) {
            list[index_case][i] = list_input[index];
            index++;
        }
        index_case++;
        index++;
    }
    number_to_matrice(list, count_nbr, fstruct);
}

void number_to_matrice(char **list, int nb_number, fct_struct_t *fstruct)
{
    int **matrice;
    int len = nb_number;
    int str_index = 0;
    int nb_lines = len / fstruct->key_matrice_dim;

    if (nb_lines % fstruct->key_matrice_dim != 0)
        nb_lines++;
    matrice = malloc(sizeof(int*) * nb_lines + 1);
    for (int i = 0; i < nb_lines; i++) {
        matrice[i] = malloc(sizeof(int) * fstruct->key_matrice_dim + 1);
        for (int j = 0; j < fstruct->key_matrice_dim; j++) {
            if (str_index < len) {
                matrice[i][j] = my_getnbr(list[str_index]);
                str_index++;
            } else {
                matrice[i][j] = 0;
            }
            if (j == 5)
                j = 0;
        }
    }
    fstruct->nb_line_msg_matrix = nb_lines;
    fstruct->matrice_message = matrice;
}

void decryption(fct_struct_t *fstruct)
{
    int **decrypted_message;
    int i = 0;
    int j = 0;
    int k = 0;
    
    decrypted_message = malloc(sizeof(int*) * fstruct->nb_line_msg_matrix + 1);
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        decrypted_message[i] = malloc(sizeof(int) * fstruct->key_matrice_dim + 1);
    }
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        for (j = 0; j < fstruct->key_matrice_dim; j++) {
            for (k = 0; k < fstruct->key_matrice_dim; k++) {
                decrypted_message[i][j] = decrypted_message[i][j] + (fstruct->matrice_message[i][k] * fstruct->matrice_key_decrypt[k][j]);
            }
        }
    }
    fstruct->decrypted_message = decrypted_message;
    printf("\nDecrypted message:\n");
    for (i = 0; i < fstruct->nb_line_msg_matrix; i++) {
        for (j = 0; j < fstruct->key_matrice_dim; j++) {
            printf("%c", decrypted_message[i][j]);
        }
    }
    putchar('\n');
}
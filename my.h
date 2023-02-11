/*
** EPITECH PROJECT, 2022
** myls
** File description:
** my header
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MY_H_
    #define MY_H_
    typedef struct fct_struct {
        char *message;
        char *key;
        int **matrice_message;
        int **encrypted_message;
        int **decrypted_message;
        int **matrice_key;
        float **matrice_key_decrypt;
        int key_matrice_dim;
        int nb_line_msg_matrix;
        float determinant;
        int count_nbr;
    }fct_struct_t;

    void print_help(char *av);
    void key_to_matrice(char *string, fct_struct_t *fstruct);
    void message_to_matrice(char *string, fct_struct_t *fstruct);
    void encryption(fct_struct_t *fstruct);
    int extra_messages(char* arg1, char* arg2, char* arg3, int numberarg);
    void key_to_matrice_decryption(char *string, fct_struct_t *fstruct);
    void determinant(fct_struct_t *fstruct);
    void key_matrix_invert(fct_struct_t *fstruct);
    void str_to_word_array(fct_struct_t *fstruct, char *list_input);
    void number_to_matrice(char **list, int nb_number, fct_struct_t *fstruct);
    void decryption(fct_struct_t *fstruct);
    int my_getnbr(char *input);
#endif /* !MY_H_ */

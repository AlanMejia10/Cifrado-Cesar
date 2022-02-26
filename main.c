/*
    * Mejia Espinosa Ruben Alan
    * Seguridad computacional
    * 2801
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHRASE_SIZE 50

void menu();
int encrypt(char* phrase, char* encrypt_phrase, int displacement);
int decrypt(char* phrase, char* decrypt_phrase, int displacement);

int main(){
    int opc_menu, displacement;
    char phrase[PHRASE_SIZE] = {}, encrypt_phrase[PHRASE_SIZE] = {}, decrypt_phrase[PHRASE_SIZE] = {};

    printf("Algoritmo de encriptacion\n");
    menu();
    printf("Selecciona una opcion: ");
    scanf("%i", &opc_menu);
    fflush(stdin);
    printf("Ingresa la frase (solo minusculas): ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = 0; // removes the trailing \n and replaces it with \0
    printf("Ingresa el desplazamiento: ");
    scanf("%i", &displacement);

    switch(opc_menu){
        case 1:
            if(encrypt(phrase, encrypt_phrase, displacement) > 0)
                printf("Frase encriptada exitosamente: %s\n", encrypt_phrase);
            else
                printf("La frase no se pudo encriptar, caracteres invalidos\n");
            break;
        case 2:
            if(decrypt(phrase, decrypt_phrase, displacement) > 0)
                printf("Frase desencriptada exitosamente: %s\n", decrypt_phrase);
            else
                printf("La frase no se pudo desencriptar, caracteres invalidos\n");
            break;
        default:
            printf("Opcion incorrecta");
    }

    return 0;
}

void menu(){
    printf("Menu\n");
    printf("1. Encriptar\n");
    printf("2. Desencriptar\n");
}

int encrypt(char* phrase, char* encrypt_phrase, int displacement){
    int letter;
    int initial_letter = 97, last_letter = 122;
    for(int i = 0; i < PHRASE_SIZE; i++){
        letter = (int)(phrase[i]);

        if(phrase[i] == ' '){
            encrypt_phrase[i] = ' ';
            continue;
        }

        if(phrase[i] == '\0'){
            encrypt_phrase[i] = '\0'; // sets the buffer to a null terminated character to prevent garbage characters
            return 1;
        }

        if(letter < initial_letter || letter > last_letter)
            return -1;

        int new_letter = letter + displacement;
        if(new_letter > last_letter)
            new_letter = new_letter - last_letter + initial_letter - 1;
        encrypt_phrase[i] = (char) new_letter;
    }
    return 1;
}

int decrypt(char* phrase, char* decrypt_phrase, int displacement){
    int letter;
    int initial_letter = 97, last_letter = 122;
    for(int i = 0; i < PHRASE_SIZE; i++){
        letter = (int)(phrase[i]);

        if(phrase[i] == ' '){
            decrypt_phrase[i] = ' ';
            continue;
        }

        if(phrase[i] == '\0'){
            decrypt_phrase[i] = '\0'; // sets the buffer to a null terminated character
            return 1;
        }

        if(letter < initial_letter || letter > last_letter)
            return -1;

        int new_letter = letter - displacement;
        if(new_letter < initial_letter)
            new_letter = last_letter + 1 - (initial_letter - new_letter);
        decrypt_phrase[i] = (char) new_letter;
    }
    return 1;
}

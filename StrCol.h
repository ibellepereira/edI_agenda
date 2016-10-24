#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE_STR 50

typedef struct _strcol{
    char* str;
    int cont;
} StrCol;

//void manageString(StrCol)
void strcolSet(StrCol* Col);//configuração inicial da coleção
void insertString(StrCol *str, char* string); //insere string na última posição
char* String(void); //lê a string inserida pelo usuário e retorna
char* stringLabeled(char* label); //mesma função String(), mas imprime uma label antes
char* returnString(StrCol *String, int pos); //retorna a string na posição
void printString(StrCol *str, int pos); //printa conteúdo de dentro da string;
void deleteString(StrCol *String, int pos); //deleta e rearruma a string


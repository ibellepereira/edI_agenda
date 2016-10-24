#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE_STR 50

typedef struct _strcol{
    char* str;
    int cont;
} StrCol;

//void manageString(StrCol)
void strcolSet(StrCol* Col);//configura��o inicial da cole��o
void insertString(StrCol *str, char* string); //insere string na �ltima posi��o
char* String(void); //l� a string inserida pelo usu�rio e retorna
char* stringLabeled(char* label); //mesma fun��o String(), mas imprime uma label antes
char* returnString(StrCol *String, int pos); //retorna a string na posi��o
void printString(StrCol *str, int pos); //printa conte�do de dentro da string;
void deleteString(StrCol *String, int pos); //deleta e rearruma a string


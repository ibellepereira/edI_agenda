#include "StrCol.h"

void strcolSet(StrCol *Col){
    Col->cont = 0;
    Col->str = NULL;
}

void insertString(StrCol *Strings, char* string){
    int i = 0, cont;
    //char* string;

    if (string == NULL){
        string = String();
    }

    if(Strings->cont == 0)
        Strings->str = (char*) malloc(SIZE_STR);

    for(cont = 0; cont <= Strings->cont;i++){

        if( i != 0 && Strings->str[i] == '\0'){ //se não for o início da string e o caracter for o '\0', vai para o próximo caracter, e incrementa o contador de posições
            i++;
            cont++;
        }
        if(cont == Strings->cont){ //se o contador leu o último contato
            Strings->str = (char*) realloc(Strings->str, i + strlen(string) + 1); // 1 por causa o barra zero delas
            strcpy(&Strings->str[i], string); //i+1, porque o i atal é o \0
            break;
        }/*ISA'\0'jin'\0'suga*/
    }
    free(string);
    Strings->cont++;
}

char* String(){
    char* str;
    int i, block = 0;
    str = (char *) malloc(SIZE_STR * (++block));
    for(i = 0; i<=SIZE_STR*block; i++) //preenche a string de acordo com o tamanho do bloco
    {
        system("cls");
        if(i!= 0)
            printf("%s", str); //se tiver algo na string

        if(SIZE_STR*block == i) //lotou a capacidade da string
            str = (char *) realloc(str, (SIZE_STR * ++block));  //realoca mais um bloco para str


        str[i] = getche();
        fflush(stdin);
        //str[i+1] = '\0';

        if(str[i] == 10 || str[i] == 13){ //se o usuário der ENTER, coloca o \0
            if(i == 0){ //se ele der backspace sem ter escrito nada
                free(str);
                return NULL;
            }
            str[i] = '\0';
            break;
        }

        str[i+1] = '\0';

        if(str[i] == 8){ //backspace
            if(i != 0) //caso a string não esteja vazia, decrementa
                i--;
        }

    } //end for
    str = (char *) realloc(str, strlen(str)+1); //realoca a string para o tamanho dela real + 1 do \0
    return str;//retorna o endereço inicial da string
}

char* stringLabeled(char *label){
    char* str;
    int i, block = 0;
    str = (char *) malloc(SIZE_STR * (++block));
    for(i = 0; i<=SIZE_STR*block; i++) //preenche a string de acordo com o tamanho do bloco
    {
        system("cls");
        if(label != NULL){
            printf("%s", label);
        }
        if(i!= 0)
            printf("%s", str); //se tiver algo na string

        if(SIZE_STR*block == i) //lotou a capacidade da string
            str = (char *) realloc(str, (SIZE_STR * ++block));  //realoca mais um bloco para str


        str[i] = getche();
        fflush(stdin);
        //str[i+1] = '\0';

        if(str[i] == 10 || str[i] == 13){ //se o usuário der ENTER, coloca o \0
            if(i == 0){ //se ele der backspace sem ter escrito nada
                free(str);
                return NULL;
            }
            str[i] = '\0';
            break;
        }

        str[i+1] = '\0';

        if(str[i] == 8){ //backspace
            if(i != 0) //caso a string não esteja vazia, decrementa
                i-=2;
            continue;
        }

    } //end for
    str = (char *) realloc(str, strlen(str)+1); //realoca a string para o tamanho dela real + 1 do \0
    return str;//retorna o endereço inicial da string
}

char* returnString(StrCol *String, int pos){
    int cont;
    int i = 0;

    for(cont = 0; cont <= pos;)
    {
        if( i != 0 && String->str[i] == '\0'){ //se não for o início da string e o caracter for o '\0', vai para o próximo caracter, e incrementa o contador de posições
            i++;
            cont++;
            continue;
        }
        if(cont == pos){ //se o contador é o mesmo da posição indicada,
            return &(String->str[i]);
        }

        i++;
    }
    return NULL;
}

void deleteCol(StrCol *Col){
    free(Col->str);
    strcolSet(Col);
}

void printString(StrCol *String, int pos){ //2
    int cont;
    int i = 0;
    //printf("%s", &String->str[pos]);
   for(cont = 0; cont < pos;)
    {
        if(String->str[i] == '\0'){ //se não for o início da string e o caracter for o '\0', vai para o próximo caracter, e incrementa o contador de posições
            i++;
            cont++;
            continue;
        }
        if(cont == pos){
            break;
        }
        i++;
    }
    printf("%s", &String->str[i]);
}

void deleteString(StrCol* String, int pos){
    int i, cont, length;
    length = strlen(returnString(String, pos));

    for(i=0, cont = 0; cont < String->cont; i++){
        if(String->str[i] == '\0'){
            cont++;
        }
        if(cont >= pos){
            if(pos == String->cont - 1){
                break;
            }
            String->str[i] = String->str[i+length+1];
        }
    }
    String->cont--;
    String->str = (char*) realloc(String->str, i+1);
}

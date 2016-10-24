#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <locale.h>

#include "menu.h"

int menu(Agenda* agenda);

int main(){
    setlocale(LC_ALL, "portuguese");

    Agenda agenda;

    agendaInit(&agenda);

   do{
        system("color 0b");
    } while(menu(&agenda));
/*
    StrCol strcol;
    strcolSet(&strcol);

    int i;
    for(i = strcol.cont; i<5; i++){
        printf("\n%i ", i);
        insertString(&strcol, String());
    }

    for(i = 0; i<5; i++){
        printString(&strcol, i);
        puts(" ");
    }

    printf("\n\nDeletar contato na posição: ");
    scanf("%1i", &i);
    fflush(stdin);

    deleteString(&strcol, i);

    for(i = 0; i<strcol.cont; i++){
        printf("\n%i %s\n", i, returnString(&strcol, i));
    }
*/
}

int menu(Agenda* agenda){
    system("cls");
    printf("\n1. NOVO CONTATO\n"
            "2. LISTAR CONTATOS\n"
            "3. DELETAR CONTATO\n"
            "4. LIMPAR AGENDA\n"
            "5. SAIR\n \n>> ");

    //user_input = getchar();
    fflush(stdin);

    switch(getchar()){
        case '1': novoContato(agenda);break;
        case '2': system("cls"); listaContatos(agenda); break;
        case '3': system("cls"); apagaContato(agenda); break;
        case '4': limparAgenda(agenda); break;
        case '5': sair(agenda); return 0;
        default:
            logMsg(1);
    }

    agendaRealoc(agenda);
    return 1;
}

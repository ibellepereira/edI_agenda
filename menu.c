#include "menu.h"

void novoContato(Agenda* agenda){
    Contato* novo;
    novo = (Contato*) malloc(sizeof(Contato));

    strcolSet(&novo->tel);
    strcolSet(&novo->email);

    if(novo == NULL) logMsg(2); // memória insuficiente
    else
    {
        system("cls");
        char tempNome[TAM_NOME];

        fflush(stdin);
        printf("Nome: ");
        gets(tempNome);
        fflush(stdin);

        //tempNome = stringLabeled("Nome: ");

        if(tempNome == 13)
            insereNome(novo, "(SEM NOME)");
        else
            insereNome(novo, tempNome);

        loopInsercao(novo, -1); //telefone
        loopInsercao(novo, 1); //email
    }

    if(novo->tel.cont == 0 && novo->email.cont == 0){//não salva contatos sem número e emails
        logMsg(3);
        free(novo);
    }
    else{//insere na ordem alfabética
        int i, testaString;

        for(i = agenda->numContatos; i>=0; i--){
            if (i == 0){
                agenda->contatos[i] = novo;
                break;
            }

            testaString = strcasecmp(novo->nome, agenda->contatos[i-1]->nome);

            if( testaString < 0){ //se o nome do ultimo contato inserido for menor que o do anterior a ele
                agenda->contatos[i] = agenda->contatos[i-1]; //o último passa a ser o anterior
                continue;
            }
            else {
                agenda->contatos[i] = novo;
                break;
            }

        }//end for
        agenda->numContatos++;
    }
}

void mostraContato(Agenda* agenda, int i){
    int cont;

    printf("%s", retornaNome(agenda->contatos[i]));

    if(agenda->contatos[i]->tel.cont > 0)
    {
        //printf("\n\n\t");
        //msg(2); //mensagem "telefones:"

        for(cont = 0; cont < agenda->contatos[i]->tel.cont; cont++){
            printf("\n\tT(%i) %s", cont+1, retornaTel(agenda->contatos[i], cont));
        }
    }

    if(agenda->contatos[i]->email.cont >0 && agenda->contatos[i]->tel.cont > 0)
       printf("\n");//uma questão de boniteza ;D

    if(agenda->contatos[i]->email.cont > 0)
    {
        //printf("\n\n\t");
        //msg(3); //mensagem "emails: "

        for(cont = 0; cont < agenda->contatos[i]->email.cont; cont++){
            printf("\n\tE(%i) %s", cont+1, retornaEmail(agenda->contatos[i], cont));
        }
    }

}

void listaContatos(Agenda* agenda){
    int i;

    if(agenda->numContatos == 0) logMsg(5);
    else
    {
        for(i = 0; i<agenda->numContatos; i++){
            printf("%i. ", i+1);
            mostraContato(agenda, i);
            printf("\n\n===============================================\n\n");
        }

    getche();
    }
    fflush(stdin);
}

void listaCompacta(Agenda* agenda){
    int cont;

    for(cont = 0; cont < agenda->numContatos; cont++){
        printf("\n%i. %s", cont+1, retornaNome(agenda->contatos[cont]));
    }
}

void apagaContato(Agenda* agenda){
    char input[4];
    //listaCompacta(agenda);

    if(agenda->numContatos > 0)
    {
        listaCompacta(agenda);
        printf("\n\n>> ");

        fflush(stdin);
        gets(input);

        if(atoi(input)>0 && atoi(input) <= agenda->numContatos){
            deletaContato(agenda, atoi(input)-1);
        }
        else logMsg(4); //qualquer outra coisa (letras ou enter, ele termina execução)

    }//end for

    else logMsg(5);



}

void limparAgenda(Agenda* agenda){
    if(agenda->numContatos == 0)
        logMsg(5);
    else
        limpaAgenda(agenda, 1); //1 indica que é pra resetar a agenda
}

void sair(Agenda* agenda){
    limpaAgenda(agenda, 0); //0 dá um free na agenda
}

void msg(int n){
    switch(n){
        case 1: printf("Nome: "); break;
        case 2: printf("Telefone(s): "); break;
        case 3: printf("E-mail(s): "); break;
        //case 4: printf("Agenda vazia");
    }
}

void logMsg(int n){
    system("cls");
    system("color 0c");
    switch (n){
        case 1: printf("\nEntrada Inválida\n"); break;
        case 2: printf("\nMemória insuficiente\n"); break;
        case 3: printf("\nContato não será salvo\nObs.: Contato não possui telefones ou emails\n"); break;
        case 4: printf("\nContato inexistente\n"); break;
        case 5: printf("\nAgenda vazia\n"); break;
        case 6: printf("\nEntrada incorreta: telefone não pode conter mais que %d dígitos.\n\n", TAM_TEL); break;
    }
    getche();
    fflush(stdin);
    system("color 0b");
}

char* getEmailCheck(){
    char *email;
    int i;

    for(;;){
        email = stringLabeled("E-mail: ");

        if(email == NULL){
           return email;
        }


        for(i=0; i<strlen(email); i++){
            if(email[0] == 10 || email[0] == 13){
                free(email);
                return NULL;
            }

            if(email[i] == '@'){
                return email;
            }
        }
        logMsg(1);
        free(email);
    }

}

char* getTelCheck(){
    char *tel;
    int i, fail = 0;

    for(;;){
        fail = 0;
        do{
            tel = stringLabeled("Telefone: ");

            if(tel == NULL){
                return tel;
            }
            if(strlen(tel)>15){
                logMsg(6);
                //printf("Entrada incorreta: telefone não pode conter mais que %d dígitos.\n\n", TAM_TEL);
                //system("pause");
            }
        } while(strlen(tel)>15);


        for(i=0; i<strlen(tel); i++){
            if(tel[0] == 10 || tel[0] == 13){
                free(tel);
                return NULL;
            }

            if(tel[i] != '0' && tel[i] != '1' && tel[i] != '2'&& tel[i] != '3' && tel[i] != '4'&& tel[i] != '5'&& tel[i] != '6'&& tel[i] != '7'&& tel[i] != '8'&& tel[i] != '9'){
                logMsg(1);
                fail = 1;
                break;
            }
        }

        if (fail <= 0){
            return tel;
        }
        free(tel);
    }
}

void loopInsercao(Contato* contato, int modo){//telefone:+1  email: -1
    char* string;
    string = NULL;

    for(;;){
        if(modo<0) string = getTelCheck();
        else string = getEmailCheck();

        if(string == NULL){
            break;
        }

        if(modo<0) insertString(&contato->tel, string);
        else insertString(&contato->email, string);
    }
}

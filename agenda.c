#include "agenda.h"

void agendaInit(Agenda *agenda){
    agenda->contatos = (Contato**) malloc(BLOCO_AGD * sizeof(Contato *));
    agenda->numBlocks = 1;
    agenda->numContatos = 0;
}

void agendaRealoc(Agenda *agenda){
    //se a capacidade de armazenamento dos blocos já alocados menos a quantidade de contatos na agenda for igual a 0
    //isto é, se a agenda estiver lotada, aloca mais um bloco para ela e atualiza.
    if(agenda->numBlocks * BLOCO_AGD - agenda->numContatos == 0){
        agenda->contatos = (Contato**) realloc(agenda->contatos, (BLOCO_AGD * agenda->numBlocks) + (BLOCO_AGD * sizeof(Contato *)));
        agenda->numBlocks++;
    }
}

//-----------------------------------------------------------------------------------------------------------------------

void insereNome(Contato *contato, char* nome){
    strcpy(&contato->nome, nome);
}

void insereTel(Contato* contato, char* telefone){
    insertString(&contato->tel, telefone);
}

void insereEmail(Contato* contato, char* email){
    insertString(&contato->email, email);
}

void deletaTel(Contato* contato, int i){
    deleteString(&contato->tel, i);
}

void deletaEmail(Contato* contato, int i){
    deleteString(&contato->email, i);
}

char* retornaNome(Contato* contato){
    return contato->nome;
}

char* retornaTel(Contato* contato, int i){
    return returnString(&contato->tel, i);
}

char* retornaEmail(Contato* contato, int i){
    return returnString(&contato->email, i);
}

void deletaContato(Agenda* agenda, int i){
    int cont;

    deleteCol(&agenda->contatos[i]->tel);
    deleteCol(&agenda->contatos[i]->email);
    free(agenda->contatos[i]);

    agenda->numContatos--;

    //rearruma a agenda
    for(cont = i; cont<agenda->numContatos; cont++){ // varre a agenda toda
        agenda->contatos[cont] = agenda->contatos[cont+1]; //a partir do índice removido, aponte para o próximo.
    }
}

void limpaAgenda(Agenda* agenda, int restart){//reseta: 1 sai: 0
    int i;

    for(i=0; i<agenda->numContatos; i++)
        deletaContato(agenda, i);

    //achei menos custoso, realocar a agenda que liberar tudo e alocar de novo.
    agenda->numContatos = 0;
    agenda->numBlocks = 0;

    if(restart) agendaRealoc(agenda); //caso continue a aplicação
    else free(agenda); //senão, libera o espaço da agenda
}

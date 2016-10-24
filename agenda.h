#include <stdlib.h>
#include <string.h>

#include "StrCol.h"

#define TAM_NOME 51
#define TAM_TEL 15
#define TAM_EMAIL 51

#define BLOCO_STR 3
#define BLOCO_AGD 5

typedef struct _contato{
    char nome[TAM_NOME];
    StrCol tel;
    StrCol email;
} Contato;

typedef struct _agenda{
    Contato** contatos;
    int numBlocks;
    int numContatos;
} Agenda;

/* M�TODOS PARA GERECIAMENTO DA MEM�RIA DA AGENDA */
void agendaInit(Agenda* agenda);
void agendaRealoc(Agenda* agenda);

/* M�TODOS DO CONTATO */
void insereNome(Contato* contato, char* nome); //INSERE O NOME, DADO UMA REFER�NIA PARA CONTATO
void insereTel(Contato* contato, char* telefone); //INSERE O TELEFONE, DADOS A REFER�NCIA PARA O CONTATO E INDICE DO TELEFONE
void insereEmail(Contato* contato, char* email); //INSERE O EMAIL, DADOS A REFER�NCIA PARA O CONTATO E INDICE DO TELEFONE

void deletaTel(Contato* contato, int i); //APAGA DETERMINADO TELEFONE, DADO A REFER�NCIA PARA O CONTATO E O �NDICE DO TELEFONE
void deletaEmail(Contato* contato, int i); //APAGA DETERMINADO EMAIL, DADO A REFER�NCIA PARA O CONTATO E O �NDICE DO TELEFONE

char* retornaNome(Contato* contato);
char* retornaTel(Contato* contato, int i);
char* retornaEmail(Contato* contato, int i);

void deletaContato(Agenda* agenda, int i);
void limpaAgenda(Agenda* agenda, int restart); //PARA RESETAR SOMENTE, RESTART = 1, SENAO RESTART = 0


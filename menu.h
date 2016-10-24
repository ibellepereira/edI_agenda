#include <stdlib.h>
#include <stdio.h>
#include "agenda.h"

//funções chamadas do main, que fazem manipulações das funções de Agenda e StrCol

void novoContato(Agenda* agenda);
void mostraContato(Agenda* agenda, int i);
void listaContatos(Agenda* agenda);
void listaCompacta(Agenda* agenda); // lista contatos, porém sem exibir telefones e emails
void apagaContato(Agenda* agenda);
void limparAgenda(Agenda* agenda);
void sair(Agenda* agenda);

void msg(int n);
void logMsg(int n);

char* getEmailCheck();
char* getTelCheck();

void loopInsercao(Contato* contato, int modo);


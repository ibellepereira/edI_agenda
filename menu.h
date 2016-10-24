#include <stdlib.h>
#include <stdio.h>
#include "agenda.h"

//fun��es chamadas do main, que fazem manipula��es das fun��es de Agenda e StrCol

void novoContato(Agenda* agenda);
void mostraContato(Agenda* agenda, int i);
void listaContatos(Agenda* agenda);
void listaCompacta(Agenda* agenda); // lista contatos, por�m sem exibir telefones e emails
void apagaContato(Agenda* agenda);
void limparAgenda(Agenda* agenda);
void sair(Agenda* agenda);

void msg(int n);
void logMsg(int n);

char* getEmailCheck();
char* getTelCheck();

void loopInsercao(Contato* contato, int modo);


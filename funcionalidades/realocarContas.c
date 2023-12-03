//cabeçalhos do compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

/*
Realoca um espaço extra no vetor contas.
Parâmetros: vetor contas, quantidade de contas para realocar, conta que vai ser adicionada no vetor
*/
void realocarContas(conta *contas,int qtdContas,conta conta){
    //realoca um espaço extra no vetor contas
    contas = realloc(contas,(qtdContas) * sizeof(conta));
    //adiciona uma nova conta ao vetor
    contas[qtdContas-1] = conta;
}
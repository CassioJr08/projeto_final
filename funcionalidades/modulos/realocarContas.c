//cabeçalhos do compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//cabeçalhos do projeto
#include "../../headers/conta.h"

/*
Realoca um espaço extra no vetor contas.
Parâmetros: vetor de contas e tamanho para realocar.

Ex.: realocarContas(&contas, &tamanho).

Obs.: O parâmetro tamanho é o tamanho novo a ser realocado. Caso seja necessário inserir uma nova conta no vetor e o tamanho atual seja 1, o parâmetro receberá o valor 2 (tamanho atual + 1).
*/
void realocarContas(conta **contas,int *tamanho){
    *contas = realloc(*contas,(*tamanho + 1) * sizeof(conta));
    *tamanho += 1;
}
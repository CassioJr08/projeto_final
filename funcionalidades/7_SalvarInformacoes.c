//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

void SalvarInformacoes(conta contas[]){

    char numConta[9];

    printf("\nInsira o numero da conta que deseja salvar: ");
    scanf("%s",numConta);

    int i = 0;
    while(strcmp(contas[i].numero,numConta) != 0){
        i++;
    }

    if(salvarConta(contas[i])){
        printf("Os dados da conta %s foram salvos com sucesso!\n",numConta);
    }else{
        printf("Ocorreu algum problema ao salvar os dados da conta %s. Tente de novo!",numConta);
    };
}
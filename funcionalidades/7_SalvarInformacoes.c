//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

/*
Salva as informações das contas em um arquivo(.csv).
Parâmetros: vetor contas, quantidade de contas
*/
void SalvarInformacoes(conta contas[],int qtdContas){

    //VARIÁVEIS
    char numConta[9];
    int opcao;
    int i;

    printf("\nQuantidade de contas: %d\n",qtdContas);

    printf("\nEscolha uma opcao:\n");
    printf("1. Salvar todas as contas de uma vez.\n");
    printf("2. Salvar apenas uma conta (necessario informar o numero da conta).\n");
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            for(i=0;i<qtdContas;i++){
                if(salvarConta(contas[i])){
                    printf("Os dados da conta %s foram salvos com sucesso!\n",contas[i].numero);
                }else{
                    printf("Ocorreu algum problema ao salvar os dados da conta %s. Tente de novo!\n",contas[i].numero);
                };
            }
            break;
        case 2:
            printf("\nInsira o numero da conta que deseja salvar: ");
            scanf("%s",numConta);
            i = 0;
            while(strcmp(contas[i].numero,numConta) != 0){
                i++;
            }
            if(salvarConta(contas[i])){
                printf("Os dados da conta %s foram salvos com sucesso!\n",numConta);
            }else{
                printf("Ocorreu algum problema ao salvar os dados da conta %s. Tente de novo!",numConta);
            };
            break;
        default:
            printf("Opcao %d invalida!\n",opcao);
    }
}
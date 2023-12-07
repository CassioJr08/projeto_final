//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

void RemoverConta() {

    char numeroConta[9]; //número da conta bancária

    printf("\nDigite o numero da conta: ");
    scanf("%s",numeroConta);

    if(!contaExiste(numeroConta)){
        printf("\nErro: A conta %s nao existe!\n",numeroConta);
        return;
    }

    conta conta = pesquisarConta(numeroConta);

    //exibe as informações atuais da conta
    printf("\nConta %s\n",conta.numero);
    printf("\tTitular: %s\n",conta.titular);
    printf("\tSaldo: R$ %.2lf\n",conta.saldo);

    char confirma; //confirma a opção do usuário

    do{
        printf("\nTem certeza que deseja excluir a conta %s? [S/N] ",conta.numero);
        scanf("\n%c",&confirma);
    }while(tolower(confirma) != 's' && tolower(confirma) != 'n');

    if(tolower(confirma) == 's'){
        
        char dir[255]; //diretório do arquivo
        //cria o diretório
        strcpy(dir,"../contas/");
        strcat(dir,conta.numero);
        strcat(dir,".csv");

        //tenta excluir o arquivo CSV da conta
        if(remove(dir) == 0){
            printf("\nConta exluida com sucesso!\n");
        }else{
            printf("\nErro: Nao foi possivel excluir a conta %s!\n",conta.numero);
        }
    }

}
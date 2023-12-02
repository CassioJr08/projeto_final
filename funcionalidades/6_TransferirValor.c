//importa os arquivos de cabeçalho, nesses arquivos estão todas as definições de variáveis, structs e funções
#include "../headers/conta.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void TransferirValor(){
// Função para transferir valor de uma conta para outra

    //VARIÁVEIS
    int i;
    char numContaOrigem[9];
    char numContaDestino[9];
    char dirContaOrigem[255];
    char dirContaDestino[255];
    double transferencia;
    FILE *fcontaOrigem;
    FILE *fcontaDestino;
    char dadosContaOrigem[255];
    char dadosContaDestino[255];
    conta contaOrigem;
    conta contaDestino;
    char *token;
    char *endptr;

    // Solicitar informações da transferência ao usuário
    printf("\nDigite o numero da conta de origem: ");
    scanf("%s", numContaOrigem);

    printf("Digite o numero da conta de destino: ");
    scanf("%s", numContaDestino);

    printf("Digite o valor a ser transferido: R$ ");
    scanf("%lf", &transferencia);

    //diretório da conta origem
    strcpy(dirContaOrigem,"./contas/");
    strcat(dirContaOrigem,numContaOrigem);
    strcat(dirContaOrigem,".csv");
    //diretório da conta destino
    strcpy(dirContaDestino,"./contas/");
    strcat(dirContaDestino,numContaDestino);
    strcat(dirContaDestino,".csv");

    //verifica se a conta origem existe
    if(access(dirContaOrigem,F_OK) != 0){
        printf("A conta %s nao existe!\n",numContaOrigem);
        return;
    }else{
        fcontaOrigem = fopen(dirContaOrigem,"r");
        //lê o arquivo
        fscanf(fcontaOrigem,"%[^\n]",dadosContaOrigem);
        //extrai os dados do arquivo
        token = strtok(dadosContaOrigem,",");
        strcpy(contaOrigem.numero,token);
        token = strtok(NULL,",");
        strcpy(contaOrigem.titular,token);
        token = strtok(NULL,",");
        contaOrigem.saldo = strtod(token,&endptr);
    }
    //verifica se a conta destino existe
    if(access(dirContaDestino,F_OK) != 0){
        printf("A conta %s nao existe!\n",numContaDestino);
        return;
    }else{
        fcontaDestino = fopen(dirContaDestino,"r");
        //lê o arquivo
        fscanf(fcontaDestino,"%[^\n]",dadosContaDestino);
        //extrai os dados do arquivo
        token = strtok(dadosContaDestino,",");
        strcpy(contaDestino.numero,token);
        token = strtok(NULL,",");
        strcpy(contaDestino.titular,token);
        token = strtok(NULL,",");
        contaDestino.saldo = strtod(token,&endptr);
    }

    //ANTES DA OPERAÇÃO
    printf("\nConta origem\n");
    printf("Numero: %s\n",contaOrigem.numero);
    printf("Titular: %s\n",contaOrigem.titular);
    printf("Saldo: R$ %.2lf\n",contaOrigem.saldo);
    printf("\nConta destino\n");
    printf("Numero: %s\n",contaDestino.numero);
    printf("Titular: %s\n",contaDestino.titular);
    printf("Saldo: %.2lf\n",contaDestino.saldo);


    //verifica a conta origem possui saldo suficiente
    if(contaOrigem.saldo < transferencia){
        printf("A conta %s nao possui saldo suficiente para transferencia!\n",contaOrigem.numero);
        return;
    }else{
        //realiza a transferência
        contaOrigem.saldo -= transferencia;
        contaDestino.saldo += transferencia;
        fclose(fcontaOrigem);
        fclose(fcontaDestino);
        fcontaOrigem = fopen(dirContaOrigem,"w");
        fcontaDestino = fopen(dirContaDestino,"w");
        fprintf(fcontaOrigem,"%s,%s,%.2lf",contaOrigem.numero,contaOrigem.titular,contaOrigem.saldo);
        fprintf(fcontaDestino,"%s,%s,%.2lf",contaDestino.numero,contaDestino.titular,contaDestino.saldo);
    }

    //DEPOIS DA OPERAÇÃO
    printf("\nConta origem\n");
    printf("Numero: %s\n",contaOrigem.numero);
    printf("Titular: %s\n",contaOrigem.titular);
    printf("Saldo: R$ %.2lf\n",contaOrigem.saldo);
    printf("\nConta destino\n");
    printf("Numero: %s\n",contaDestino.numero);
    printf("Titular: %s\n",contaDestino.titular);
    printf("Saldo: %.2lf\n",contaDestino.saldo);

}


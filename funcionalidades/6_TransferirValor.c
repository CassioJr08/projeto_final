//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

void TransferirValor(){
// Função para transferir valor de uma conta para outra

    //VARIÁVEIS
    char numContaOrigem[9];
    char numContaDestino[9];
    char dirContaOrigem[255];
    char dirContaDestino[255];
    double transferencia;
    conta contaOrigem;
    conta contaDestino;

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
    if(contaExiste(dirContaOrigem)){
        printf("A conta %s nao existe!\n",numContaOrigem);
        return;
    }else{
        contaOrigem = pesquisarConta(numContaOrigem);
    }
    //verifica se a conta destino existe
    if(contaExiste(dirContaDestino)){
        printf("A conta %s nao existe!\n",numContaDestino);
    }else{
        contaDestino = pesquisarConta(numContaDestino);
    }

    //ANTES DA OPERAÇÃO
    printf("\nDADOS ANTES DA OPERACAO\n");
    printf("\n\tConta origem\n");
    printf("\tNumero: %s\n",contaOrigem.numero);
    printf("\tTitular: %s\n",contaOrigem.titular);
    printf("\tSaldo: R$ %.2lf\n",contaOrigem.saldo);
    printf("\n\tConta destino\n");
    printf("\tNumero: %s\n",contaDestino.numero);
    printf("\tTitular: %s\n",contaDestino.titular);
    printf("\tSaldo: %.2lf\n",contaDestino.saldo);


    //verifica a conta origem possui saldo suficiente
    if(contaOrigem.saldo < transferencia){
        printf("A conta %s nao possui saldo suficiente para transferencia!\n",contaOrigem.numero);
        return;
    }else{
        //realiza a transferência
        contaOrigem.saldo -= transferencia;
        contaDestino.saldo += transferencia;
        salvarConta(contaOrigem);
        salvarConta(contaDestino);
    }

    //DEPOIS DA OPERAÇÃO
    printf("\nDADOS DEPOIS DA OPERACAO\n");
    printf("\n\tConta origem\n");
    printf("\tNumero: %s\n",contaOrigem.numero);
    printf("\tTitular: %s\n",contaOrigem.titular);
    printf("\tSaldo: R$ %.2lf\n",contaOrigem.saldo);
    printf("\n\tConta destino\n");
    printf("\tNumero: %s\n",contaDestino.numero);
    printf("\tTitular: %s\n",contaDestino.titular);
    printf("\tSaldo: %.2lf\n",contaDestino.saldo);

}
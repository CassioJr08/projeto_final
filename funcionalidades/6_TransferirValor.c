// transferencia.c

#include <stdio.h>
#include <string.h>
#include "../headers/conta.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma conta bancária
typedef struct {
    char numero[20];
    char titular[100];
    double saldo;
} ContaBancaria;

void salvarContaNoArquivo(const char *nomeArquivo, const ContaBancaria *conta) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivo, "%s,%s,%.2lf", conta->numero, conta->titular, conta->saldo);

    fclose(arquivo);
}

void lerContaDoArquivo(const char *nomeArquivo, ContaBancaria *conta) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%19[^,],%99[^,],%lf", conta->numero, conta->titular, &conta->saldo);

    fclose(arquivo);
}

void transferirSaldo(const char *numContaOrigem, const char *numContaDestino, double valor) {
    char dirContaOrigem[100];
    char dirContaDestino[100];

    // Construir o caminho do arquivo para a conta de origem
    strcpy(dirContaOrigem, "../contas/");
    strcat(dirContaOrigem, numContaOrigem);
    strcat(dirContaOrigem, ".csv");

    // Construir o caminho do arquivo para a conta de destino
    strcpy(dirContaDestino, "../contas/");
    strcat(dirContaDestino, numContaDestino);
    strcat(dirContaDestino, ".csv");

    // Abrir arquivo da conta de origem para leitura
    ContaBancaria contaOrigem;
    lerContaDoArquivo(dirContaOrigem, &contaOrigem);

    // Validar se há saldo suficiente na conta de origem
    if (contaOrigem.saldo < valor) {
        printf("\nErro: Saldo insuficiente para realizar a transferência.\n");
        return;
    }

    // Abrir arquivo da conta de destino para leitura
    ContaBancaria contaDestino;
    lerContaDoArquivo(dirContaDestino, &contaDestino);

    // Realizar a transferência
    contaOrigem.saldo -= valor;
    contaDestino.saldo += valor;

    // Salvar contas atualizadas nos arquivos
    salvarContaNoArquivo(dirContaOrigem, &contaOrigem);
    salvarContaNoArquivo(dirContaDestino, &contaDestino);

    // Exibir dados após a operação
    printf("\nDADOS DEPOIS DA OPERACAO\n");
    printf("\n\tConta origem\n");
    printf("\tNumero: %s\n", contaOrigem.numero);
    printf("\tTitular: %s\n", contaOrigem.titular);
    printf("\tSaldo: R$ %.2lf\n", contaOrigem.saldo);
    printf("\n\tConta destino\n");
    printf("\tNumero: %s\n", contaDestino.numero);
    printf("\tTitular: %s\n", contaDestino.titular);
    printf("\tSaldo: R$ %.2lf\n", contaDestino.saldo);
}

void TransferirValor() {

    char numContaOrigem[20];
    char numContaDestino[20];
    double valor;

    // Obter informações do usuário
    printf("\nInforme o numero da conta de origem: ");
    scanf("%s", numContaOrigem);

    printf("\nInforme o numero da conta de destino: ");
    scanf("%s", numContaDestino);

    printf("\nInforme o valor a ser transferido: ");
    scanf("%lf", &valor);

    // Chamar a função de transferência
    transferirSaldo(numContaOrigem, numContaDestino, valor);
}

#include <stdio.h>
/*
Douglas_
Estava faltando incluir a biblioteca stdio!
*/
#include "../headers/conta.h"

void salvarContaNoArquivo(const char *nomeArquivo, const conta *conta) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        esperar(1000);
        limparTela();
        return 0;
    }

    fprintf(arquivo, "%s,%s,%.2lf", conta->numero, conta->titular, conta->saldo);

    fclose(arquivo);
}

void lerContaDoArquivo(const char *nomeArquivo, conta *conta) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        esperar(1000);
        limparTela();
        return 0;
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
    conta contaOrigem;
    lerContaDoArquivo(dirContaOrigem, &contaOrigem);

    // Validar se há saldo suficiente na conta de origem
    if (contaOrigem.saldo < valor) {
        printf("Saldo insuficiente para realizar a transferência.\n");
        esperar(1000);
        limparTela();
        return;
    }

    // Abrir arquivo da conta de destino para leitura
    conta contaDestino;
    lerContaDoArquivo(dirContaDestino, &contaDestino);

    // Realizar a transferência
    contaOrigem.saldo -= valor;
    contaDestino.saldo += valor;

    // Salvar contas atualizadas nos arquivos
    salvarContaNoArquivo(dirContaOrigem, &contaOrigem);
    salvarContaNoArquivo(dirContaDestino, &contaDestino);

    esperar(800);
    limparTela();

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

    esperar(4000);
    limparTela();
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/conta.h"

// Estrutura para representar uma conta bancaria...
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
        printf("Caminho do arquivo: %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%19[^,],%99[^,],%lf", conta->numero, conta->titular, &conta->saldo);

    fclose(arquivo);
}

void realizarDeposito(const char *numConta, double valor) {
    char dirConta[100];

    // Construir o caminho do arquivo para a conta
    strcpy(dirConta, "../contas/");
    strcat(dirConta, numConta);
    strcat(dirConta, ".csv");

    // Abrir arquivo da conta para leitura
    ContaBancaria conta;
    lerContaDoArquivo(dirConta, &conta);

    // Realizar o deposito
    conta.saldo += valor;

    // Salvar conta atualizada no arquivo
    salvarContaNoArquivo(dirConta, &conta);

    // Exibir dados apos a operação
    printf("\nDADOS APoS O DEPoSITO\n");
    printf("\n\tConta\n");
    printf("\tNumero: %s\n", conta.numero);
    printf("\tTitular: %s\n", conta.titular);
    printf("\tSaldo: R$ %.2lf\n", conta.saldo);
}

void realizarSaque(const char *numConta, double valor) {
    char dirConta[100];

    // Construir o caminho do arquivo para a conta
    strcpy(dirConta, "../contas/");
    strcat(dirConta, numConta);
    strcat(dirConta, ".csv");

    // Abrir arquivo da conta para leitura
    ContaBancaria conta;
    lerContaDoArquivo(dirConta, &conta);

    // Validar se há saldo suficiente
    if (conta.saldo < valor) {
        printf("Saldo insuficiente para realizar o saque.\n");
        exit(EXIT_FAILURE);
    }

    // Realizar o saque
    conta.saldo -= valor;

    // Salvar conta atualizada no arquivo
    salvarContaNoArquivo(dirConta, &conta);

    // Exibir dados apos a operação
    printf("\nDADOS APoS O SAQUE\n");
    printf("\n\tConta\n");
    printf("\tNumero: %s\n", conta.numero);
    printf("\tTitular: %s\n", conta.titular);
    printf("\tSaldo: R$ %.2lf\n", conta.saldo);
}

void realizarOperacao() {
    int opcao;
    char numConta[20];
    double valor;

    // Exibe o menu
    printf("\nEscolha uma opcao:\n");
    printf("1. Realizar Deposito\n");
    printf("2. Realizar Saque\n");
    printf("0. Sair\n");

    // Obtém a escolha do usuário
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Opcao 1 selecionada: Realizar Deposito\n");
            printf("Informe o numero da conta: ");
            scanf("%s", numConta);
            printf("Informe o valor: ");
            scanf("%lf", &valor);
            realizarDeposito(numConta, valor);
            break;
        case 2:
            printf("Opcao 2 selecionada: Realizar Saque\n");
            printf("Informe o numero da conta: ");
            scanf("%s", numConta);
            printf("Informe o valor: ");
            scanf("%lf", &valor);
            realizarSaque(numConta, valor);
            break;
        case 0:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opcao Invalida. Tente novamente!!!\n");
    }
}

int main() {
    realizarOperacao();
    return 0;
}

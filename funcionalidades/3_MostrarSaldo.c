#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/conta.h"

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
        printf("Caminho do arquivo: %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%19[^,],%99[^,],%lf", conta->numero, conta->titular, &conta->saldo);

    fclose(arquivo);
}

void consultarSaldoConta(const char *numConta) {
    char dirConta[100];

    // Construir o caminho do arquivo para a conta
    snprintf(dirConta, sizeof(dirConta), "../contas/%s.csv", numConta);

    // Abrir arquivo da conta para leitura
    FILE *arquivo = fopen(dirConta, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        printf("Caminho do arquivo: %s\n", dirConta);
        exit(EXIT_FAILURE);
    }

    ContaBancaria conta;
    fscanf(arquivo, "%19[^,],%99[^,],%lf", conta.numero, conta.titular, &conta.saldo);

    // Exibir dados da conta
    printf("\nDADOS DA CONTA\n");
    printf("\n\tConta\n");
    printf("\tNumero: %s\n", conta.numero);
    printf("\tTitular: %s\n", conta.titular);
    printf("\tSaldo: R$ %.2lf\n", conta.saldo);

    fclose(arquivo);
}

void MostrarSaldo() {
    char numConta[20];

    // Perguntar o número da conta e guardar na variável
    printf("Digite o numero da conta: ");
    scanf("%s", numConta);

    // Chama a função para mostrar o saldo
    consultarSaldoConta(numConta);
}
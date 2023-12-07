#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/conta.h"

// Função para pesquisar uma conta no arquivo CSV
conta pesquisarContaCSV(char numConta[]) {
    char dir[255];
    strcpy(dir, "./contas/"); // Ajuste: diretório local
    strcat(dir, numConta);
    strcat(dir, ".csv");

    FILE *arquivo = fopen(dir, "r");

    if (arquivo != NULL) {
        char dados[255];
        fscanf(arquivo, "%[^\n]", dados);
        fclose(arquivo);

        conta conta;
        char *token;
        char *endptr;

        token = strtok(dados, ",");
        strcpy(conta.numero, token);

        token = strtok(NULL, ",");
        strcpy(conta.titular, token);

        token = strtok(NULL, ",");
        conta.saldo = strtod(token, &endptr);

        return conta;
    } else {
        conta contaVazia = {"", "", 0.0};
        return contaVazia;
    }
}

// Função para verificar se a conta existe
bool contaExiste(char numConta[]) {
    char dir[255]; // diretório do arquivo
    // cria o diretório
    strcpy(dir, "../contas/");
    strcat(dir, numConta);
    strcat(dir, ".csv");

    if (access(dir, F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}
// Função para mostrar o saldo de uma conta
void MostrarSaldo() {
    char numConta[9];

    printf("Digite o numero da conta: ");
    scanf("%s", numConta);

    if (!contaExiste(numConta)) {
        printf("Conta nao encontrada.\n");
    } else {
        conta conta = pesquisarContaCSV(numConta);

        if (conta.saldo != 0.0) {
            printf("Numero da conta: %s\n", conta.numero);
            printf("Nome do titular: %s\n", conta.titular);
            printf("Saldo: %.2f\n", conta.saldo);
        } else {
            printf("Conta nao encontrada.\n");
        }
    }
}
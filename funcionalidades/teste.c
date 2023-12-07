#include "../headers/conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONTA_H
#define CONTA_H

// Estrutura para armazenar informações da conta
typedef struct {
    char numero[9];
    char titular[150];
    double saldo;
} conta;

bool contaExiste(char numConta[]) {
    char dir[255];
    strcpy(dir, "../contas/");
    strcat(dir, numConta);
    strcat(dir, ".csv");

    if (access(dir, F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}

conta pesquisarConta(char numConta[]) {
    char dir[255];
    strcpy(dir, "../contas/");
    strcat(dir, numConta);
    strcat(dir, ".csv");

    FILE *arquivo = fopen(dir, "r");

    char dados[255];
    fscanf(arquivo, "%[^\n]", dados);

    conta contaAtual;
    char *token;
    char *endptr;

    token = strtok(dados, ",");
    strcpy(contaAtual.numero, token);
    token = strtok(NULL, ",");
    strcpy(contaAtual.titular, token);
    token = strtok(NULL, ",");
    contaAtual.saldo = strtod(token, &endptr);

    fclose(arquivo);

    return contaAtual;
}

#endif

int main() {
    char numeroContaStr[9];

    // Perguntar o número da conta e guardar na variável
    printf("Digite o número da conta: ");
    scanf("%s", numeroConta);

    // Chamar a função contaExiste() passando o número como parâmetro
    if (contaExiste(numeroConta)) {
        // A conta existe

        // Chamar a função pesquisarConta() passando o número como parâmetro
        conta contaAtual = pesquisarConta(numeroConta);

        // Modificar os dados da struct 'conta'
        int novoNumeroConta;
        char novoNomeTitular[150];

        // Solicitar novas informações
        printf("Digite o novo nome do titular: ");
        scanf("%s", novoNomeTitular);

        printf("Digite o novo número da conta: ");
        scanf("%d", &novoNumeroConta);

        // Atualizar os dados da struct 'conta'
        strcpy(contaAtual.titular, novoNomeTitular);
        snprintf(contaAtual.numero, sizeof(contaAtual.numero), "%d", novoNumeroConta);

        // Chamar a função salvarConta() passando a struct como parâmetro
        salvarConta(contaAtual);

        // Exibir informações atualizadas
        printf("Conta %s - Titular: %s, Saldo: %.2f\n", contaAtual.numero, contaAtual.titular, contaAtual.saldo);
    } else {
        // A conta não existe, imprimir mensagem de erro e encerrar o programa
        printf("Erro: A conta com o número %s não existe.\n", numeroConta);
        return 1;
    }

    return 0;
}

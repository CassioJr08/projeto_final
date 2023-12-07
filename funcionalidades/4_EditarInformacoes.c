#include "../headers/conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int EditarInfomacoes() {
    char numeroConta[9];

    // Perguntar o número da conta e guardar na variável
    printf("Digite o número da conta: ");
    scanf("%s", numeroConta);

    // Chamar a função contaExiste() passando o número como parâmetro
    if (contaExiste(numeroConta)) {
        // A conta existe

        // Chamar a função pesquisarConta() passando o número como parâmetro
        ContaBancaria contaAtual = pesquisarConta(numeroConta);

        // Modificar os dados da struct 'ContaBancaria'
        int novoNumeroConta;
        char novoNomeTitular[150];

        // Solicitar novas informações
        printf("Digite o novo nome do titular: ");
        scanf("%s", novoNomeTitular);

        printf("Digite o novo número da conta: ");
        scanf("%d", &novoNumeroConta);

        // Atualizar os dados da struct 'ContaBancaria'
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

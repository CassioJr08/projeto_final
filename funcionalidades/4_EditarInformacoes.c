#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações da conta
typedef struct {
    int numeroConta;
    char *nomeTitular;
    float saldo;
} ContaBancaria;

// Função para criar uma nova conta
ContaBancaria *criarConta(int numeroConta, const char *nomeTitular, float saldo) {
    ContaBancaria *novaConta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    
    if (novaConta != NULL) {
        novaConta->numeroConta = numeroConta;
        novaConta->nomeTitular = strdup(nomeTitular); // Alocação dinâmica para o nomeTitular
        novaConta->saldo = saldo;
    }
    
    return novaConta;
}

// Função para editar informações do titular
void editarInformacoes(ContaBancaria *conta) {
    char novoNome[50];
    int novoNumeroConta;

    // Solicitar novas informações
    printf("Digite o novo nome do titular: ");
    scanf("%s", novoNome);

    printf("Digite o novo número da conta: ");
    scanf("%d", &novoNumeroConta);

    // Liberar a memória alocada para o nomeTitular atual
    free(conta->nomeTitular);

    // Alocar nova memória para o novo nomeTitular
    conta->nomeTitular = strdup(novoNome);
    conta->numeroConta = novoNumeroConta;

    printf("Informações da conta %d foram atualizadas.\n", conta->numeroConta);
}

// Função para liberar memória de uma conta
void liberarConta(ContaBancaria *conta) {
    free(conta->nomeTitular); // Liberar memória alocada para o nomeTitular
    free(conta); // Liberar memória da estrutura ContaBancaria
}

int main() {
    int numeroConta;
    char nomeTitular[50];
    float saldo;

    // Solicitar informações para criar a conta
    printf("Digite o número da conta: ");
    scanf("%d", &numeroConta);

    printf("Digite o nome do titular: ");
    scanf("%s", nomeTitular);

    printf("Digite o saldo inicial: ");
    scanf("%f", &saldo);

    // Criar a conta
    ContaBancaria *conta = criarConta(numeroConta, nomeTitular, saldo);

    if (conta == NULL) {
        printf("Erro ao criar a conta.\n");
        return 1;
    }

    // Editar informações da conta
    editarInformacoes(conta);

    // Exibir informações atualizadas
    printf("Conta %d - Titular: %s, Saldo: %.2f\n", conta->numeroConta, conta->nomeTitular, conta->saldo);

    // Liberar memória da conta
    liberarConta(conta);

    return 0;
}
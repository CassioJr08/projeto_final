#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Douglas

    _colocar no topo do código: #include "../headers/conta.h"

    _apagar a struct contaBancária (o código vai reconhecer a struct pelo identificador 'conta')
    ~ em caso de dúvida olhar o arquivo conta.h

    _criar uma variável do tipo vetor de char com tamanho 9
    _perguntar o número da conta e guardar na variável

    _chamar a função contaExiste() passando o número como parâmetro
    _usar um if else para validar se a conta existe, caso não exista printar um erro na tela e usar o comando "return" para parar a execução
    ~ em caso de dúvida olhar o arquivo contaExiste.c

    _apagar a função criarConta
    _no lugar chamar a função pesquisarConta() passando número como parâmetro
    ~ em caso de dúvida olhar o arquivo pesquisarConta.c

    _a função pesquisarConta() retorna os dados da conta que estão em um arquivo CSV
    _chamar a função atribuindo ela a uma variável do tipo 'conta'
    Ex.: conta contaNova = pesquisarConta(numero)

    _criar sua lógica em cima, modificando os dados da struct 'conta' (número e nome do titular)
    _no final chamar a função salvarConta() passando a struct como parâmetro
    Ex.: salvarConta(contaNova)

    
qualquer dúvida pode me chamar no privado!
amanhã vamos precisar enviar todos os códigos pelo AVA

*/


// Estrutura para armazenar informações da conta
typedef struct {
    int numeroConta;
    char *nomeTitular;
    float saldo;
} ContaBancaria;

// Função para criar uma nova conta do usuario
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

    printf("Digite o saldo disponivel na conta: ");
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma conta bancária
typedef struct {
    char numero[20];
    char titular[100];
    double saldo;
} ContaBancaria;

// Função para consultar o saldo de uma conta
void consultarSaldoConta(const char *numConta) {
    char dirConta[100];

    // Construir o caminho do arquivo para a conta
    snprintf(dirConta,(sizeof(dirConta)/sizeof(dirConta[0])), "../contas/%s.csv", numConta);

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
    printf("\tTitular: %s\n", conta.titular);
    printf("\tSaldo total: R$ %.2lf\n", conta.saldo);

    fclose(arquivo);
}

// Função para validar se um número de conta é válido
int validarNumeroConta(const char *numConta) {

    return strlen(numConta) == 8;
}

// Função para mostrar o saldo de uma conta 
void MostrarSaldo() {
    char numConta[20];

    // Perguntar o número da conta e validar
    do {
        printf("Digite o numero da conta: ");
        scanf("%s", numConta);

        if (!validarNumeroConta(numConta)) {
            printf("Numero de conta invalido. Tente novamente.\n");
        }

    } while (!validarNumeroConta(numConta));

    // Chama a função para mostrar o saldo
    consultarSaldoConta(numConta);
}

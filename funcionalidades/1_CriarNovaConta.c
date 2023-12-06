#include <stdio.h>
#include <string.h>

typedef struct {
    char numeroConta[9];
    char titularConta[100];
    double saldoConta;
} cabeçalhoConta;

void criarConta() {
    cabeçalhoConta novaConta;

    printf("Digite o número da conta: ");
    scanf("%s", novaConta.numeroConta);

    printf("Digite o nome do titular: ");
    scanf("%s", novaConta.titularConta);

    novaConta.saldoConta = 0.0;

    printf("Saldo inicial: %.2lf\n", novaConta.saldoConta);
}




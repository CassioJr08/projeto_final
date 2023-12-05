#include <stdio.h>
#include <string.h>

typedef struct {
    char titular[50];
    int numeroConta;
    double saldo;
} ContaBancaria;

void mostrarSaldo(ContaBancaria contas[], int numContas) {
    int numeroConta;
    char nomeTitular[50];

    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    printf("Digite o nome do titular: ");
    scanf("%s", nomeTitular);

    int indiceConta = -1;
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta && strcmp(contas[i].titular, nomeTitular) == 0) {
            indiceConta = i;
            break;
        }
    }

    if (indiceConta != -1) {
        printf("Saldo da conta de %s: %.2f\n", contas[indiceConta].titular, contas[indiceConta].saldo);
    } else {
        printf("Conta nao encontrada.\n");
    }
}

int main() {
    ContaBancaria contas[100];
    int numContas = 0;
    int opcao;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("3. Mostrar saldo total de cada conta\n");
        printf("0. Sair\n");

        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 3:
                mostrarSaldo(contas, numContas);
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção invalida. Tente novamente!!!\n");
        }

    } while (opcao != 0);

    return 0;
}

#include <stdio.h>

typedef struct {
    char titular[50];
    char cpf[15];
    int numeroConta;
    float saldo;
} criarConta;

void mostrarSaldo(criarConta contas[], int numContas) {
    // Variável para armazenar o número da conta inserido pelo usuário
    int numeroConta;

    // Solicita ao usuário que insira o número da conta
    printf("Digite o numero da conta: ");
    
    // Adiciona verificação de entrada
    if (scanf("%4d", &numeroConta) != 1 || numeroConta < 1000 || numeroConta > 9999) {
        // Se a entrada não for um número de quatro dígitos, exibe mensagem de erro e encerra a função
        printf("Numero de conta invalido.\n");
        return;
    }

    // Variável para armazenar o índice da conta no array, inicializado como -1 (não encontrado)
    int indiceConta = -1;

    // Loop para percorrer o array de contas
    for (int i = 0; i < numContas; i++) {
        // Verifica se o número da conta na posição atual é igual ao número inserido pelo usuário
        if (contas[i].numeroConta == numeroConta) {
            // Se encontrado, armazena o índice e sai do loop
            indiceConta = i;
            break;
        }
    }

    // Verifica se a conta foi encontrada
    if (indiceConta != -1 && indiceConta < numContas) {
        // Imprime as informações da conta, incluindo titular, CPF, número da conta e saldo
        printf("Saldo da conta de %s (CPF: %s), numero da conta: %d: %.2f\n",
               contas[indiceConta].titular, contas[indiceConta].cpf,
               contas[indiceConta].numeroConta, contas[indiceConta].saldo);
    } else {
        printf("Conta com numero %d nao encontrada ou indice invalido.\n", numeroConta);
    }
}

int main() {
    criarConta contas[3] = {{"Titular1", "123.456.789-01", 1001, 1000.0},
                            {"Titular2", "987.654.321-01", 1002, 1500.0},
                            {"Titular3", "111.222.333-44", 1003, 2000.0}};

    mostrarSaldo(contas, 3);

    return 0;
}

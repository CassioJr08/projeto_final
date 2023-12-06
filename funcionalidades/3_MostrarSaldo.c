#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100
#define MAX_TAMANHO_NOME 50
#define MAX_TAMANHO_ARQUIVO 255

typedef struct {
    char titular[MAX_TAMANHO_NOME];
    int numeroConta;
    double saldo;
} ContaBancaria;

// Função para carregar contas a partir de um arquivo
int carregarContas(ContaBancaria contas[], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0; // Falha ao abrir o arquivo
    }

    int numContas = 0;
    while (fscanf(arquivo, "%d,%49[^,],%lf", &contas[numContas].numeroConta, contas[numContas].titular, &contas[numContas].saldo) == 3) {
        numContas++;
        if (numContas >= MAX_CONTAS) {
            break; // Evitar overflow no array contas
        }
    }

    fclose(arquivo);
    return numContas; // Retorna o número de contas carregadas
}

// Função para mostrar o saldo de uma conta específica
void mostrarSaldo(ContaBancaria contas[], int numContas) {
    int numeroConta;
    char nomeTitular[MAX_TAMANHO_NOME];

    // Entrada do número da conta
    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    // Verificação se o número da conta é válido
    if (numeroConta < 0 || numeroConta >= numContas) {
        printf("Numero da conta invalido.\n");
        return;
    }

    // Entrada do nome do titular 
    printf("Digite o nome do titular: ");
    getchar(); // Limpar o buffer do teclado antes de ler a string
    fgets(nomeTitular, sizeof(nomeTitular), stdin);

    // Remover o caractere de nova linha do final da string (se existir)
    nomeTitular[strcspn(nomeTitular, "\n")] = '\0';

    // Buscar a conta correspondente
    int indiceConta = -1;
    for (int i = 0; i < numContas; i++) {
        // Comparação sem diferenciar maiúsculas e minúsculas no nome do titular
        if (contas[i].numeroConta == numeroConta && strcasecmp(contas[i].titular, nomeTitular) == 0) {
            indiceConta = i;
            break;
        }
    }

    // Exibir saldo ou informar que a conta não foi encontrada
    if (indiceConta != -1) {
        printf("Saldo da conta de %s: %.2f\n", contas[indiceConta].titular, contas[indiceConta].saldo);
    } else {
        printf("Conta nao encontrada.\n");
    }
}

int main() {
    ContaBancaria contas[MAX_CONTAS];

    // Nome do arquivo CSV (altere para o nome do seu arquivo)
    const char *nomeArquivo = "./.csv";

    // Carregar as contas do arquivo
    int numContas = carregarContas(contas, nomeArquivo);

    // Verificar se houve falha ao carregar as contas
    if (numContas == 0) {
        return 1; // Código de erro
    }

    int opcao;

    do {
        // Menu principal
        printf("\nEscolha uma opcao:\n");
        printf("3. Mostrar saldo total de cada conta\n");
        printf("0. Sair\n");

        // Entrada da opção desejada
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);

        // Executar a opção escolhida
        switch (opcao) {
            case 3:
                mostrarSaldo(contas, numContas);
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente!!!\n");
        }

    } while (opcao != 0);

    return 0;
}

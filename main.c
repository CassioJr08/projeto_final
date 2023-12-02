//arquivos do compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
//arquivos do projeto
#include "./funcionalidades/1_CriarNovaConta.c"
#include "./funcionalidades/2_DepositoSaque.c"
#include "./funcionalidades/3_MostrarSaldo.c"
#include "./funcionalidades/4_EditarInformacoes.c"
#include "./funcionalidades/5_RemoverConta.c"
#include "./funcionalidades/6_TransferirValor.c"
#include "./funcionalidades/7_SalvarInformacoes.c"

int main() {

    setlocale(LC_ALL,"Portuguese");

    int opcao;

    // Exibe o menu
    printf("\nEscolha uma opcao:\n");
    printf("1. Criar nova conta\n");
    printf("2. Depositar e sacar dinheiro em uma conta\n");
    printf("3. Mostrar saldo total de cada conta\n");
    printf("4. Editar informacoes do titular de uma conta\n");
    printf("5. Remover conta\n");
    printf("6. Transferir valor de uma conta para outra\n");
    printf("7. Salvar informacoes de cada conta em um arquivo\n");
    printf("0. Sair\n");

    // Obtém a escolha do usuário
    printf("Digite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    // Executa a ação correspondente à escolha
    switch (opcao)
    {
    case 1:
        printf("Opcao 1 selecionada: Criar nova conta\n");
        criarConta();
        break;
    case 2:
        printf("Opcao 2 selecionada: Depositar e sacar dinheiro em uma conta\n");
        DepositoSaque();
        break;
    case 3:
        printf("Opcao 3 selecionada: Mostrar saldo total de cada conta\n");
        MostrarSaldo();
        break;
    case 4:
        printf("Opcao 4 selecionada: Editar informacoes do titular de uma conta\n");
        EditarInformacoes();
        break;
    case 5:
        printf("Opcao 5 selecionada: Remover conta\n");
        RemoverConta();
        break;
    case 6:
        printf("Opcao 6 selecionada: Transferir valor de uma conta para outra\n");
        TransferirValor();
        break;
    case 7:
        printf("Opcao 7 selecionada: Salvar informacoes de cada conta em um arquivo\n");
        SalvarInformacoes();
        break;
    case 0:
        printf("Saindo do programa. Obrigado!\n");
        break;
    default:
        printf("Opcao Invalida. Tente novamente!!!\n");
    }

    return 0;
}



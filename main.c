//cabeçalhos do compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//cabeçalhos do projeto
#include "./headers/conta.h"
//arquivos do projeto
#include "./funcionalidades/realocarContas.c"
#include "./funcionalidades/esperar.c"
#include "./funcionalidades/limparTela.c"
#include "./funcionalidades/contaExiste.c"
#include "./funcionalidades/pesquisarConta.c"
#include "./funcionalidades/salvarConta.c"
#include "./funcionalidades/1_CriarNovaConta.c"
#include "./funcionalidades/2_DepositoSaque.c"
#include "./funcionalidades/3_MostrarSaldo.c"
//#include "./funcionalidades/4_EditarInformacoes.c"
#include "./funcionalidades/5_RemoverConta.c"
#include "./funcionalidades/6_TransferirValor.c"

int main() {

    //VARIÁVEIS
    int opcao;

    do{
    //limpa o terminal
    //limparTela();
    //limparTela() não funciona corretamente em todos os compiladores
    // Exibe o menu
    printf("\nSISTEMA DE BANCO\n\n");
    printf("Escolha uma opcao:\n");
    printf("1. Criar nova conta\n");
    printf("2. Depositar e sacar dinheiro em uma conta\n");
    printf("3. Mostrar saldo total de uma conta\n");
    printf("4. Editar informacoes do titular de uma conta\n");
    printf("5. Remover conta\n");
    printf("6. Transferir valor de uma conta para outra\n");
    printf("0. Sair\n");

    // Obtém a escolha do usuário
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    // Executa a ação correspondente à escolha
    switch (opcao){
        case 1:
            printf("Opcao 1 selecionada: Criar nova conta\n");
            criarConta();
            esperar(5000);
            break;
        case 2:
            printf("Opcao 2 selecionada: Depositar e sacar dinheiro em uma conta\n");
            DepositoSaque();
            esperar(5000);
            break;
        case 3:
            printf("Opcao 3 selecionada: Mostrar saldo total de cada conta\n");
            MostrarSaldo();
            esperar(5000);
            break;
        case 4:
            printf("Opcao 4 selecionada: Editar informacoes do titular de uma conta\n");
            //EditarInformacoes();
            esperar(5000);
            break;
        case 5:
            printf("Opcao 5 selecionada: Remover conta\n");
            RemoverConta();
            esperar(5000);
            break;
        case 6:
            printf("Opcao 6 selecionada: Transferir valor de uma conta para outra\n");
            TransferirValor();
            break;
        case 0:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opcao Invalida. Tente novamente!!!\n");
    }
    }while(opcao!=0);

    return 0;
}



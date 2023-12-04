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
//#include "./funcionalidades/3_MostrarSaldo.c"
#include "./funcionalidades/4_EditarInformacoes.c"
#include "./funcionalidades/5_RemoverConta.c"
#include "./funcionalidades/6_TransferirValor.c"
#include "./funcionalidades/7_SalvarInformacoes.c"

int main() {

    //VARIÁVEIS
    int opcao;
    int qtdContas = 0; //quantidade de contas
    conta *contas = (conta*) calloc(qtdContas,sizeof(conta)); //vetor de contas


    //apenas ****teste****, pode retirar da versão final
    conta douglas = {"00891911","Douglas Souza de Lima",1559.9};
    realocarContas(&contas,&qtdContas);
    contas[qtdContas-1] = douglas;
    conta carolina = {"00980991","Carolina do Norte",3540.1};
    realocarContas(&contas,&qtdContas);
    contas[qtdContas-1] = carolina;
    conta adriel = {"67016100","Adriel da Cruz",2345.89};
    realocarContas(&contas,&qtdContas);
    contas[qtdContas-1] = adriel;
    int i = 0;
    while(i<3){
        printf("contas[%d] = {\"%s\",\"%s\",%.2f}\n",i,contas[i].numero,contas[i].titular,contas[i].saldo);
        i++;
    }
    printf("\n");
    //apenas ****teste****, pode retirar da versão final


    do{
    //limpa o terminal
    //limparTela();
    //limparTela() não funciona corretamente em todos os compiladores
    // Exibe o menu
    printf("\nSISTEMA DE BANCO\n\n");
    printf("Escolha uma opcao:\n");
    printf("1. Criar nova conta\n");
    printf("2. Depositar e sacar dinheiro em uma conta\n");
    printf("3. Mostrar saldo total de cada conta\n");
    printf("4. Editar informacoes do titular de uma conta\n");
    printf("5. Remover conta\n");
    printf("6. Transferir valor de uma conta para outra\n");
    printf("7. Salvar informacoes de cada conta em um arquivo\n");
    printf("0. Sair\n");

    // Obtém a escolha do usuário
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    // Executa a ação correspondente à escolha
    switch (opcao){
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
            //MostrarSaldo();
            // Verificar com a Kamila
            // O programa está dando erro na execução do MostrarSaldo()
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
            esperar(10000);
            break;
        case 7:
            printf("Opcao 7 selecionada: Salvar informacoes de cada conta em um arquivo\n");
            SalvarInformacoes(contas,qtdContas);
            esperar(10000);
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



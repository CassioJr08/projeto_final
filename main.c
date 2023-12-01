#include <stdio.h>

//1. Criar nova conta




//2. Depositar e sacar dinheiro em uma conta




//3. Mostrar saldo total de cada conta




//4. Editar informacoes do titular de uma conta




//5. Remover conta




//6. Transferir valor de uma conta para outra




//7. Salvar informacoes de cada conta em um arquivo




int main() {
    ContaBancaria contas[100];
    int numContas = 0;
    int opcao;

    do {
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
        switch (opcao) {
            case 1:
                printf("Opcao 1 selecionada: Criar nova conta\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 2:
                printf("Opcao 2 selecionada: Depositar e sacar dinheiro em uma conta\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 3:
                printf("Opcao 3 selecionada: Mostrar saldo total de cada conta\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 4:
                printf("Opcao 4 selecionada: Editar informacoes do titular de uma conta\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 5:
                printf("Opcao 5 selecionada: Remover conta\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 6:
                printf("Opcao 6 selecionada: Transferir valor de uma conta para outra\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 7:
                printf("Opcao 7 selecionada: Salvar informacoes de cada conta em um arquivo\n");
                //chamar a função da funcionalidade respectiva
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao Invalida. Tente novamente!!!\n");
        }

    } while (opcao != 0);

    return 0;
}

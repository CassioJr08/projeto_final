#include "../headers/conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void EditarInformacoes(){

    //Número da conta bancária
    char numeroConta[9];

    // Perguntar o número da conta e guardar na variável
    printf("\nDigite o numero da conta: ");
    scanf("%s",numeroConta);

    // Chamar a função contaExiste() passando o número como parâmetro
    if (contaExiste(numeroConta)) {

        // Chamar a função pesquisarConta() passando o número como parâmetro
        conta contaAtual = pesquisarConta(numeroConta);

        //exibe as informações atuais da conta
        printf("\nConta %s\n",contaAtual.numero);
        printf("\tTitular: %s\n",contaAtual.titular);
        printf("\tSaldo: R$ %.2lf\n",contaAtual.saldo);

        // Modificar os dados da struct 'conta'
        char novoNumeroConta[9];
        char novoNomeTitular[150];
        char confirma; //confirma a opção do usuário
        bool alterarNumero = false; //guarda a opção de alterar o número da conta
        char numeroAntigo[9];
        strcpy(numeroAntigo,contaAtual.numero); //guarda o número antigo da conta
        /*
        Douglas_
        Caso o usuário altere o número da conta, devemos renomear o arquivo CSV.
        */

        // Solicitar novas informações
        do{
            printf("\nGostaria de alterar o numero da conta? [S/N] ");
            scanf("\n%c",&confirma);
        }while(tolower(confirma) != 's' && tolower(confirma) != 'n');

        if(tolower(confirma) == 's'){
            printf("Digite o novo numero da conta: ");
            scanf("\n%s",novoNumeroConta);
            if(contaExiste(novoNumeroConta)){
                printf("\nErro: Ja existe uma conta com esse numero!\n");
                /*
                Douglas_
                Exibe a mensagem de erro e não deixa alterar o número.
                Contas diferentes não podem ter números iguais!
                */
            }else{
                strcpy(contaAtual.numero,novoNumeroConta);
                alterarNumero = true;
            }
        }

        do{
            printf("\nGostaria de alterar o nome do titular da conta? [S/N] ");
            scanf("\n%c",&confirma);
        }while(tolower(confirma) != 's' && tolower(confirma) != 'n');

        if(tolower(confirma) == 's'){
            printf("Digite o novo nome do titular: ");
            scanf("\n%[^\n]",novoNomeTitular);
            /*
            Douglas_
            Alterei o formato de "%s" para "[^\n]", pois antes não aceitava espaços brancos.
            */
            strcpy(contaAtual.titular, novoNomeTitular);
        }
        /*
        Douglas_
        1. Adicionei uma pergunta de confirmação para deixar o usuário alterar somente os dados desejados.
        2. Os loops while servem para evitar que o usuário responda as perguntas de forma errada.
        3. tolower(int c) converte o caractere para lower case, é a melhor opção quando validamos respostas de apenas 1 caractere (ex.: 'S' ou 'N', o usuário pode colocar 's' ou 'n')
        */

        //Se o usuário alterou o número da conta, renomeia o arquivo CSV
        if(alterarNumero){
            renomearConta(numeroAntigo,novoNumeroConta);
        }

        // Chamar a função salvarConta() passando a struct como parâmetro
        salvarConta(contaAtual);

        // Exibir informações atualizadas
        printf("\nConta %s - Titular: %s, Saldo: R$ %.2f\n", contaAtual.numero, contaAtual.titular, contaAtual.saldo);
        /*
        Douglas_
        Adicionei "R$" para ficar no formato monetário
        */
    } else {
        // A conta não existe, imprimir mensagem de erro e encerrar o programa
        printf("\nErro: A conta com o numero %s nao existe!\n",numeroConta);
        return;
        /*
        Douglas_
        Alterei "return 1" para "return", assim a função para de executar e volta para a main.
        */
    }
    /*
    Douglas_
    Retirei a função return 0, pois ela para a execução do programa na main.
    */
}

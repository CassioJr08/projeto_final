#include "../headers/conta.h"
// Atualizando a inclusão da biblioteca do projeto
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Aqui substitui a antiga struct pela função conta 
void criarConta() {
    conta novaConta;

    printf("\nDigite o numero da conta: ");
    scanf("%s", novaConta.numero);
    
    // adicionei a função "contaExiste" para verificar se a conta ja existe no sistema
    if (contaExiste(novaConta.numero)) {
        printf("\nErro: O numero da conta ja existe.\n");
    } else {
        printf("\nDigite o nome do titular: ");
        scanf("\n%[^\n]", novaConta.titular);
        
        // retirei a parte do saldo pois nao era necessária 

        // a função salvarConta lida com os arquivos para salvar as informações das novas contas 
        if(salvarConta(novaConta)){
            printf("\nConta criada com sucesso!\n");
        }else{
            printf("\nErro: Não foi possível criar a conta!\n");
        }
    }
}
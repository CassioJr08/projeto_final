
#include "../headers/conta.h"
// Atualizando a inclusão da biblioteca do projeto
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Aqui substitui a antiga struct pela função conta 
void criarConta() {
    conta novaConta;

    printf("Digite o numero da conta: ");
    scanf("%s", novaConta.numero);
    
// adicionei a função "contaExiste" para verificar se a conta ja existe no sistema
    if (contaExiste(novaConta.numero)) {
        printf("O numero da conta já existe.\n");
    } else {
        printf("Digite o nome do titular: ");
        scanf("%s", novaConta.titular);
        
// retirei a parte do saldo pois nao era necessária 
    
      printf("Conta criada com sucesso!\n");
    }
// a função salvarConta lida com os arquivos para salvar as informações das novas contas 
    salvarConta(novaConta);
}
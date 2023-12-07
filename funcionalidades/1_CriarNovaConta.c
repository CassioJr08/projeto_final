#include "../headers/conta.h"
// Atualizando a inclusão da biblioteca do projeto
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Aqui substitui a antiga struct pela função conta 
void criarConta() {
    conta novaConta;

    printf("Digite o número da conta: ");
    scanf("%s", novaConta.numero);
    
// adicionei "contaExiste" para verificar se a conta ja existe no sistema
    if (contaExiste(novaConta.numero)) {
        printf("O número da conta já existe.\n");
    } else {
        printf("Digite o nome do titular: ");
        scanf("%s", novaConta.titular);

        novaConta.saldo = 0.0;

      printf("Conta criada com sucesso.\n");
    }

    salvarConta(novaConta);
}
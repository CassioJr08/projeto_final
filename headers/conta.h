#ifndef CONTA_H //verifica se a definição CONTA_H existe
#define CONTA_H //caso NÃO exista cria a definição CONTA_H

// Estrutura para armazenar informações da conta
typedef struct conta{
    char numero[9]; //char armazena strings que começam com zero, int não faz o mesmo
    //na verdade o vetor número tem 8 espaços, o último espaço guarda o caractere '\0' (responsável por identificar o fim do vetor) 
    char titular[150]; //nome do titular
    double saldo;
} conta;

#endif
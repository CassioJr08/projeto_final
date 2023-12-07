//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

//Pesquisa o arquivo de dados (csv) da conta
conta pesquisarConta(char numConta[]){

    char dir[255]; //diretório do arquivo
    //cria o diretório
    strcpy(dir,"../contas/");
    strcat(dir,numConta);
    strcat(dir,".csv");

    //abre o arquivo no modo leitura
    FILE *arquivo = fopen(dir,"r");
    
    //faz a leitura dos dados do arquivo
    char dados[255]; //guarda a leitura dos dados
    fscanf(arquivo,"%[^\n]",dados);

    //guarda os dados na struct conta
    conta conta; //struct conta
    char *token; //guarda os tokens gerados pela função strtok
    char *endptr; //guarda a parte string da função strtod
    token = strtok(dados,",");
    strcpy(conta.numero,token);
    token = strtok(NULL,",");
    strcpy(conta.titular,token);
    token = strtok(NULL,",");
    conta.saldo = strtod(token,&endptr);

    //fecha o arquivo
    fclose(arquivo);

    return conta;
}
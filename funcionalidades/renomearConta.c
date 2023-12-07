//cabeçalhos do compilador
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//cabeçalhos do projeto
#include "../headers/conta.h"

//Renomeia o arquivo CSV da conta
bool renomearConta(char nomeAntigo[],char nomeNovo[]){

    char dirAntigo[255]; //diretório do arquivo antigo
    //cria o diretório
    strcpy(dirAntigo,"../contas/");
    strcat(dirAntigo,nomeAntigo);
    strcat(dirAntigo,".csv");

    char dirNovo[255]; //diretório do arquivo novo
    //cria o diretório
    strcpy(dirNovo,"../contas/");
    strcat(dirNovo,nomeNovo);
    strcat(dirNovo,".csv");

    int retorno;
    retorno = rename(dirAntigo,dirNovo); //renomeia o arquivo

    //caso o resultado não seja 0 (sucesso), a função retorna false
    if(retorno != 0){
        return false;
    }
    
    return true;
}
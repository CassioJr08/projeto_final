//cabeçalhos do compilador
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
//cabeçalhos do projeto
#include "../../headers/conta.h"

//Verifica se a conta existe, caso não exista retorna false
bool contaExiste(char numConta[]){

    char dir[255]; //diretório do arquivo
    //cria o diretório
    strcpy(dir,"../contas/");
    strcat(dir,numConta);
    strcat(dir,".csv");

    if(access(dir,F_OK) == 0){
        return true;
    }else{
        return false;
    }
}

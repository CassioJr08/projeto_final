//cabeçalhos do compilador
#include <stdio.h>
#include <stdbool.h>
//cabeçalhos do projeto
#include "../../headers/conta.h"

//Salva os dados da conta em um arquivo CSV
bool salvarConta(conta conta){

    char dir[255]; //diretório do arquivo
    //cria o diretório
    strcpy(dir,"../contas/");
    strcat(dir,conta.numero);
    strcat(dir,".csv");

    FILE *arquivo; //ponteiro para o arquivo

    //abre o arquivo no modo de escrita
    arquivo = fopen(dir,"w");

    if(arquivo == NULL){
        return false;
    }

    //salva dados no arquivo 
    fprintf(arquivo,"%s,%s,%.2lf",conta.numero,conta.titular,conta.saldo);

    //fecha o arquivo
    fclose(arquivo);

    return true;
}
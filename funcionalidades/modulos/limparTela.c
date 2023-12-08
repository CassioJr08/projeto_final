#include <stdlib.h>

//Limpa o terminal
void limparTela(){
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}
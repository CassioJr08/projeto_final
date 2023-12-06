#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

//Para a execução do programa durante um tempo (milissecundos)
void esperar(int ms){
    #ifdef __linux__
        usleep(ms*1000);
    #elif _WIN32
        Sleep(ms);
    #endif
}
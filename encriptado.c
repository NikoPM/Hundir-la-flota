#include "modulos/encriptado.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* encriptar(char* contrasenha)
{
    int size = strlen(contrasenha);
    char* encriptado =(char*)malloc(sizeof(char) * size);
    char letra;
    for (int i = 0; i < size; i++)
    {
        letra = contrasenha[i];
        letra +=3;
        encriptado[i] = letra;
    }
    
    return encriptado;
}

char* desencriptar(char* contrasenha)
{
    int size = strlen(contrasenha);
    char* desencriptado =(char*)malloc(sizeof(char) * size);
    char letra;
    for (int i = 0; i < size; i++)
    {
        letra = contrasenha[i];
        letra -=3;
        desencriptado[i] = letra;
    }
    
    return desencriptado;
}
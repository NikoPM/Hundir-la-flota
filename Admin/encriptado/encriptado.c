#include "encriptado.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void encriptar(char* contrasenha)
{
    int size = strlen(contrasenha);
    for (int i = 0; i < size; i++)
    {
        contrasenha[i] += 3;
    }
}

void desencriptar(char* contrasenha)
{
    int size = strlen(contrasenha);
    for (int i = 0; i < size; i++)
    {
        contrasenha[i] -= 3;
    }
}
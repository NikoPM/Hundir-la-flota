#include <stdio.h>

#include "Usuario/usuario.h"
#include "Barco/barco.h"

void menu() {
    printf("\n1. Registrar Usuario.\n2. Iniciar Sesion.\n3. Salir.\n");
}

void opciones(char c) {
    if(c == '1') {
        registrar();
    } else if(c == '2') {
        if(iniSesion() == 1) {
		printf("\nJuego: \n");
		Casilla c[100];
		generarTablero(c);
		printTablero(c);
	  } else {
		printf("Usuario o Contrasena Incorrectos\n");
	  }
    } else if(c == 'd') {
	  vaciar();
    }
}

int main(void) {
    char str[10];
    char c;
    do {
        menu();
        fgets(str, 10, stdin);
        sscanf(str, "%c", &c);
        fflush(stdin);
        fflush(stdout);
        opciones(c);
    } while(c != '3');
    return 0;
}
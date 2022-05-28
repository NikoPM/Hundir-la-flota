#include <stdio.h>

#include "Usuario/usuario.h"
#include "Barco/barco.h"
#include "BBDD/bbdd.h"
#include "BBDD/sqlite3.h"
#include "Logger/logger.h"

#define DATABASE 1

void menu() {
    printf("\n1. Registrar Usuario.\n2. Iniciar Sesion.\n3. Salir.\n");
}

void opciones(char c) {
    if(c == '1') {
        registrar();
        loggear("Usuario Registrado con exito\n");
    } else if(c == '2') {
        if(iniSesion() == 0) {
            loggear("Inicio Sesion exitoso\n");
		    printf("\nJuego: \n");
		    Casilla c[100];
		    generarTablero(c);
            pedirBarcos();
		    printTablero(c);
            Barco bJ[3];
            generarBarcos(bJ);
            loggear("Partida Iniciada\n");
            partida(bJ, c);
            loggear("Partida Finalizada\n");
	    } else {
	        printf("Usuario o Contrasena Incorrectos\n");
            loggear("Inicio Sesion fallido\n");
	    }
    } else if(c == 'v') {
	    mostrarData();
        loggear("Mostrado Datos de la base\n");
    }
}

int main(void) {
    if(DATABASE == 1) {
	    crearTablas();
    }
    char str[10];
    char c;
    iniciarLogger();
    do {
        menu();
        fgets(str, 10, stdin);
        sscanf(str, "%c", &c);
        fflush(stdin);
        fflush(stdout);
        opciones(c);
    } while(c != '3');
    loggear("Programa cerrado\n\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "barco.h"

void generarTablero(Casilla c[100]) {
	
	int cont = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(i == 0) {
				c[cont].letra = 'A';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 1) {
				c[cont].letra = 'B';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 2) {
				c[cont].letra = 'C';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 3) {
				c[cont].letra = 'D';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 4) {
				c[cont].letra = 'E';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 5) {
				c[cont].letra = 'F';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 6) {
				c[cont].letra = 'G';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 7) {
				c[cont].letra = 'H';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 8) {
				c[cont].letra = 'I';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			} else if(i == 9) {
				c[cont].letra = 'J';
				c[cont].num = j + 1;
				c[cont++].estado = 0;
			}
		}
	}
}

void printCasilla(Casilla c) {
	if(c.estado == 0) {
		printf("~");
	} else if(c.estado < 0) {
		printf("x");
	} else {
		printf("o");
	}
}

void printTablero(Casilla c[100]) {
	int cont = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			printCasilla(c[cont++]);
			printf(" ");
		}
		printf("\n");
	}
}

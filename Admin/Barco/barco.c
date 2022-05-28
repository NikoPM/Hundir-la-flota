#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void pedirBarcos() {
	char str[MAX_LINEAS];
	for (int i = 0; i < 9; i++) {
		printf("Letra (A-J):\n");
		fgets(str, MAX_LINEAS, stdin);
		fflush(stdin);
		fflush(stdout);
		printf("Numero (1-10):\n");
		fgets(str, MAX_LINEAS, stdin);
		fflush(stdin);
		fflush(stdout);
	}
}

void generarBarcos(Barco b[3]) {
	int fil = 64;
	int col = 0;
	Casilla casArr[9];
	Casilla cas;
	int num = 0;
	srand(time(0));
	int randNum = (rand() % (4 - 1 + 1)) + 1;
	//printf("Rand: %i\n", randNum);
	FILE* f = fopen("../Tableros.txt", "r");
	char c;
	while ((c = fgetc(f)) != EOF) {
		if (c == randNum + '0') {
			while (c != (randNum + 1) + '0') {
				if (c == '~' || c == 'x') {
					col += 1;
					if (col > 10) {
						col = 1;
					}
					if (c == 'x') {
						cas.letra = fil;
						cas.num = col;
						cas.estado = 0;
						casArr[num++] = cas;
					}
				}
				else if (c == '\n') {
					fil += 1;
				}
				c = fgetc(f);
			}
		}
		c = fgetc(f);
	}
	fclose(f);
	num = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i].piezas[j] = casArr[num++];
			b[i].size = 3;
			b[i].estado = 0;
			//printf("C%i: %c, %i\n", num, b[i].piezas[j].letra, b[i].piezas[j].num);
		}
	}
}


void partida(Barco b[3], Casilla c[100]) {
	int intentos = 25;
	while(((b[1].estado + b[0].estado + b[2].estado) != 3) && intentos > 0) {
		intentos -= 1;
		int boo = 0;
		char str[MAX_LINEAS];
    	char letra;
    	int num;
		printf("\nSelecciona una casilla para disparar\n");
		printf("Letra (A-J):\n");
    	fgets(str, MAX_LINEAS, stdin);
    	sscanf(str, "%c", &letra);
    	fflush(stdin);
    	fflush(stdout);
    	printf("Numero (1-10):\n");
    	fgets(str, MAX_LINEAS, stdin);
    	sscanf(str, "%i", &num);
   		fflush(stdin);
    	fflush(stdout);
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(b[i].piezas[j].letra == letra && b[i].piezas[j].num == num) {
					b[i].piezas[j].estado = -1;
					boo = 1;
				}
			}
			if((b[i].piezas[0].estado + b[i].piezas[1].estado + b[i].piezas[2].estado) == -3) {
				b[i].estado = 1;
			}
		}
		for(int i = 0; i < 100; i++) {
			if(c[i].letra == letra && c[i].num == num) {
				if(boo == 1) {
					c[i].estado = -1;
				} else {
					c[i].estado = 1;
				}
			}
		}
		printTablero(c);
	}
	printf("Fin de Partida\n");
}
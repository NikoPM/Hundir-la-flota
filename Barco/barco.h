#ifndef BARCO_H_
#define BARCO_H_

#define MAX_LINEAS 15

typedef struct {
	char letra;
	int num;
	int estado;
} Casilla;

typedef struct {
	Casilla piezas[3];
	int size;
	int estado;
} Barco;

void generarTablero(Casilla c[100]);
void printCasilla(Casilla c);
void printTablero(Casilla c[100]);

#endif
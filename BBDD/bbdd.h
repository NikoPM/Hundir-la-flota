#ifndef BBDD_H_
#define BBDD_H_

#include "sqlite3.h"

int crearTablas();
int insertarData(char* nom, char* pass);
int llamada(void *, int, char **, char **);
int mostrarData();

#endif
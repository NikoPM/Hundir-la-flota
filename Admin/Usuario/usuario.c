#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "usuario.h"
#include "../Encriptado/encriptado.h"
#include "../BBDD/bbdd.h"
#include "../BBDD/sqlite3.h"

void insertDataUser(char* c1, char* c2) {
    char str[MAX_LINEAS];
    char nom[MAX_LINEAS];
    char pass[MAX_LINEAS];
    printf("Nombre Usuario:\n");
    fgets(str, MAX_LINEAS, stdin);
    sscanf(str, "%s", nom);
    fflush(stdin);
    fflush(stdout);
    printf("Contrasena Usuario:\n");
    fgets(str, MAX_LINEAS, stdin);
    sscanf(str, "%s", pass);
    fflush(stdin);
    fflush(stdout);
    strcpy(c1, nom);
    strcpy(c2, pass);
}

void registrar() {
    char nom[MAX_LINEAS];
    char pass[MAX_LINEAS];
    insertDataUser(nom, pass);
    encriptar(pass);
    insertarData(nom, pass);
}

int iniSesion() {
  int res;
  char nom[MAX_LINEAS];
  char pass[MAX_LINEAS];
  insertDataUser(nom, pass);
  if(strcmp("ComandoJuego", pass) == 0) {
  	return 1;
  }
  encriptar(pass);
  res = checkPass(nom, pass);
  return res;
}
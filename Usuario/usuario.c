#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "usuario.h"

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
    FILE* f = fopen("Usuarios.txt", "a");
    fprintf(f, "@%s\n", nom);
    fprintf(f, "?%s\n", pass);
    fclose(f);
}

void vaciar() {
    FILE* f = fopen("Usuarios.txt", "w");
    fclose(f);
}

int iniSesion() {
  int res = 0;
  FILE* f = fopen("Usuarios.txt", "r");
  char nom[MAX_LINEAS];
  char checkNom[MAX_LINEAS];
  char pass[MAX_LINEAS];
  char checkPass[MAX_LINEAS];
  insertDataUser(checkNom, checkPass);
  if(strcmp("ComandoJuego", checkPass) == 0) {
  	return 1;
  }
  char c;
  int cont = 0;
  while((c = fgetc(f)) != EOF) {
    if(c == '@') {
	cont = 0;
	do {
		c = fgetc(f);
		if(c != '\n' && c != '@' && c != '?' && c != '\0') {
			nom[cont++] = c;
		}
	} while(c != '\n');
     } else if(c == '?') {
	cont = 0;
	do {
		c = fgetc(f);
		if(c != '\n' && c != '@' && c != '?' && c != '\0') {
			pass[cont++] = c;
		}
	} while(c != '\n');
     }
	 if((strcmp(nom, checkNom) + strcmp(pass, checkPass)) == 0) {
		  res = 1;
		  //printf("si\n");
		  break;
  	}
  }
  fclose(f);
  return res;
}
#ifndef LISTACORREOS_H
#define LISTACORREOS_H

#include <iostream>
#include <string>
#include <fstream>
#include "correo.h"
using namespace std;

const int MAX_CORREOS = 100;
typedef tCorreo tArrCorreo[MAX_CORREOS];

typedef struct {
	tArrCorreo correo;
	int cont;
} tListaCorreos;

inline void iniciar (tListaCorreos &correos){ correos.cont= 0; }
inline int longitud (const tListaCorreos &correos){ return correos.cont; }
void guardar (const tListaCorreos &correos, const string &nombre);
bool cargar (tListaCorreos &correos, const string &nombre);
bool insertar (tListaCorreos &correos, const tCorreo &correo);
bool buscar (const tListaCorreos &correos, const string &idMail, int &pos);
bool eliminar (tListaCorreos &correos, const string &idMail);

//Funciones auxiliares:
bool eliminar (tListaCorreos &list, int pos);

#endif
#ifndef SESION_H
#define SESION_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "gestor.h"
#include "usuario.h"
#include "utilsWin.h"
using namespace std;

typedef struct {
	tGestor * gestor;
	tUsuario * usuario;
} tSesion;

typedef tCorreo * puntCorreos[MAX_CORREOS];
typedef struct {
	puntCorreos arrCorreos;
	int cont;
} tPuntCorreos;

bool iniciarSesion (tSesion &sesion, tGestor * gestor, tUsuario * usuario);

//Opciones del menú:
void leerCorreo (tSesion &sesion);
void enviarCorreo (tSesion &sesion);
void borrarCorreo (tSesion &sesion);
void lecturaRapida (tSesion &sesion);

//Funciones auxiliares:
int menuBandeja(tSesion &sesion);
void encabezadoBandeja(tSesion &sesion);
void ordenarSeleccion(tPuntCorreos &correos, int longitud);
string ignorarREyFW(tCorreo &correo);

#endif
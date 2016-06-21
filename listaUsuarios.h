#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include "usuario.h"
const int MAX_USUARIOS = 100;
typedef tUsuario tArrUsuarios[MAX_USUARIOS - 1]; //No sé si había que hacerlo como en la listaCorreos

typedef struct {
	tArrUsuarios usuario;
	int cont;
} tListaUsuarios;


inline void iniciar (tListaUsuarios & usuarios){ usuarios.cont = 0; }
inline bool llena (const tListaUsuarios &usuarios){ return usuarios.cont == MAX_USUARIOS; }
inline int longitud (const tListaUsuarios &usuarios){ return usuarios.cont; }
bool cargar (tListaUsuarios &usuarios, const string &nombre);
void guardar (const tListaUsuarios &usuarios, const string &nombre);
bool insertar (tListaUsuarios &usuarios, const tUsuario &usuario);
bool buscar (const tListaUsuarios &usuarios, const string &idUser, int &posicion);

#endif
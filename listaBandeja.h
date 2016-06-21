#ifndef LISTABANDEJA_H
#define LISTABANDEJA_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct {
	string identificador;
	bool leido;
} tElemBandeja;

const int MAX_ELEMS = 100;
typedef tElemBandeja tArrBandeja[MAX_ELEMS - 1]; //No sé si había que hacerlo como en la listaCorreos

typedef struct {
	tArrBandeja correo;
	int cont;
} tListaBandeja;

inline void inicializar (tListaBandeja &listElems){ listElems.cont = 0; }
inline bool llena (const tListaBandeja &listElems){ return listElems.cont == MAX_ELEMS; }
inline int longitud(const tListaBandeja & listElems){ return listElems.cont; }
void guardar (const tListaBandeja &listElems, ofstream &archivo);
void cargar (tListaBandeja &listElems, ifstream &archivo);
bool insertar (tListaBandeja &listElems, const tElemBandeja &elem);
int buscar (const tListaBandeja &listElems, const string &idMail);
bool eliminar (tListaBandeja &listElems, const string &idMail);
bool correoLeido (tListaBandeja &listElems, const string &idMail);

#endif
#include "listaBandeja.h"

void guardar (const tListaBandeja &listElems, ofstream &archivo) {
	archivo << listElems.cont << endl;

	for (int i = 0; i < listElems.cont; i++) {
		archivo << listElems.correo[i].identificador << " ";
		if (listElems.correo[i].leido)
			archivo << 1 << endl;
		else
			archivo << 0 << endl;
	}
}

void cargar (tListaBandeja &listElems, ifstream &archivo) {
	int cont, leido;
	string correo;

	archivo >>  cont;

	listElems.cont = cont;

	for (int i = 0; i < cont; i++) {
		archivo >> correo >> leido;
		listElems.correo[i].identificador = correo;
		if (leido == 1)
			listElems.correo[i].leido = true;
		else
			listElems.correo[i].leido = false;
	}
}

bool insertar (tListaBandeja &listElems, const tElemBandeja &elem) {
	bool inserCorrecta = false;

	if (!llena(listElems)) {
		listElems.correo[listElems.cont].identificador = elem.identificador;
		listElems.correo[listElems.cont].leido = elem.leido;
		listElems.cont++;

		inserCorrecta = true;
	}

	return inserCorrecta;
}

int buscar (const tListaBandeja &listElems, const string &idMail) {
	int posicion;
	bool encontrado = false;
	int ini = 0;
	int fin = listElems.cont;
	int mitad = (ini + fin) / 2;
	
	while (ini < fin && encontrado == false) {
		if (idMail < listElems.correo[mitad].identificador)
			fin = mitad;
		else if (idMail > listElems.correo[mitad].identificador)
			ini = mitad + 1;
		else
			encontrado = true;

		mitad = (ini + fin) / 2;
	} 

	if (encontrado == true)
		posicion = mitad;
	else posicion = -1;

	return posicion;
}

bool eliminar (tListaBandeja &listElems, const string &idMail) {
	bool eliminado = false;
	int posicion;

	posicion = buscar(listElems, idMail);

	if (posicion != -1) {
		for (int i = posicion; i < listElems.cont - 1; i++)
			listElems.correo[i] = listElems.correo[i + 1];
		listElems.cont--;
		eliminado = true;
	}

	return eliminado;
}

bool correoLeido (tListaBandeja &listElems, const string &idMail) {
	bool encontrado = false;
	int cont = 0;

	while (cont < listElems.cont && !encontrado) {
		if (listElems.correo[cont].identificador == idMail) {
			listElems.correo[cont].leido = true;
			encontrado = true;
		}

		cont++;
	}

	return encontrado;
}
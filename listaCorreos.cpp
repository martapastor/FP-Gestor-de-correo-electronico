#include "correo.h"
#include "listaCorreos.h"

void guardar (const tListaCorreos &correos, const string &nombre) {
	ofstream fichero;
	string nombreFichero = nombre + "_correos.txt";
	fichero.open(nombreFichero);

	if (fichero.is_open()) {
		for (int i = 0; i < correos.cont; i++) {
			guardar(correos.correo[i], fichero);
		}

		fichero << "XXX";
	}

	fichero.close();
}

bool cargar (tListaCorreos &correos, const string &nombre) {
	ifstream fichero;
	string nombreFichero = nombre + "_correos.txt";
	fichero.open(nombreFichero);
	bool cargaCorrecta = true;
	correos.cont = 0;

	if (fichero.is_open()) {
		for (int i = 0; i < MAX_CORREOS && cargaCorrecta; i++) {
			cargaCorrecta = cargar(correos.correo[i], fichero);
			if (cargaCorrecta) correos.cont++;
		}
		cargaCorrecta = true;
	}

	fichero.close();

	return cargaCorrecta;
}

bool insertar (tListaCorreos &correos, const tCorreo &correo) {
	bool inserCorrecta = false;
	int pos, cont = correos.cont;

	if (correos.cont < MAX_CORREOS) {
		if (!buscar(correos, correo.id_correo, pos))  {
			for (int i = cont; pos < i; i--)
				correos.correo[i] = correos.correo[i - 1];
			correos.correo[pos] = correo;
			correos.cont++;
			inserCorrecta = true;
		}
	}

	return inserCorrecta;
}

bool buscar (const tListaCorreos &correos, const string &idMail, int &pos) {
	bool encontrado = false;
	int ini = 0;
	int fin = correos.cont;
	int mitad = (ini + fin) / 2;

	while (ini < fin && !encontrado) {
		if (idMail < correos.correo[mitad].id_correo)
			fin = mitad;
		else if (idMail > correos.correo[mitad].id_correo)
			ini = mitad + 1;
		else
			encontrado = true;

		mitad = (ini + fin) / 2;
	} 

	//Tanto si encontrado como si !encontrado, devolver la pos en la que iría
	pos = mitad;

	return encontrado;
}

bool eliminar (tListaCorreos &correos, const string &idMail) {
	bool eliminado = false;
	bool encontrado;
	int pos;

	encontrado = buscar(correos, idMail, pos);

	if (encontrado) 
		eliminado = eliminar(correos, pos);

	return eliminado;
}

//Funciones auxiliares:

bool eliminar (tListaCorreos &list, int pos) {
	for (int i = pos; i < list.cont - 1; i++)
			list.correo[i] = list.correo[i + 1];
		list.cont--;

	return true;
}
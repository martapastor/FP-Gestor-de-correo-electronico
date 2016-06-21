#include "usuario.h"
#include "listaUsuarios.h"

bool cargar (tListaUsuarios &usuarios, const string &nombre) {
	ifstream fichero;
	string nombreFichero = nombre + "_usuarios.txt";
	fichero.open(nombreFichero);
	bool cargaCorrecta = true;
	usuarios.cont = 0;

	if (fichero.is_open()) {
		for (int i = 0; i < MAX_USUARIOS && cargaCorrecta; i++) {
			cargaCorrecta = cargar(usuarios.usuario[i], fichero);
			if (cargaCorrecta) usuarios.cont++;
		}
		cargaCorrecta = true;
	}

	fichero.close();

	return cargaCorrecta;
}

void guardar (const tListaUsuarios &usuarios, const string &nombre) {
	ofstream fichero;
	string nombreFichero = nombre + "_usuarios.txt";
	fichero.open(nombreFichero);

	if (fichero.is_open()) {
		for (int i = 0; i < usuarios.cont; i++) {
			guardar(usuarios.usuario[i], fichero);
		}

		fichero << "XXX";
	}

	fichero.close();
}

bool insertar (tListaUsuarios &usuarios, const tUsuario &usuario) {
	bool inserCorrecta = false;
	int pos, cont = usuarios.cont;

	if (usuarios.cont < MAX_USUARIOS) {
		if (!buscar(usuarios, usuario.identificador, pos)) {
			for (int i = cont; pos < i; i--)
				usuarios.usuario[i] = usuarios.usuario[i - 1];
			usuarios.usuario[pos] = usuario;
			usuarios.cont++;
			inserCorrecta = true;
		}
	}

	return inserCorrecta;
}

bool buscar (const tListaUsuarios &usuarios, const string &idUser, int &posicion) {
	bool encontrado = false;
	int ini = 0;
	int fin = usuarios.cont;
	int mitad = (ini + fin) / 2;

	while (ini < fin && !encontrado) {
		if (idUser < usuarios.usuario[mitad].identificador)
			fin = mitad;
		else if (idUser > usuarios.usuario[mitad].identificador)
			ini = mitad + 1;
		else
			encontrado = true;

		mitad = (ini + fin) / 2;
	} 

	//Tanto si encontrado como si !encontrado, devolver la pos en la que iría
	posicion = mitad;
	
	return encontrado;
}
#include "listaBandeja.h"
#include "usuario.h"


void iniciar (tUsuario &usuario, const string &idUser, const string &contrasenia) {
	usuario.identificador = idUser;
	usuario.password = contrasenia;
	usuario.bandeja = true; //Entrada -> true
	inicializar(usuario.listaMnsjRecibidos);
	inicializar(usuario.listaMnsjEnviados);
}

void guardar (const tUsuario &usuario, ofstream &archivo) {
	archivo << usuario.identificador << endl;
	archivo << usuario.password << endl;

	guardar(usuario.listaMnsjRecibidos, archivo);
	guardar(usuario.listaMnsjEnviados, archivo);
}

bool cargar (tUsuario &usuario, ifstream &archivo) {
	bool cargaCorrecta = false;

	string idUser, pass;
	tListaBandeja listaElems;
	archivo >> idUser;
	archivo >> pass;

	if (idUser != "XXX") {
		usuario.identificador = idUser;
		usuario.password = pass;

		cargar(listaElems, archivo);
		usuario.listaMnsjRecibidos.cont = listaElems.cont;
		for (int i = 0; i < usuario.listaMnsjRecibidos.cont; i++) {
			usuario.listaMnsjRecibidos.correo[i].identificador = listaElems.correo[i].identificador;
			usuario.listaMnsjRecibidos.correo[i].leido = listaElems.correo[i].leido;
		}

		cargar(listaElems, archivo);
		usuario.listaMnsjEnviados.cont = listaElems.cont;
		for (int i = 0; i < usuario.listaMnsjEnviados.cont; i++) {
			usuario.listaMnsjEnviados.correo[i].identificador = listaElems.correo[i].identificador;
			usuario.listaMnsjEnviados.correo[i].leido = listaElems.correo[i].leido;
		}

		cargaCorrecta = true;
	}

	return cargaCorrecta;
}

bool validarContrasenia (const tUsuario &usuario, const string &contrasenia) {
	return usuario.password == contrasenia;
}

void cambiarBandeja (tUsuario &usuario) {
	if (usuario.bandeja) usuario.bandeja = false;
	else usuario.bandeja = true;
}
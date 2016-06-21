bool usuarioCorrecto (const string &nombreUsuario, const string &dominio) {
	bool correcto = false;
	char c;
	string tmpDominio;

	istringstream flujo(nombreUsuario);

	while (flujo >> c && c != '@') {
		flujo >> c;
	}

	flujo >> tmpDominio;

	if ("@" + tmpDominio == dominio)
		correcto = true;

	return correcto;
}

bool contraseniaCorrecta (const string &contrasenia, const string &contrasenia2) {
	bool correcta = false;

	if (contrasenia == contrasenia2)
		correcta = true;

	return correcta;
}

/*
IMPORTANTE: es necesario incluir la biblioteca <conio.h> en el archivo de encabezado .h pertinente.
El funcionamiento de esta función es muy sencillo.
Inicializamos el string pass como vacío.
Con la función _getch(), lo que hace es guardar el caracter que introducimos en pantalla, pero no lo escribe.
Con la función pass.push_back(c), lo que hacemos es guardar en el string pass el caracter que acabamos de leer del teclado.
Depués, en pantalla nos muestra '*' (podemos hacer que nos muestre el símbolo que nosotros queramos).
Mientras no pulsemos el Intro, la consola va a seguir leyendo caracteres del teclado.
Al final, nos devuelve un string que es la contraseña completa.
*/

string noMostrarContrasenia() { //ATENCIÓN: esta función sólo sirve para consola MS-DOS/Windows
	string pass = "";
	char c;
	c = _getch();
	
	while (c != 13) { //No funciona si ponemos '\n', y el Intro corresponde al número de caracter 13
      pass.push_back(c);
      cout << '*';
      c = _getch();
   }

	return pass;
}

//Cómo llamar a la función noMostrarContrasenia en la parte de código de sesion.cpp:
tUsuario * crearCuenta (tGestor &gestor) {
[...]

cout << "Nombre de usuario: ";
	cin >> nombreUsuario;

	//No nos muestra la contraseña en pantalla cuando la escribimos, aunque sí nos la guarda en los string password y password2:
	cout << "Contraseña: ";
	password = noMostrarContrasenia();
	cout << "\nVuelve a escribir la contraseña: ";
	password2 = noMostrarContrasenia();

[...]
}
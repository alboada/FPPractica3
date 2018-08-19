
// >> << <>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Header.h"
using namespace std;




void colorFondo(int	color) {
	HANDLE	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}


int elegirColor(const tCasilla casilla) {
	int fondo;
	switch (casilla.estado) {

	case VACIA: fondo = 15;
		break;
	case HIELO: fondo = 3;
		break;
	case MURO: fondo = 5;
		break;
	case JOYA: fondo = 7;
		break;
	case TORTUGA:
		fondo = elegirColorJugadores (casilla.tortuga.numero);
		break;
	case CAJA: fondo = 12;
		break;
	}
	return fondo;

}

int elegirColorJugadores (int numJugador){

int fondo;
	switch (numJugador) {

	case 0: fondo = 5;
		break;
	case 1: fondo = 13;
		break;
	case 2: fondo = 9;
		break;
	case 3: fondo = 10;
		break;
	}
	return fondo;


}


string nombreFichero() {
	string nombre_fich;
	cout << "¿Cual es el nombre del fichero?";
	cin >> nombre_fich; 
	cin.sync();

	return nombre_fich;
}

int numeroJug() {

	int numero;

	cout << "Cuantos jugadores juegan:";
	cin >> numero;

	return numero;

}


tEstadoCasilla charAtCasilla(char b) {//D,C,L,U,R,#,@,$, " "

tCasilla devuelto;

	switch (b) {
		case 'C': devuelto.estado = CAJA;
	break;
		case 'D': devuelto.estado = TORTUGA;
		juego.tablero[i][j].tortuga.direccion = SUR;
	break;
		case 'U': devuelto.estado = TORTUGA;
		juego.tablero[i][j].tortuga.direccion = NORTE;
	break;
		case 'L': devuelto.estado = TORTUGA;
		juego.tablero[i][j].tortuga.direccion = OESTE;
	break;
		case 'R': devuelto.estado = TORTUGA;
		juego.tablero[i][j].tortuga.direccion = ESTE;
	break;
		case '#': devuelto.estado = MURO;
	break;
		case '@': devuelto.estado = HIELO;
	break;
		case '*': devuelto.estado = VACIA;
	break;
		case '$': devuelto.estado = JOYA;
	break;
	}
return devuelto.estado;
}


tDir charatDir(char b) {
	tDir devuelto;
	switch (b) {
	case 'D': devuelto = SUR;
		break;
	case 'R': devuelto = ESTE;
		break;
	case 'U': devuelto = NORTE;
		break;
	case 'L': devuelto = OESTE;
	}
	return devuelto;
}


string tCasillaAString2(tCasilla aux) {
	string c;
	switch (aux.tortuga.direccion) {
	case NORTE: c = "^^";
		break;
	case SUR: c = "vv";
		break;
	case ESTE: c = ">>";
		break;
	case OESTE: c = "<<";
		break;
	}
	return c;
}


string tCasillaAString(tCasilla aux) {

	string c;
	switch (aux.estado) {
		case TORTUGA: c = tCasillaAString2(aux);
	break;
		case CAJA: c = "[]";
	break;
		case HIELO: c = "**";
	break;
		case VACIA: c = "  ";
	break;
		case MURO: c = "||";
	break;
		case JOYA: c = "00";
	break
	}

return c;
}


void cargarJuego(tJuego& juego) {

	string nombre_fich;
	char caracter;
	int fondo, hola, jug;
	string c, linea;
	tCasilla aux;
	ifstream fich;
	nombre_fich = nombreFichero();
	juego.num_jugadores = numeroJug();

	fich.open(nombre_fich);
	if (!fich.is_open()) {

		cout << "El fichero no ha podido abrirse correctamente.";
	}
	else {
		fich >> jug;

		while (jug != juego.num_jugadores) {
		for (int k = 0; k < NUM_FILAS; k++){
			for(int l = 0; l < NUM_FILAS; l++){
				fich >> caracter;
			}
		}
		fich >> jug;
		}
		
		if(!leerTablero(juego)){
			cout << "Error leyendo el tablero" << endl;
		}
				

	}
	
	fich.close();
}


bool leerTablero (tJuego &juego){

	bool errores;
	int numJug = 0;

	for (int j = 0; j < NUM_FILAS; j++){
		for (int i = 0; i < NUM_FILAS; i++){
			fich >> caracter;
			juego.tablero[i][j].estado = charAtCasilla(caracter);
			if (juego.tablero[i][j].estado == TORTUGA) {
				juego.tablero[i][j].tortuga.direccion = charatDir(caracter);
				numJug++;
				juego.tablero[i][j].tortuga.numero = numJug;

			}
			
		}

	}

	errores = numJug == juego.num_jugadores 
	return errores;

}


void mostrarJuego(const tJuego &juego) {//c = "vv"; fondo = 1;
	int fondo;
	string c;
	for (int j = 0; j < NUM_FILAS; j++) {
		for (int i = 0; i < NUM_FILAS; i++) {

			c = tCasillaAString(juego.tablero[i][j]);
		
			fondo = elegirColor(juego.tablero[i][j]);
			colorFondo(fondo);
			cout << c;
		}
		cout << endl;
	}

	colorFondo(0);
}

void opcion1() {

	tJuego  juego;
	cargarJuego(juego);
	mostrarJuego(juego);
}

int menu() {
	int opc;
	cout << " 1. Jugar \n";
	cout << " 0. Salir del menu \n";
	cin >> opc;
	return opc;
}
void ejecutarOpc() {
	int opc;
	opc = menu();
	switch (opc) {
	case 0: cout << "Venga tio ya nos vemos \n";
		break;
	case 1: opcion1();
		break;
	}
}

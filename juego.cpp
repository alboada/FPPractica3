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
/*int elegirColor(const tCasilla casilla) {
int fondo;
switch (casilla.estado) {

case VACIA: fondo = 0;
break;
case HIELO: fondo = 3;
break;
case MURO: fondo = 5;
break;
case JOYA: fondo = 7;
break;
case TORTUGA: fondo = 10;
break;
case CAJA: fondo = 12;
break;
}
return fondo;

}*/
string nombreFichero() {
	string nombre_fich;
	cout << "¿Cual es el nombre del fichero?";
	cin >> nombre_fich;

	return nombre_fich;
}
void numeroJug(tJuego& juego) {
	cout << "Cuantos jugadores juegan:";
	cin >> juego.num_jugadores;

}
/*tCasilla charAtCasilla(char b) {//D,C,L,U,R,#,@,$, " "
tCasilla prueba;
switch (b) {
case 'D': prueba.estado = TORTUGA;
break;
case 'C': prueba.estado = CAJA;
break;
case 'U': prueba.estado = TORTUGA;
break;
case 'L': prueba.estado = TORTUGA;
break;
case 'R': prueba.estado = TORTUGA;
break;
case '#': prueba.estado = MURO;
break;
case '@': prueba.estado = HIELO;
break;
case '*': prueba.estado = VACIA;
break;
case '$': prueba.estado = JOYA;
break;
}
return prueba;
}*/
/*string tCasillaAChar(tJuego juego) {

string c;
switch () {
case TORTUGA: c = "vv";
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
break;
}

return c;
}*/
void cargarJuego(tJuego& juego) {

	string nombre_fich;
	char caracter;
	int fondo, hola, jug;
	string c, linea;
	tCasilla aux;
	ifstream fich;
	nombre_fich = nombreFichero();
	numeroJug(juego);

	fich.open(nombre_fich);
	if (!fich.is_open()) {

		cout << "El fichero no ha podido abrirse correctamente.";
	}
	else {
		fich >> jug;

		while (jug != juego.num_jugadores) {
			for (int k = 0; k < NUM_FILAS; k++) {
				for (int l = 0; l < NUM_FILAS; l++) {
					fich >> caracter;
				}
			}
			fich >> jug;
		}

		for (int j = 0; j < NUM_FILAS; j++) {
			for (int i = 0; i < NUM_FILAS; i++) {
				fich >> caracter;

				switch (caracter) {
				case 'D': juego.tablero[i][j].estado = TORTUGA; juego.tablero[i][j].tortuga.direccion = SUR;
					break;
				case 'C': juego.tablero[i][j].estado = CAJA;
					break;
				case 'U': juego.tablero[i][j].estado = TORTUGA; juego.tablero[i][j].tortuga.direccion = NORTE;
					break;
				case 'L': juego.tablero[i][j].estado = TORTUGA; juego.tablero[i][j].tortuga.direccion = OESTE;
					break;
				case 'R': juego.tablero[i][j].estado = TORTUGA; juego.tablero[i][j].tortuga.direccion = ESTE;
					break;
				case '#': juego.tablero[i][j].estado = MURO;
					break;
				case '@': juego.tablero[i][j].estado = HIELO;
					break;
				case '*':juego.tablero[i][j].estado = VACIA;
					break;
				case '$': juego.tablero[i][j].estado = JOYA;
					break;
				}
			}
		}



	}

	fich.close();
}

void mostrarJuego(const tJuego &juego) {//c = "vv"; fondo = 1;
	int fondo;
	string c;
	for (int j = 0; j < NUM_FILAS; j++) {
		for (int i = 0; i < NUM_FILAS; i++) {
			switch (juego.tablero[i][j].estado) {
			case TORTUGA: if (juego.tablero[i][j].tortuga.direccion == NORTE) {
				c = "^^"; fondo = 1;
			}
						  else if (juego.tablero[i][j].tortuga.direccion == SUR) {
							  c = "vv"; fondo = 1;
						  }
						  else if (juego.tablero[i][j].tortuga.direccion == ESTE) {
							  c = ">>"; fondo = 1;
						  }
						  else if (juego.tablero[i][j].tortuga.direccion == OESTE) {
							  c = "<<"; fondo = 1;
						  }
						  break;
			case CAJA: c = "[]"; fondo = 4;
				break;
			case HIELO: c = "**"; fondo = 6;
				break;
			case VACIA: c = "  "; fondo = 8;
				break;
			case MURO: c = "||"; fondo = 10;
				break;
			case JOYA: c = "00"; fondo = 14;
				break;
			}

			//c = tCasillaAChar(juego.tablero[i][j]);
			//fondo = elegirColor(juego.tablero[i][j]);
			colorFondo(fondo);
			cout << c;
		}
		cout << endl;
	}
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

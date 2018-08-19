#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>
using namespace std;
#include <string>


const int NUM_FILAS = 8;
const int MAX_JUGADORES = 4;
const int MAX_CARTAS = 38;

typedef enum { NORTE, SUR, ESTE, OESTE }tDir ;
typedef enum { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA }tEstadoCasilla;
typedef enum { AVANZA, DERECHA, IZQUIERDA, SALIR }tTecla;
typedef enum { AVANZAR, GIROIZQUIERDA, GIRODERECHA, LASER }tCarta;
typedef enum { ROBAR, ACCION }tAccion;

typedef struct {
	int fila;
	int columna;
}tCoordenada;

typedef struct{
	int	numero;
	tDir direccion;
}tTortuga;

typedef struct{
	tEstadoCasilla	estado;
	tTortuga tortuga;
}tCasilla;

typedef tCarta tArrayCartas[MAX_CARTAS];

typedef struct {
	tArrayCartas cartas;
	int cont;
} tMazo;

typedef struct {
	string nombre;
	int fila_act;
	int columna_act;
	tMazo mano;
	tMazo mazo;
}tJugador;


typedef tCasilla tTablero[NUM_FILAS][NUM_FILAS];

typedef tJugador tRegistro[MAX_JUGADORES];

typedef struct {
	int num_jugadores;
	int turno;
	tTablero tablero;
}tJuego;



void crearVacia(tMazo &mazo);
void crearMazoAleatorio(tMazo &mazo);
bool sacar(tMazo &mazo);
void muestraMazo (tMazo mazo);


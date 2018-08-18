
#include <string>
using namespace std;

const int NUM_FILAS = 8;
const int MAX_JUGADORES = 4;
const int MAX_CARTAS = 38;
enum	tDir { NORTE, SUR, ESTE, OESTE };
enum	tEstadoCasilla { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA };
enum tTecla { AVANZA, DERECHA, IZQUIERDA, SALIR };
enum	tCarta { AVANZAR, GIROIZQUIERDA, GIRODERECHA, LASER };
enum tAccion { ROBAR, ACCION };

struct	tTortuga {
	int	numero;
	tDir	direccion;
};
struct tCasilla {
	tEstadoCasilla	estado;
	tTortuga tortuga;
};

typedef tCasilla tTablero[NUM_FILAS][NUM_FILAS];
struct tMazo {
	typedef tCarta tMazoJug[MAX_CARTAS];
	tMazoJug mazoJug;
};
struct tJugador {
	string nombre;
	int fila_act;
	int columna_act;
	//falta el mazo y la mano 
};
struct tJuego {
	int num_jugadores;
	int turno;
	typedef tJugador tRegistro[MAX_JUGADORES];
	tTablero tablero;
};
struct tCoordenada {
	int fila;
	int columna;
};


void crearVacia(tMazo &mazo);
void crearMazoAleatorio(tMazo &mazo);
bool sacar(tMazo &mazo);


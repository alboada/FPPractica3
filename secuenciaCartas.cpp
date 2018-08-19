#include "Header.h"


void crearVacia(tMazo &mazo) {
	
	mazo.cont = 0;

	/*
	*/

}

void crearMazoAleatorio(tMazo &mazo) {
	

	for (int i = 0; i < 18; i++)
	{
		mazo.cartas[i] = AVANZAR;
	}
	for (int i = 18; i < 26; i++)
	{
		mazo.cartas[i] = GIRODERECHA;
	}
	for (int i = 26; i < 34; i++)
	{
		mazo.cartas[i] = GIROIZQUIERDA;
	}
	for (int i = 34; i < 38; i++)
	{
		mazo.cartas[i] = LASER;
	}

	

	mazo.cont = 38;



	cout << "Todo Ok" << endl;

	random_shuffle( &mazo.cartas[0], &mazo.cartas[37]);

}
bool sacar(tMazo &mazo) {
	bool posible;

	if (mazo.cartas[0] == AVANZAR || mazo.cartas[0] == GIRODERECHA || mazo.cartas[0] == GIROIZQUIERDA || mazo.cartas[0] == LASER) {
		posible = true;
	}
	else {
		posible = false;
	}

	/*for (int k = 0; k < MAX_CARTAS; k++)
	{

	cout << mazo.mazoJug[k] << " ";
	}
	cout << endl;*/

	return posible;
}


void muestraMazo (tMazo mazo){

	for (int k = 0; k < mazo.cont; k++)
	{

	cout << mazo.cartas[k] << " ";
	}
	cout << endl;

}



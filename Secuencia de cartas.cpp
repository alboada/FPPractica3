#include "Header.h"
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>
using namespace std;

void crearVacia(tMazo &mazo) {
	for (int i = 0; i < 18; i++)
	{
		mazo.mazoJug[i] = AVANZAR;
	}
	for (int i = 18; i < 26; i++)
	{
		mazo.mazoJug[i] = GIRODERECHA;
	}
	for (int i = 26; i < 34; i++)
	{
		mazo.mazoJug[i] = GIROIZQUIERDA;
	}
	for (int i = 34; i < 38; i++)
	{
		mazo.mazoJug[i] = LASER;
	}


}

void crearMazoAleatorio(tMazo &mazo) {

	srand(time(0));
	for (int i = 0; i < MAX_CARTAS; i++)
	{
		int index = rand() % MAX_CARTAS;

		tCarta temp = mazo.mazoJug[i];
		mazo.mazoJug[i] = mazo.mazoJug[index];
		mazo.mazoJug[index] = temp;
	}

	for (int k = 0; k < MAX_CARTAS; k++)
	{

		cout << mazo.mazoJug[k] << " ";
	}
	cout << endl;

}
bool sacar(tMazo &mazo) {
	bool posible;

	if (mazo.mazoJug[0] == AVANZAR || mazo.mazoJug[0] == GIRODERECHA || mazo.mazoJug[0] == GIROIZQUIERDA || mazo.mazoJug[0] == LASER) {
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




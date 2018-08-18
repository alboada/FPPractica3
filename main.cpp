#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	tMazo mazo;

	crearVacia(mazo);
	crearMazoAleatorio(mazo);
	sacar(mazo);
	system("pause");
	return 0;
}
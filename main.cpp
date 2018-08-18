#include "Secuencia de cartas.cpp"

using namespace std;

int main() {
	tMazo mazo;

	cout << "Todo Ok" << endl;

	srand(time(0));
	cout << "Todo Ok" << endl;


	crearVacia(mazo);
	cout << "Todo Ok" << endl;

	crearMazoAleatorio(mazo);

	muestraMazo (mazo);


	return 0;
}
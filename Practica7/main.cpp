/*
NOMBRE Y APELLIDOS:
GRUPO: B34  LAB: 1
COLLADO MAMBLONA, ALBERTO
GÓMEZ ALONSO, JOSÉ LUIS
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Arbin.h"

using namespace std;


bool esHoja(const Arbin<char>& a) {
	if (a.esVacio()) return false;
	else return a.hijoIz().esVacio() && a.hijoDer().esVacio();
}

void tiempoAyudaAux(const Arbin<char>& falda, int cont, int & horas_ac) {
	// A IMPLEMENTAR
	if (!falda.esVacio()) {
			if (falda.raiz() == 'X') horas_ac += cont * 2;
			if (!esHoja(falda)){
				++cont;
				tiempoAyudaAux(falda.hijoIz(), cont, horas_ac);
				tiempoAyudaAux(falda.hijoDer(), cont, horas_ac);
			}
	}
}

int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	int horas_ac = 0;
	tiempoAyudaAux(falda, 0, horas_ac);

	return horas_ac;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
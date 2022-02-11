//ALUMNOS:
//GRUPO: B34  LAB: 1
//COLLADO MAMBLONA, ALBERTO
//GÓMEZ ALONSO, JOSÉ LUIS

#include <iostream>
#include <string>
using namespace std;
#include "cola.h"
#include "pila.h"


void lee_caso(Cola<char>& cola) {
	char ch;
	cin.get(ch);
	while (ch != '\n') {
		if (ch != ' ')
			cola.pon(ch);
		cin.get(ch);
	}
}


bool palindroma(Cola<char> cola) {
	int longitud = cola.longitud();
	Pila <char> pila;
	bool res = true;

	if (!cola.esVacia()) {
		if (longitud % 2 == 0) {
			for (int i = 0; i < longitud / 2; ++i) {
				pila.apila(cola.primero());
				cola.quita();
			}
		}
		else if (longitud % 2 != 0) {
			for (int i = 0; i < ((longitud / 2) + 1); ++i) {
				if (i == (longitud / 2)) cola.quita();
				else {
					pila.apila(cola.primero());
					cola.quita();
				}
			}
		}
	}

	while (cola.longitud() > 0 && res == true) {
		if (cola.primero() != pila.cima()) res = false;
		cola.quita();
		pila.desapila();
	}
	
	return res;
}


int main() {
	Cola<char> cola;

	lee_caso(cola);

	Cola<char> colaAux;
	colaAux = cola;
	int longitud = colaAux.longitud();
	for (int i = 1; i <= longitud; i++) {
		cout << colaAux.primero();
		colaAux.quita();
	}
	cout << " = ";
	if (palindroma(cola)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}




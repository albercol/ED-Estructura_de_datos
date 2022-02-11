#include <iostream>
#include <string>
#include "Arbin.h"

using namespace std;


/**
  FUNCION A IMPLEMENTAR.
  Aparte de esta función, puedes implementar todas las funciones auxiliares que
  consideres oportuno. 
  Debes describir y justificar aquí la complejidad de la implementación realizada:
  
  La complejidad es lineal, porque recorre cada nodo del arbol una sola vez con llamadas recursivas.
  El resto del código son instrucciones constantes.
  Ademas de que el TAD Arbin esta implementado de forma eficiente con conteo de referencias.

*/


int num_a_salvo_aux(const Arbin<char>& a, int nMonstruos, bool dama, int &aSalvo) {
	int sumCab = 0;

	if (!a.esVacio()) {
		if (a.raiz() == 'D' && dama == false) {
			dama = true;
			sumCab = 0;
		}
		if (a.raiz() == 'M' && dama == false) ++nMonstruos;
		if (a.raiz() == 'C' && dama == true) ++sumCab;

		
		if (!a.hijoIz().esVacio()) sumCab += num_a_salvo_aux(a.hijoIz(), nMonstruos, dama, aSalvo);
		if (!a.hijoDer().esVacio()) sumCab += num_a_salvo_aux(a.hijoDer(), nMonstruos, dama, aSalvo);

		if (a.raiz() == 'D' && nMonstruos <= sumCab) {
			++aSalvo;
			dama = false;
		}
		
	}

	return sumCab;
}

int num_a_salvo(const Arbin<char>& a) {
	/*** A IMPLEMENTAR ***/
	int aSalvo = 0;
	num_a_salvo_aux(a, 0, false, aSalvo);

	return aSalvo;
}



Arbin<char> lee_arbol(istream& in) {
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
		Arbin<char> iz = lee_arbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = lee_arbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}


void escribe_arbol(Arbin<char> a) {
	if (a.esVacio()) cout << "#";
	else if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) cout << "[" << a.raiz() << "]";
	else {
		cout << "("; 
		escribe_arbol(a.hijoIz()); 
		cout << a.raiz(); 
		escribe_arbol(a.hijoDer());
		cout << ")";
	}
}


int main() {
	Arbin<char> arbol;
	while (cin.peek() != EOF)  {
		Arbin<char> mapa = lee_arbol(cin);
		cout << "num_a_salvo ";
		escribe_arbol(mapa);
		cout << " => ";
		cout << num_a_salvo(mapa);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}

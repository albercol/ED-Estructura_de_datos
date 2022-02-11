#include <iostream>
#include "cola.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
      // A IMPLEMENTAR
	Cola<int> cola;
	unsigned int res = 0, cont = 1;
	 //Rellena Cola:
	for (unsigned int i = 1; i <= n; ++i) {
			cola.pon(i);
	}
	
	while (!cola.esVacia()) {
		if (cont == m) {
			cola.quita();
			cont = 1;
		}
		else {
			cola.pon(cola.primero());
			res = cola.primero();
			cola.quita();
			cont++;
		}
	}
	return res;
}


int main() {
    int n,m;
	while((cin >> n)) {
	   cin >> m;
       cout << afortunado(n,m) << endl;	   
	}
	return 0;
}	

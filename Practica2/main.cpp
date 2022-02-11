#include <iostream>
#include<string>
#include "pila.h"
using namespace std;


int evaluar(string exp) {
	Pila<int> pila;
	int num, op1, op2;
	//int size = 
	for (int i=0; i< exp.size(); ++i) {
		switch (exp[i]) {
		case '+':
			op1 = pila.cima();
			pila.desapila();
			op2 = pila.cima();
			pila.desapila();
			num = op2 + op1;
			pila.apila(num);
			break;
		case '-':
			op1 = pila.cima();
			pila.desapila();
			op2 = pila.cima();
			pila.desapila();
			num = op2 - op1;
			pila.apila(num);
			break;
		case '*':
			op1 = pila.cima();
			pila.desapila();
			op2 = pila.cima();
			pila.desapila();
			num = op2 * op1;
			pila.apila(num);
			break;
		case '/':
			op1 = pila.cima();
			pila.desapila();
			op2 = pila.cima();
			pila.desapila();
			num = op2 / op1;
			pila.apila(num);
			break;
		default:
			pila.apila(int(exp[i]-'0'));
		}
	}

	num = pila.cima();

	while(!pila.esVacia()) {
		pila.desapila();
	}

	return num;
}

int main() {
	
	string expresion;
	while (cin >> expresion) 
		cout << evaluar(expresion) << endl;

	
	return 0;
}


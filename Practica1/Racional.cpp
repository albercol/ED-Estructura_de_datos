// ALUMNOS:
//GRUPO: B34  LAB: 1
//COLLADO MAMBLONA, ALBERTO
//GÓMEZ ALONSO, JOSÉ LUIS


#include "Racional.h"
#include <cmath>


//Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
Racional::Racional(long n, long d) { //Constructor parametrizado
	if (d == 0) throw EDenominadorCero();
	_numer = new long;
	*_numer = n;
	_denom = new long;
	*_denom = d;
	reduce();
}

Racional::Racional() { //Constructor por defecto
	_numer = new long;
	*_numer = 0;
	_denom = new long;
	*_denom = 1;
}

Racional::~Racional() {
	delete _numer;
	delete _denom;
}

Racional& Racional::suma(const Racional &e) {
	// (_numer=a)(_denom=b)(e._denom=d)(e._numer=c)

	long resMcm = mcm(*_denom, *e._denom); 
	long numerA =(*_numer * resMcm)/ *_denom; 
	long numerB = (*e._numer * resMcm) / *e._denom; 
	long numerT = numerA + numerB;
	
	*_numer = numerT;
	*_denom = resMcm;
	 
	reduce();
	return *this;
}

Racional& Racional::operator- (const Racional &e) {
	// (_numer=a)(_denom=b)(e._denom=d)(e._numer=c)

	long resMcm = mcm(*_denom, *e._denom);
	long numerA = (*_numer * resMcm) / *_denom;
	long numerB = (*e._numer * resMcm) / *e._denom;
	long numerT = numerA - numerB;

	*_numer = numerT;
	*_denom = resMcm;

	reduce();
	return *this;
}

Racional& Racional::operator*= (const Racional &e) {
	// (_numer=a)(_denom=b)(e._denom=d)(e._numer=c)
	*_numer = *_numer * *e._numer;
	*_denom = *_denom * *e._denom;

	reduce();
	return *this;
}

Racional& Racional::divideYActualiza(const Racional &e) {
	// (_numer=a)(_denom=b)(e._denom=d)(e._numer=c)
	if (*e._numer == 0 && *e._denom == 1) throw EDivisionPorCero();
	*_numer = *_numer * *e._denom;
	*_denom = *_denom * *e._numer;

	reduce();
	return *this;
}

bool Racional::operator== (Racional &e) {
	return ((*_numer == *e._numer) && (*_denom == *e._denom));
}

	
// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << *f._numer << "/" << *f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0) {
		*_numer = -(*_numer);
		*_denom = -(* _denom);
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}


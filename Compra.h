#ifndef COMPRA_H
#define COMPRA_H
#include"CLiente.h"
#include"Peca.h"
#include<iostream>

using namespace std;

class Compra
{
	public:
		Compra(Peca *p, Cliente *c); // Passando como Parametro para o constutor a Classe peca e a classe cliente.
		Cliente * getCliente(); // Passando o Ponteiro da Classe Cliente para poder utiliza-lá.
		Peca * getPeca();       // Passando o Ponteiro da Classe Peça para poder utiliza-lá.
	private:
		Peca *peca;
		Cliente *cliente;
};

#endif


#include<iostream>
#include"Compra.h"
#include"Cliente.h"
#include"Peca.h"

using namespace std;

Compra::Compra(Peca *p, Cliente *c)
{
	this->peca = p;
	this->cliente = c;
}

Cliente* Compra::getCliente()
{
	return this->cliente; //Pegando o nome do Cliente da classe Cliente.
	
}

Peca* Compra::getPeca()
{
	return this->peca; // Pegando o nome da peca da Classe Peca.
}

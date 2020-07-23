#include<iostream>
#include"Cliente.h"

using namespace std;

Cliente::Cliente(string nome)
{
	this->nome = nome; // Construtor
}

void Cliente::setNome()
{
	this->nome = nome; //Pegando o Nome do Cliente.
}

string Cliente::getNome()
{
	return this->nome; //Retornando o Nome do Cliente.
}

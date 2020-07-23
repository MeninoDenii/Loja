#ifndef LOJA_H
#define LOJA_H
#include"Cliente.h"
#include"Peca.h"
#include<vector>
#include<string>

using namespace std;

class Loja
{
	public:
			
	private:
		vector<Cliente*> clientes;
		vector<Peca*> pecas;
		vector<Compra*>compras;
};

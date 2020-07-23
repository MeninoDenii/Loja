#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>

using namespace std;

class Cliente
{
	public:
		Cliente(string nome);
		string getNome();
		void setNome();			
	private:
		string nome;
			
};

#endif

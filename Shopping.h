#ifndef SHOPPING_H
#define SHOPPING_H
#include<string>
#include"Cliente.h"
#include"Compra.h"
#include"Peca.h"
#include"Excessao.h"
#include<vector>

/* Aqui se Encontram Basicamente todas as Funcionalidades da Loja.*/

class Loja
{
	public:
		void CadastrarPecas(Peca *p);
		void CadastrarCliente(Cliente *c);
		void MostrarProdutos();
		void MostrarClientes();
		void MostrarCompras();
		int VerificaCliente(string nome) throw(ExcessaoCliente);
		int VerificaEstoque(string nome) throw(ExcessaoPeca);
		void compra(int q, int w, int quantidade);
		void Compras_do_Cliente(string nome);
		void Cliente_por_roupa(string nome);
		/*Criando os vectors para as Classes para armazenar os dados do cliente, as pecas que foram compradas na Loja, e as comprar realizadas. */
	private:
		vector<Cliente*>clientes; 
		vector<Peca*>pecas;
		vector<Compra*>compras;
};

#endif

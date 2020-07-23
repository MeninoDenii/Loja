#include"Peca.h"
#include"Cliente.h"
#include"Shopping.h"
#include"Compra.h"
#include"Excessao.h"
#include<vector>
#include<iostream>
#include<exception>
#include<string>

using namespace std;

/* Esse metodo ele Cadastra os Produtos da Loja */
void Loja::CadastrarPecas(Peca *p)
{
	this->pecas.push_back(p);
}
/* Esse metodo ele Cadastra os Clientes da Loja */
void Loja::CadastrarCliente(Cliente *c)
{
	this->clientes.push_back(c);
}
/* Esse metodo ele Mostra todos os Clientes Cadastrados na Loja */
void Loja::MostrarClientes()
{
	cout<<" Lista De Clientes Cadastrados!"<<endl;
	cout<<endl;
	
	for(int i = 0; i < this->clientes.size(); i++)
	{
		cout<<"O Cliente "<<this->clientes[i]->getNome()<<" Se Cadastrou na Loja!"<<endl;
	}
}
/* Esse metodo ele Mostra todos os Produtos Cadastrados na Loja */
void Loja::MostrarProdutos()
{
	cout <<"Lista De Produtos Cadastrados!"<<endl;
	cout <<endl;
	
	for(int i = 0; i < this->pecas.size(); i++)
	{
		cout<<"Foram Cadastradas um(a) Peca: "<<this->pecas[i]->getNome()<<" Seu Codigo de Barras eh: "<<pecas[i]->getCodigoBarras()<<" E contem no Estoque: "<<this->pecas[i]->getQuantidade()<<" Produto(s)"<<endl;
	}
}
/* Esse metodo ele Mostra Verifica  se o  Cliente que deseja efetuar alguma compra esta cadastrado na Loja, se nao estiver cadastrado ele retorna uma excessao */
int Loja::VerificaCliente(string nome) throw(ExcessaoCliente)
{
	for(int i = 0; i < this->clientes.size(); i++)
	{
		if(nome.compare(this->clientes[i]->getNome()) == 0) // uma funcao do c++ chamada compare serve para comparar se duas strings sao identicas, se caso for igual a 0 significa que são iguais se não, sao diferentes e ele retorna a excessao
		{
			return i;
		}	
	}
	throw ExcessaoCliente("Cliente Inexistente ou nao Cadastrado no Sistema!");
}

/* Esse metodo Verifica o estoque, se caso algum produto nao estiver  Cadastrado na Loja , ele entra na excessao*/
int Loja::VerificaEstoque(string nome) throw(ExcessaoPeca)
{
	for(int i = 0; i < pecas.size(); i++)
	{
		if(nome.compare(this->pecas[i] ->getNome()) == 0)
		{
			return i;
		}
	}
	throw ExcessaoPeca("Produto Inexistente ou nao Cadastrado no Sistema!");
}
/* Aqui é Onde o cliente ira fazer a Compra */
void Loja::compra(int cliente, int peca, int quantidade)
{
	string nome_cliente = this->pecas[peca]->getNome(); // Atraves do vector e do metodo getNome() é Possivel ter acesso ao nome do cliente que irá efetuar a compra.
	string codigo_barras = this->pecas[peca]->getCodigoBarras(); // Atraves do vector e do metodo getCodigoBarras() é Possivel ter acesso ao codigo de Barras.
	string tamanho_peca = this->pecas[peca]->getTamanho(); // Atraves do vector e do metodo getTamanho() é Possivel ter acesso ao tamanho do produto.
	
	this->pecas[peca]->setQuantidade(quantidade); // Atraves do vector e do metodo setQuantidade() Implementado na peca.h ele serve para diminuir a quantidade de um produto que ja foi comprado.
	
	Peca *pecas = new Peca(nome_cliente,tamanho_peca,codigo_barras,quantidade); // criando o vetor para peças
	Compra *compras = new Compra(pecas, this->clientes[cliente]); // criando um vetor para compras
	
	this->compras.push_back(compras); // Colocando todas as compras efetuadas no vector.
}
// Aqui é Possivel listar todas as compras realizadas pelos Clientes.
void Loja::MostrarCompras()
{
	for(int i = 0; i < compras.size();i++)
	{
		cout<<" Compra: "<<i+1<<endl;
		cout<<"Peca Comprada: "<<this->compras[i]->getPeca()->getNome()<<endl;
        cout<<"Cliente que Fez a Compra: "<<this->compras[i]->getCliente()->getNome()<<endl;
	}
}

// Aqui é Possivel Citar quais produtos os clientes compraram pelo nome do cliente.

void Loja::Cliente_por_roupa(string nome)
{
	cout<<"Informe Seu Nome Cliente: "<<nome<<endl;

    for(int i = 0; i < this->compras.size();i++){
        if(nome.compare(this->compras[i]->getPeca()->getNome()) == 0){
            cout<<"Cliente "<<i<<": "<<this->compras[i]->getCliente()->getNome()<<endl;
        }
    }
}
// Aqui é Possivel Mostrar os Produtos que o cliente comprou.
void Loja::Compras_do_Cliente(string nome)
{
	cout<<"Compras:"<<endl;

    for(int i = 0; i < this->compras.size();i++){
        if(nome.compare(this->compras[i]->getCliente()->getNome()) == 0){
            cout<<"Peca "<<i<<": "<<this->compras[i]->getPeca()->getNome()<<endl;
        }
    }
}













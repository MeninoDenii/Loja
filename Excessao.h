#ifndef EXCESSAO_H
#define EXCESSAO_H
#include<iostream>

/* Aqui Contém as Excessoes do Sistema, foram criadas duas Excessoes Para Cliente e Outra para os Produtos, utilizadas no caso de se existir algum cliente inexistente ou produto inexistente. */
using namespace std;

class ExcessaoCliente : public exception
{
	public:
		ExcessaoCliente(string mensagem)
		{
			this->mensagem = mensagem;
		}	
		virtual const char* what() const throw()
		{
			return mensagem.c_str();
		}
		virtual ~ExcessaoCliente() throw(){}
	private:
		string mensagem;
};

class ExcessaoPeca : public exception
{
	public:
		ExcessaoPeca(string mensagem)
		{
			this->mensagem = mensagem;
		}	
		virtual const char* what() const throw()
		{
			return mensagem.c_str();
		}
		virtual ~ExcessaoPeca() throw(){}
	private:
		string mensagem;
};

#endif

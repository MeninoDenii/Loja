#ifndef PECA_H
#define PECA_H
#include<string>

using namespace std;

class Peca
{
	public:
		Peca(string nome, string tamanho, string codigo_barras, int quantidade);
		string getNome();
		void setNome();
		string getTamanho();
		void setTamanho();
		string getCodigoBarras();
		void setCodigoBarras();
		int getQuantidade();
		void setQuantidade(int n);
	private:
		string nome;
		string tamanho;
		string codigo_barras;
		int quantidade;
};

#endif

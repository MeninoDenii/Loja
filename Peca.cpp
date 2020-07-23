#include<iostream>
#include<string>
#include"Peca.h"

using namespace std;

Peca::Peca(string nome, string tamanho,string codigo_barras, int quantidade)
{
	this->nome = nome;
	this->tamanho = tamanho;           //Construtor
	this->codigo_barras = codigo_barras;
	this->quantidade = quantidade;
}

string Peca::getNome()
{
	return this->nome; //Retornando o Nome da peça.
}

void Peca::setNome()
{
	this->nome = nome; //Pegando o Nome da peça.
}

string Peca::getTamanho()
{
	return this->tamanho; // Retornando o Tamanho da Peça.
}

void Peca::setTamanho()
{
	this->tamanho = tamanho; // Pegando o Tamanho da Peça
}

string Peca::getCodigoBarras()
{
	return this->codigo_barras; // Retornando o Codigo de Barras.
}

void Peca::setCodigoBarras()
{
	this->codigo_barras = codigo_barras; // Pegando o Código de Barras.
}

int Peca::getQuantidade()
{
	return this->quantidade; // Retornando a Quantidade.
}

void Peca::setQuantidade(int n)
{
	this->quantidade-=n; // Pegando a Quantidade.
}


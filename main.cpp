#include<iostream>
#include"Cliente.h"
#include"Peca.h"
#include"Shopping.h"
#include"Excessao.h"
#include<string>
#include<vector>

using namespace std;

void MenuLoja()
{
	cout<<endl;
	cout<<"Bem-vindo ao Ponto de Vendas"<<endl;
	cout<<endl;
	cout<<"Escolha Uma Opcao: "<<endl;
	cout<<endl;
	cout<<"\t1-Cadastrar Clientes"<<endl;
	cout<<"\t2-Cadastrar Produtos"<<endl;
	cout<<"\t3-Listar Produtos"<<endl;
	cout<<"\t4-Listar Clientes"<<endl;
	cout<<"\t5-Listar Compras"<<endl;
	cout<<"\t6-Realizar Uma Compra"<<endl;
	cout<<"\t7-Cliente Compradores"<<endl;
	cout<<"\t8-Sair do Programa"<<endl;
}

int main()
{
	Loja shopping;
	int opcao;
	string nome_cliente;
	string nome_produto;
	string tamanho;
	int quantidade;
	string codigo_barras;
	int produto;
	int cliente;
	
	while(opcao!= 8)
	{
		MenuLoja();
		cout<<endl;
		cout<<"Escolha Sua Opcao:"<<endl;
		cin >> opcao;
		
		switch(opcao)
		{
			case 1:
				cout<<"Caro Cliente, Digite seu nome:"<<endl;
				cin >> nome_cliente;
				system("cls");
				shopping.CadastrarCliente(new Cliente(nome_cliente));
				break;
			case 2:
				cout<<"Nos informe o nome do produto"<<endl;
				cin>> nome_produto;
				
				cout<<"Nos informe o codigo de Barras do Produto"<<endl;
				cin >> codigo_barras;
				
				cout<<"Nos informe a quantidade do Produto"<<endl;
				cin >> quantidade;
				
				cout<<"Nos informe o tamanho do Produto"<<endl;
				cin >> tamanho;	
				
				shopping.CadastrarPecas(new Peca(nome_produto,tamanho,codigo_barras,quantidade));
				break;	
			case 3:
				shopping.MostrarProdutos();
				break;
			case 4:
				shopping.MostrarClientes();	
				break;
			case 5:
				shopping.MostrarCompras();
				break;	
			case 6:
				cout<<"Diga seu Nome Cliente:"<<endl;
				cin>> nome_cliente;
				try{
					cliente = shopping.VerificaCliente(nome_cliente);	
				}catch(ExcessaoCliente &ex){
					cout<<ex.what()<<endl;
					break;
				}
				cout<<"O que Deseja Comprar?"<<endl;
				cin>>nome_produto;
				try{
					produto = shopping.VerificaEstoque(nome_produto);
				}catch(ExcessaoPeca &ex){
					cout<<ex.what()<<endl;
					break;
				}
				cout<<"Quantos produtos voce quer?"<<endl;
				cin>> quantidade;
				shopping.compra(cliente,produto,quantidade);
				break;
			case 7:
				try{
                    cout<<"Diga Seu Nome Cliente"<<endl;
                    cin>> nome_cliente;
                    shopping.VerificaCliente(nome_cliente);
                    shopping.Compras_do_Cliente(nome_cliente);
                }catch(ExcessaoCliente &ex){
                    cout<<ex.what()<<endl;
                }
                break;	
			case 8:
				cout<<"Obrigado Por Utilizar o Meu Programa, Volte Sempre!"<<endl;
				break;
			default:
				cout<<endl;
				cout<<"Opcao Digitada Incorretamente!"<<endl;
		}
	}
	
	return 0;
}

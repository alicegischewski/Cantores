#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void menu(){
	cout<<"1- Inserir novo registro."<<endl;
	cout<<"2- Remover registro."<<endl;
	cout<<"3- Buscar registro."<<endl;
	cout<<"4- Ordenar dados."<<endl;
	cout<<"5- Vizualizar dados"<<endl;
	cout<<"6- Salvar alteracoes."<<endl;
	cout<<"7- Sair"<<endl;
	
}

int main(){
	ifstream entrada("entrada.csv");
	ofstream saida ("saida.csv");


  return 0;

}


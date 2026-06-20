//Integrantes: Alice ?, Helena de Godoy, Júlia Abreu de Araújo
//Turma 14A
//Tema: cantores

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
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

struct arquivo{
	string nome;
	char sexo;
	string nacionalidade;
	short nascimento;
	string genero;
};

int main(){
	ifstream entrada("entrada.csv");

	if(!entrada.is_open()){
		cout<<"Erro ao abrir o arquivo!"<<endl;
		return 0;
	}else{
		menu();
	}

	int capacidade=40, tamanho=0;
	arquivo *lista=new arquivo[capacidade];
	arquivo temp;
	char lixo;

	while(getline(entrada,temp.nome,';')){
		entrada>>temp.sexo>>lixo;
		getline(entrada,temp.nacionalidade,';');
		entrada>>temp.nascimento>>lixo;
		getline(entrada,temp.genero);
						if(capacidade==tamanho){
							arquivo *novaLista=new arquivo[capacidade+10];
							copy(lista, lista + capacidade, novaLista);
							delete[] lista;
							lista=novaLista;
							capacidade+=10;
						}
						lista[tamanho]=temp;
						tamanho++;
					}
			

  return 0;

}


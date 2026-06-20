#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct cantores{
	string nome;
	char sexo;
	string nacionalidade;
	short nascimento;
	string genero;
};

void inserirCantor(cantores *&lista, int &tamanho, int &capacidade){
	cantores novo;
	cout<<"Insira o novo registro. "<<endl;;
	cout<<"Nome: ";
	cin.ignore();
	getline(cin, novo.nome);

	bool jaExiste=false;

	for(int i=0;i<tamanho and jaExiste==false;i++){
		if(lista[i].nome==novo.nome){
			jaExiste=true;
		}
	}
	if(jaExiste==true){
		cout<<"Esse(a) cantor(a) ja esta registrado(a)."<<endl;
		cout<<endl;
		return;
	}

	cout<<"Sexo: ";
	cin>>novo.sexo;
	cout<<"Nacionalidade: ";
	cin.ignore();
	getline(cin, novo.nacionalidade);
	cout<<"Ano de nascimento: ";
	cin>>novo.nascimento;
	cout<<"Genero musical: ";
	cin.ignore();
	getline(cin, novo.genero);

		if(tamanho==capacidade){
			cantores *novaLista=new cantores[capacidade+10];
			copy(lista, lista+tamanho, novaLista);
			delete[] lista;
			lista=novaLista;
			capacidade+=10;
		}
		lista[tamanho]=novo;
		tamanho++;

		cout<<"Cantor(a) registrado!"<<endl;
		cout<<endl;
}

void removerCantor(cantores lista[], int &tamanho){
	string nomeRemovido;
	cout<<"Insira o(a) cantor(a) que deseja remover: ";
	cin.ignore();
	getline(cin, nomeRemovido);

	int pos=-1;
	bool encontrou=false;
		for(int i=0;i<tamanho and encontrou==false;i++){
			if(lista[i].nome==nomeRemovido){
				pos=i;
				encontrou=true;
				}
			}
			if(pos==-1){
				cout<<"Cantor(a) nao encontrado(a)."<<endl;
			}else{
				for(int j=pos;j<tamanho-1;j++){
				lista[j]=lista[j+1];
				}
				tamanho--;
				cout<<"Cantor(a) removido(a)!"<<endl;
			}
			cout<<endl;
}

void selectionSort(cantores lista[], int tamanho, int opcao){
	int menor;
	cantores aux;

	if (opcao==1){
		for(int i=0;i<tamanho-1;i++){
			menor=i;
			for(int j=i+1;j<tamanho;j++){
				if(lista[j].nome<lista[menor].nome){
					menor=j;
				}
			}
			aux=lista[i];
			lista[i]=lista[menor];
			lista[menor]=aux;
		}
	}
	else if(opcao==2){
		for(int i=0;i<tamanho-1;i++){
			menor=i;
			for(int j=i+1;j<tamanho;j++){
				if(lista[j].nascimento<lista[menor].nascimento){
					menor=j;
				}
			}
			aux=lista[i];
			lista[i]=lista[menor];
			lista[menor]=aux;
		}
	}else{
		cout<<"Opcao invalida!"<<endl;
		cout<<endl;
	}
}

void imprimirInfo(cantores lista[], int pos){
	cout<<"---------------------------------------------"<<endl
			<<"Nome: "<<lista[pos].nome<<endl
			<<"Sexo: "<<lista[pos].sexo<<endl
			<<"Nacionalidade: "<<lista[pos].nacionalidade<<endl
			<<"Ano de nascimento: "<<lista[pos].nascimento<<endl
			<<"Genero musical: "<<lista[pos].genero<<endl;
}

void buscarCantor(cantores lista[], int tamanho){
	string busca;
	cout<<"Deseja buscar registro por Nome, Sexo, Nacionalidade, Ano de nascimento ou Genero musical?"<<endl;
	cin.ignore();
	getline(cin, busca);
		if(busca=="Nome" or busca=="nome"){
			cout<<"Digite o nome: ";
			string nomeProcurado;
			getline(cin, nomeProcurado);
			
			bool encontrou=false;

			for(int i=0;i<tamanho;i++){
				if(lista[i].nome==nomeProcurado){
					encontrou=true;
					imprimirInfo(lista, i);
				}
			}
			if(encontrou==false){
				cout<<"Nome nao encontrado!"<<endl;
			}
		}
		else if(busca=="Sexo" or busca=="sexo"){
			cout<<"Digite o sexo que deseja buscar(F/M): ";
			char escolha;
			cin>>escolha;
			bool encontrou=false;

			for(int i=0;i<tamanho;i++){
				if(lista[i].sexo==escolha){
					encontrou=true;
					imprimirInfo(lista, i);
				}
			}
			if(encontrou==false){
				cout<<"Sexo nao encontrado!"<<endl;
			}
				
		}
		else if(busca=="nacionalidade" or busca=="Nacionalidade"){
			cout<<"Digite a nacionalidade que deseja buscar: ";
			string escolha;
			getline(cin, escolha);

			bool encontrou=false;
			for(int i=0;i<tamanho;i++){
				if(lista[i].nacionalidade==escolha){
					encontrou=true;
					imprimirInfo(lista, i);
				}
			}
			if(encontrou==false){
				cout<<"Nacionalidade nao encontrada!"<<endl;
			}
		}
		else if(busca=="ano de nascimento" or busca=="Ano de nascimento"){
			cout<<"Digite o ano de nascimento que deseja buscar: ";
			short escolha;
			cin>>escolha;
			bool encontrou=false;
			for(int i=0;i<tamanho;i++){
				if(lista[i].nascimento==escolha){
						encontrou=true;
					imprimirInfo(lista, i);
				}
			}
			if(encontrou==false){
				cout<<"Ano de nascimento nao encontrado!"<<endl;
			}
		}
		else if(busca=="Genero musical" or busca=="genero musical"){
			cout<<"Digite o genero muscial que deseja buscar: ";
			string escolha;
			getline(cin, escolha);

			bool encontrou=false;

			for(int i=0;i<tamanho;i++){
				if(lista[i].genero==escolha){
						encontrou=true;
					imprimirInfo(lista, i);
				}
			}
			if(encontrou==false){
				cout<<"Genero musical nao encontrado!"<<endl;
			}
		}else{
			cout<<"Busca invalida!"<<endl;
		}
		cout<<endl;
	}	



void salvarAlteracoes(cantores lista[], int tamanho){
	ofstream saida("cantores.csv");
	
	saida<<"nome;sexo;nacionalidade;ano_nascimento;genero_musical"<<endl;
		for(int i=0;i<tamanho;i++){
			saida<<lista[i].nome<<";"
			<<lista[i].sexo<<";"
			<<lista[i].nacionalidade<<";"
			<<lista[i].nascimento<<";"
			<<lista[i].genero
			<<endl;
		}
		saida.close();
		cout<<"Alteracao salva!"<<endl;
		cout<<endl;
}

void visualizarDados(cantores lista[], int tamanho){
	cout<<"--------------------Visualizacao-dos-cantores--------------------"<<endl;
	cout<<"Qual trecho deseja visualizar?: "<<endl;
	cout<<"1- ARQUIVO INTEIRO."<<endl;
	cout<<"2- ESCOLHER TRECHO."<<endl; 
	int opcao;
	cin>>opcao;
	
	if(opcao==1){
		for(int i=0;i<tamanho;i++){
			cout<<"------------------------------------------------"<<endl;
			cout<<lista[i].nome<<";"
			<<lista[i].sexo<<";"
			<<lista[i].nacionalidade<<";"
			<<lista[i].nascimento<<";"
			<<lista[i].genero
			<<endl;
			}
		}
	else if(opcao==2){
		int trechoInicial, trechoFinal;

		cout<<"Trecho inicial: ";
		cin>>trechoInicial;
		cout<<"Trecho Final: ";
		cin>>trechoFinal;

		if(trechoInicial<1 or trechoFinal>tamanho or trechoInicial>trechoFinal){
			cout<<"Trecho nao encontrado!"<<endl;
			return;
		}
		for(int i=trechoInicial-1;i<trechoFinal;i++){
			cout<<"------------------------------------------------"<<endl;
			cout<<lista[i].nome<<";"
			<<lista[i].sexo<<";"
			<<lista[i].nacionalidade<<";"
			<<lista[i].nascimento<<";"
			<<lista[i].genero
			<<endl;
		}

		}
		cout<<endl;
}

void menu(){
	cout<<"--------------------------------------"<<endl;
	cout<<"--------------Cantores----------------"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<endl;
	cout<<"1- Inserir novo(a) cantor(a)."<<endl;
	cout<<"2- Remover cantor(a)."<<endl;
	cout<<"3- Buscar cantor(a)."<<endl;
	cout<<"4- Ordenar cantores."<<endl;
	cout<<"5- Visualizar cantores"<<endl;
	cout<<"6- Salvar alteracoes."<<endl;
	cout<<"7- Sair"<<endl;
	
}

int main(){
	ifstream entrada("cantores.csv");

	if(!entrada.is_open()){
		cout<<"Erro ao abrir o arquivo!"<<endl;
		return 0;
	}

	string cabecalho;
	getline(entrada,cabecalho);

	int capacidade=40, tamanho=0;
	cantores *lista=new cantores[capacidade];
	cantores temp;
	char lixo;	

	while(getline(entrada,temp.nome,';')){
		entrada>>temp.sexo>>lixo;
		getline(entrada,temp.nacionalidade,';');
		entrada>>temp.nascimento>>lixo;
		getline(entrada,temp.genero);
						if(capacidade==tamanho){
							cantores *novaLista=new cantores[capacidade+10];
							copy(lista, lista + tamanho, novaLista);
							delete[] lista;
							lista=novaLista;
							capacidade+=10;
						}
						lista[tamanho]=temp;
						tamanho++;
					}
				
	int opcao;

	do{
		menu();
		cin>>opcao;

		if(opcao==1){
			inserirCantor(lista, tamanho, capacidade);
		}
		else if(opcao==2){
			removerCantor(lista, tamanho);
		}
		else if(opcao==3){
			buscarCantor(lista, tamanho);
		}
		else if(opcao==4){
			int opcao;

			cout<<"Como deseja ordenar?"<<endl;
			cout<<"1- Ordenar por nome."<<endl;
			cout<<"2- Ordenar por idade."<<endl;
			cout<<"Digite uma opcao: ";
			cin>>opcao;
			cout<<"Cantores ordenados!"<<endl;
			selectionSort(lista, tamanho, opcao);
		}
		else if(opcao==6){
			salvarAlteracoes(lista, tamanho);
		}
		else if(opcao==5){
			visualizarDados(lista, tamanho);
		}
		else if(opcao==7){
			cout<<"Programa finalizado!"<<endl;
		}
		else{
			cout<<"Opcao invalida!"<<endl;
		}
	 }while(opcao!=7);

	 delete[] lista;
	 entrada.close();

  return 0;

}

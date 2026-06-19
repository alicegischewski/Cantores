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
}

void buscarCantor(cantores lista[], int tamanho){
	string busca;
	cout<<"Deseja buscar registro por nome, sexo, nacionalidade, ano de nascimento ou genero musical?"<<endl;
	cin>>busca;
		if(busca=="Nome" or busca=="nome"){
			cout<<"Digite o nome: ";
			string nomeProcurado;
			cin.ignore();
			getline(cin, nomeProcurado);
			int pos=-1;
			bool encontrou=false;
				for(int i=0;i<tamanho and encontrou==false;i++){
					if(lista[i].nome==nomeProcurado){
						pos=i;
						encontrou=true;
					}
				}
					if(pos==-1){
						cout<<"Cantor(a) nao encontrado(a)!"<<endl;
					}else{
						cout<<"Deseja procurar quais informacoes?(posicao, sexo, nacionalidade, ano de nascimento, genero musical ou todos): "<<endl;
						string info;
						getline(cin, info);

						if(info=="posicao"){
							cout<<"Posicao: "<<(pos+1)<<endl;
						}
						else if(info=="sexo"){
							cout<<"Sexo: "<<lista[pos].sexo<<endl;
						}
						else if(info=="nacionalidade"){
							cout<<"Nacionalidade: "<<lista[pos].nacionalidade<<endl;
						}
						else if(info=="ano de nascimento"){
							cout<<"Ano de nascimento: "<<lista[pos].nascimento<<endl;
						}
						else if(info=="genero musical"){
							cout<<"Genero musical: "<<lista[pos].genero<<endl;
						}
						else if(info=="todos"){
						cout<<"Posicao: "<<(pos+1)<<endl
						<<"Nome: "<<lista[pos].nome<<endl
						<<"Sexo: "<<lista[pos].sexo<<endl
						<<"Nacionalidade: "<<lista[pos].nacionalidade<<endl
						<<"Ano de nascimento: "<<lista[pos].nascimento<<endl
						<<"Genero musical: "<<lista[pos].genero<<endl;
						}
						else{
							cout<<"Informacao invalida!"<<endl;
						}
					}
			}
}

void selectionSort(cantores lista[], int tamanho){
	int menor;
	cantores aux;
	
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
}

void visualizarDados(cantores lista[], int tamanho){
	cout<<"--------------------Visualizacao-dos-cantores--------------------"<<endl;
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

void menu(){
	cout<<"--------------------------------------"<<endl;
	cout<<"--------------Cantores----------------"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<endl;
	cout<<"1- Inserir novo(a) cantor(a)."<<endl;
	cout<<"2- Remover cantor(a)."<<endl;
	cout<<"3- Buscar cantor(a)."<<endl;
	cout<<"4- Ordenar cantores."<<endl;
	cout<<"5- Vizualizar cantores"<<endl;
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
			selectionSort(lista, tamanho);
			cout<<"Cantores ordenados!"<<endl;
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

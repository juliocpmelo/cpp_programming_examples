#include <iostream>

#include <string>

#include <map>

using namespace std;

void simples(){
	
	/*inicialização inline*/
	map<const int,string> m = {{1,"julio"},{2,"isaac"}, {3, "renan"}};
	
	map<int, string> alunos;
	alunos.insert(pair<int, string>(1,"Maria"));
	alunos.insert(pair<int, string>(2,"Joao"));

	/*insere elemento na chave 3*/
	alunos[3] = "Ana";

	//if(alunos[10] == "")// não é uma boa prática
	
	/*remove elemento com chave 2*/
	alunos.erase(2);                                 

	/*acessa posição 3*/
	cout<<"Aluno na posição 3 "<<alunos[3]<<endl;

	/*acessa posição 4 (constroi um a string "" naquela poisção)*/
	cout<<"Aluno na posição 4 "<<alunos[4]<<endl;

	/*acessar um elemento acaba criando uma nova string*/
	if(alunos[4] == "")
		cout<<"Não tem aluno na posição 4"<<endl;
	
	/*para testar se existe sem criar usamos count*/
	if(alunos.count(5) == 0)
		cout<<"Não tem aluno na posição 5"<<endl;
	
}

void iterators(){
	
	map<int, string> alunos;
	alunos.insert(pair<int, string>(1,"Maria"));
	alunos.insert(pair<int, string>(2,"Joao"));

	/*insere elemento na chave 3*/
	alunos[3] = "Ana";
	
	/*remove elemento com chave 2*/
	alunos.erase(2);                                 

	map<int, string>::iterator it;
	for (it = alunos.begin(); it != alunos.end(); ++it)     // Impressao dos valores na map
		cout << it->first << " - " << it->second << endl;
	
	/*busca por elementos na map*/
	
	int i;
	cout<<"Digite a matrícula do aluno que quer buscar: ";
	cin>>i;
	map<int, string>::iterator busca = alunos.find(i);
	/*quando não encontra retorna end()*/
	if(busca != alunos.end())
		cout<<"aluno com matricula "<<i<<" é "<<busca->second<<endl;
	else
		cout<<"aluno com matricula "<<i<<" não encontrado"<<endl;

	cout<<"Digite a matrícula do aluno que quer remover: ";
	cin>>i;
	busca = alunos.find(i);
	if(busca !=alunos.end())
		alunos.erase(busca);

	cout<<"Depois da remoção do aluno com matrícula "<<i<<endl;
	for (it = alunos.begin(); it != alunos.end(); ++it)     // Impressao dos valores na map
		cout << it->first << " - " << it->second << endl;
	
}

int main() {
	
	simples();

	iterators();

	return 0;
}

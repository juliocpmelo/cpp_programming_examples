#include <iostream>

#include <string>

#include <vector>

using namespace std;

void simples(){
	vector<int> v;
	/*insere elementos no vetor*/
	
	for (int i = 1; i <= 10; i++)
		v.push_back(rand()%10);
	
	v[0] = 42; //atribui elementos (so funciona se já tiver algum elemento nesta posição)

	// Iteracao sobre os elementos do vetor
	for (int i = 0; i < (int)v.size(); i++) {      
			std::cout << v[i] << " ";
	}
	cout<<endl;
	

	vector<int> v2 = {1,23,5,67,1}; //inicializador lista
	for (int i = 0; i < (int)v2.size(); i++) {      
			std::cout << v2[i] << " ";
	}
	cout<<endl;

	v2.resize(40,0); //aumenta o tamanho de v2, para caber 40 elementos, põe 0 nos 'novos' elementos que precisem ser inseridos.

	v2[50] = 42; //agora podemos

	for (int i = 0; i < (int)v2.size(); i++) {      
			std::cout << v2[i] << " ";
	}
	cout<<endl;

}

void iterators(){

	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);

	// Iteracao sobre os elementos do vetor
	for (int i = 0; i < (int)v.size(); i++) {      
			std::cout << v[i] << " ";
	}
	cout<<endl;

	vector<int>::iterator it; //usando iterator
	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	cout<<endl;

	vector<int>::reverse_iterator rit; //usando iterator
	for (rit = v.rbegin(); rit != v.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	cout<<endl;


	/*erase, apaga usando iterators*/
	cout<<"Qual elemento quer apagar de v? ";
	int elemento;
	cin>>elemento;
	for (it = v.begin(); it != v.end(); ++it) {
		if(*it == elemento){
			v.erase(it);
			break; //NAO pode continuar pois erase invalida o iterator it atual!
		}
	}

	cout<<"v após apagar "<<elemento<<endl;
	for (int i = 0; i < (int)v.size(); i++) {      
			std::cout << v[i] << " ";
	}
	cout<<endl;

	
	int i = 4;
	v.erase(v.begin()+i); /*apagar o elemento na posição i*/
	cout<<"v após apagar elemento posição "<<i<<endl;
	for (int i = 0; i < (int)v.size(); i++) {      
			std::cout << v[i] << " ";
	}
	cout<<endl;
}

void mais(){
	vector<int> v;
	/*insere elementos no vetor*/
	for (int i = 0; i < 20; i++)
		v.push_back(rand()%10);

	for (int i = 0; i < (int)v.size(); i++) {      
			std::cout << v[i] << " ";
	}
	cout<<endl;

	/*operador =, copia v*/
	vector<int> v2 = v;
	cout<<"v2"<<endl;
	for (int i = 0; i < (int)v2.size(); i++) {      
			std::cout << v2[i] << " ";
	}
	cout<<endl;

	if(v == v2){
		cout<<"operador == compara dois vetores pelos seus elementos"<<endl;
	}

	v2[0]++; //v2 agora é maior que v
	if(v > v2){
		cout<<"operador > compara dois vetores pelos seus elementos"<<endl;
	}
	else{
		cout<<"Quando o tamanho é igual o operador < e > em cada elemento é usado"<<endl;
	}

	
	int i=2;
	int j=6;
	v2.erase(v2.begin()+i, v2.begin()+j); /*apagar o elementos entre posição a posição i e j*/

	cout<<"v2 após apagar elementos nas posições "<<i<<" à "<<j<<endl;
	for (int i = 0; i < (int)v2.size(); i++) {      
			std::cout << v2[i] << " ";
	}
	cout<<endl;

	i = 2;
	int elemento = 24;
	cout<<"v2, após insersão de "<<elemento<<" na posição "<<i<<endl;
	v2.insert(v2.begin()+i, elemento);
	for (int i = 0; i < (int)v2.size(); i++) {      
			std::cout << v2[i] << " ";
	}
	cout<<endl;

}

int main() {
	
//	simples();

	iterators();

	//mais();

	return 0;
}

#include <iostream>

#include <string>

#include <list>

using namespace std;

void simples(){
	list<int> l;
	/*insere no inicio*/
	l.push_front(1);
	/*insere no final*/
	l.push_back(2);

	for(int i=0; i<10;i++){
		l.push_back(rand()%10);
	}

	cout<<"primeiro elemento "<<l.front()<<endl;
	cout<<"último elemento "<<l.back()<<endl;

	/*remove TODOS elementos usando o operador == dos valores*/
	l.remove(1); 

	cout<<"primeiro elemento "<<l.front()<<endl;
}

void iterators(){
	list<int> l;

	for(int i=0; i<10;i++)
		l.push_back(rand()%10);

	list<int>::iterator it, it2; 
	
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";

	int i = 1;
	it = l.begin();
	std::advance(it, i); //soma it com i
	l.insert(it, rand()%20); //insere na posição i
	it = l.begin();
	i = 3;
	std::advance(it, i);
	l.insert(it, rand()%20); //insere na posição 
	it = l.begin();
	i = 5;
	std::advance(it, i);
	l.insert(it, rand()%20); //insere na posição 

	cout<<"l após inserção de elementos"<<endl;
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;

	/*copia conteúdos de l para l2, usando o operador =*/
	list<int> l2 = l;

	i = 2;
	it = l2.begin();
	advance(it, i);
	l2.erase(it); //remove na posição i
	cout<<"l2 após remoçao do elemento na posição "<<i<<endl;
	for (it = l2.begin(); it != l2.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;

	int j = 4;
	i = 1;
	it2 = it = l2.begin();
	advance(it, i);
	advance(it2, j);
	l2.erase(it, it2); //elementos entre i (inclusive) e j (não incluso)
	cout<<"v após remoçao dos elementos entre "<<i <<" e "<<j<<endl;
	for (it = l2.begin(); it != l2.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;

}

void mais(){
	
	list<int> l;

	for(int i=0; i<10;i++)
		l.push_back(rand()%10);

	list<int>::iterator it, it2; 
	
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;
	/*insere usando uma lista/array de elementos*/
	
	l.insert(l.begin(),{1,2,34,5,2});
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;

	l.sort(); //ordena a lista
	cout<<"l depois de sort()"<<endl;
  for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;
	
	l.unique(); //remove elementos duplicados (que sejam consecutivos) usando o operador == dos elementos
	cout<<"l depois de unique()"<<endl;
  for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;

	l.assign(20,0); //reinicializa a lista com 20 valores 0
	cout<<"l depois de assign()"<<endl;
  for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	cout<<endl;
}



int main() {
	
	simples();

//	iterators();

//	mais();

	return 0;
}

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printElement(T ele){
	cout<<ele<<" ";
}

template<typename T>
void printlnElement(T ele){
	cout<<ele<<endl;
}

/*forma estática, mais simples pra usar com find_if/count_if*/
bool menorQue10(int ele){
	return ele < 10;
}

/*functor testa se um valor é menor do que um parametro dado*/
class isLt {
		int i_;
		public:
			isLt(double i) : i_(i) {}
    	bool operator()(double v){ 
				return v < i_;
			}
};


void sem_modificacao(){
	vector<double> v = {23.4, 12.21, 21.2, 0.3};
	/*conta quantidade de vezes que um elemento aparece no vector*/
	map<const int,string> m = {{1,"julio"},{2,"isaac"}, {3, "renan"}};

	list<int> l = {1, 124, 1, 21, 4, 2, 14, 5, 1};
	
	/*count*/
	int c = std::count(v.begin(), v.end(), 12.21);
	cout<<"numero 12.21 aparece "<<c<<" vezes"<<endl;
	c = std::count(v.begin(), v.end(), 0);
	cout<<"numero 0 aparece "<<c<<" vezes"<<endl;

	c = std::count(m.begin(), m.end(), pair<const int,string>(1,"julio"));

	cout<<"par [1,\"julio\"] aparece "<<c<<" vez"<<endl;

	c = std::count(l.begin(), l.end(), 1);
	cout<<"numero 1 aparece "<<c<<" vezes"<<endl;


	/*find*/
	vector<double>::iterator it_v;
	double n = 12.21;
	it_v = std::find(v.begin(), v.end(), n);
	
	if(it_v != v.end())
		cout<<"Numero "<<n<<" encontrado"<<endl;
	else
		cout<<"Numero "<<n<<" não encontrado"<<endl;
	
	map<const int,string>::iterator it_m;
	pair<const int,string> p(1,"julio");
	
	it_m = std::find(m.begin(), m.end(), p);
	if(it_m != m.end())
		cout<<"Par "<<p.first<<","<<p.second<<" encontrado"<<endl;
	else
		cout<<"Par "<<p.first<<","<<p.second<<" não encontrado"<<endl;

	
	list<int>::iterator it_l;
	int k = 1;
	it_l = std::find(l.begin(), l.end(), k);
	if(it_l != l.end())
		cout<<"Numero "<<k<<" encontrado"<<endl;
	else
		cout<<"Numero "<<k<<" não encontrado"<<endl;
	
	/*executa uma função em cada elemento*/
	std::for_each(l.begin(),l.end(),printlnElement<int>);

	std::for_each(v.begin(),v.end(),printlnElement<double>);

	/*pra fazer na map precisa especializar o template*/

	/*find_if*/
	it_v = std::find_if(v.begin(), v.end(), menorQue10);
	if(it_v != v.end())
		cout<<"Numero menor que 10 encontrado: "<<*it_v<<endl;
	else
		cout<<"Numero "<<n<<" não encontrado"<<endl;
	
	/*retorna o primeiro elemento que seja menor do que n*/
	n = 5;
	it_v = std::find_if(v.begin(), v.end(), isLt(n));
	if(it_v != v.end())
		cout<<"Numero menor que "<<n<<" encontrado "<<*it_v<<endl;
	else
		cout<<"Numero "<<n<<" não encontrado"<<endl;
	
	
	/*count_if conta elementos menores do que 10, também é possível  usar funções como parâmetros do find_if*/
	c = std::count_if(v.begin(), v.end(), menorQue10);
	cout<<c<<" valores menores que 10"<<endl;
}

void com_modificacao(){
	
	
	vector<int> numeros;
	cout<<"Vetor original"<<endl;
	for (int i = 1; i <= 10; i++)
		numeros.push_back(i);
	std::for_each(numeros.begin(),numeros.end(),printElement<int>);
	cout<<endl;


	/*transforma o vetor na ordem inversa*/
	std::reverse(numeros.begin(), numeros.end());
	cout<<"depois do reverse"<<endl;
	std::for_each(numeros.begin(),numeros.end(),printElement<int>);
	cout<<endl;

	//cout<<"depois do random_suffle"<<endl;
	std::random_shuffle(numeros.begin(), numeros.end());
	cout<<"depois do random_suffle"<<endl;
	std::for_each(numeros.begin(),numeros.end(),printElement<int>);
	cout<<endl;

	
	std::replace(numeros.begin(), numeros.end(), 10, 100);
	std::replace(numeros.begin(), numeros.end(), 9, 100);
	cout<<"depois do replace"<<endl;
	std::for_each(numeros.begin(),numeros.end(),printElement<int>);
	cout<<endl;

	std::fill(numeros.begin(), numeros.end(), 0);
	cout<<"depois do fill"<<endl;
	std::for_each(numeros.begin(),numeros.end(),printElement<int>);
	cout<<endl;


}


int main(){
	//sem_modificacao();

	com_modificacao();
	return 0;
}
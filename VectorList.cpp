#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	vector<int> v;//Arreglo dinamico
	cout<<"Maximo: "<<v.max_size()<<endl;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	cout<<"Elementos dentro vector: "<<v.size()<<endl;
	cout<<"Tamaño arreglo: "<<v.capacity()<<endl;
	//iterando con for
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<",";
	}
	cout<<endl;
	//iterando con iterador
	//El iterador es un apuntador al elemento actual
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		cout<<*it<<",";
	}
	cout<<endl;
	list<int> l;//Lista dinamica ligada
	cout<<"Maximo: "<<l.max_size()<<endl;
	l.push_back(3);
	l.push_back(2);
	l.push_back(1);
	cout<<"Elementos dentro lista: "<<l.size()<<endl;
	//Aqui no hay acceso por posicion([]), ni se puede iterar con for. A fuerza se tiene que iterar con un iterador
	//Revisar cppreference, ya que el iterador puede empezar desde rbegin, que es el final de la lista y terminar en rend, que es el inicio. La r es de reverse.
	for(list<int>::iterator it=l.begin(); it!=l.end(); it++){
		cout<<*it<<",";
	}
	cout<<endl;
	
	
	
	return 0;
}
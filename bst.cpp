#include <iostream>

using namespace std;
template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *right;
	Nodo<T> *left;
	
	Nodo(){
		value=NULL;
		right=NULL;
		left=NULL;
	}
	
	Nodo(T val){
		value=val;
		right=NULL;
		left=NULL;
	}
};


template <class T>
class BST{
	public:
	Nodo<T> *raiz;
	
	BST(){
		raiz=NULL;
	}
	
	void insertar(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(raiz==NULL){
			raiz=nuevo;
		}else{
			Nodo<T> *temp=raiz;
			while(temp!=NULL){
				if(temp->value==value){
					return;
				}
				else if(value<temp->value){
					if(temp->left==NULL){
						temp->left=nuevo;
					}else{
						temp=temp->left;
						return;
					}
				}
				else if(value>temp->value){
					if(temp->right==NULL){
						temp->right=nuevo;
					}else{
						temp=temp->right;
						return;
					}
				}
			}
		}
	}
	
	void inorden(){
			inordenAux(raiz);
			cout<<endl;
	}
	
	void inordenAux(Nodo<T> *actual){
		if(actual==NULL){
			return;
		}
		inordenAux(actual->left);
		cout<<actual->value<<", ";
		inordenAux(actual->right);
	}
};

int main(){
	BST<int> b;
	b.insertar(10);
	b.insertar(20);
	b.inorden();
}

#include <iostream>


using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo *next;
	
	Nodo(){
		value=NULL;
		next=NULL;
	}
	
	Nodo(T val){
		value=val;
		next=NULL;
	}
};

template <class T>
class LinkedList{
	Nodo<T> *head;
	public: 
		LinkedList(){
			head=NULL;
		}
		void append(Nodo<T>* nuevo){
			if(head==NULL){
				head=nuevo;
			}else{
				Nodo<T> *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=nuevo;
			}
		}
		
		void append(T value){
			Nodo<T> *nuevo=new Nodo<T>(value);
			append(nuevo);
		}
		
		void insertar(int pos, Nodo<T> *nuevo){
			int i=0;
			if (head==NULL && pos!=0){
				return;
			}
			Nodo<T> *temp=head;
			if(pos==0){
				nuevo->next=head;
				head=nuevo;
				return;
			}
			while(i<(pos-1)&&temp->next!=NULL){
				temp=temp->next;
				i++;
			}
			if(i!=(pos-1)){
				return;
			}
			nuevo->next=temp->next;
			temp->next=nuevo;
		}
		
		void insertar(int pos, T value){
			Nodo<T> *nuevo=new Nodo<T>(value);
			insertar(pos, nuevo);
		}
		
		void remove(T value){
			//checamos si es el primer elemento
			if(head->value==value){
				head=head->next;
				return;
			}else{
				Nodo<T> *temp=head;
				while(temp!=NULL){
					if (temp->next==NULL){
						return;//Si el siguiente es NULL y no lo encontramos, paramos.
					}else if(temp->next->value==value){
						break;//si el siguiente elemento es el buscado, paramos.
					}else{
						temp=temp->next;//no es, avanzamos
					}
				}
				temp->next=temp->next->next;
			}
			
		}
		
		void printList(){
			Nodo<T> *temp=head;
			while(temp!=NULL){
				cout<<temp->value<<", ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		
		
};

int main(){
	LinkedList<int> l;
	l.append(5);
	l.append(4);
	l.append(1);
	l.printList();
	l.insertar(2,10);
	l.printList();
	l.remove(11);
	l.printList();
}
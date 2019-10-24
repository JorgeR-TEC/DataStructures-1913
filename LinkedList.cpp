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
	l.append(3);
	l.printList();
	l.insertar(15,10);
	l.printList();
}
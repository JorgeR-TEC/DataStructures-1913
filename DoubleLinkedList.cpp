#include <iostream>
using namespace std;
template <class T>
class Nodo{
	public:
		T value;
		Nodo* next;
		Nodo* before;
		
		Nodo(){
			value=NULL;
			next=NULL;
			before=NULL;
		}
		
		Nodo(T val){
			value=val;
			next=NULL;
			before=NULL;
		}
};

template <class T>
class doubleLinkedList{
	public: 
		Nodo<T> *head=NULL;
		
		void append(Nodo<T>* nuevo){
			if(head==NULL){
				head=nuevo;
			}else{
				Nodo<T> *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=nuevo;
				nuevo->before=temp;
			}
		}
		
		void append(T value){
			Nodo<T> *nuevo=new Nodo<T>(value);
			append(nuevo);
		}
		
		void insertar(int pos, T value){
			Nodo<T> *nuevo=new Nodo<T>(value);
			insertar(pos, nuevo);
		}
		
		void insertar(int pos, Nodo<T> *nuevo){
			int i=0;
			if (head==NULL && pos!=0){
				return;
			}
			Nodo<T> *temp=head;
			if(pos==0){
				nuevo->next=head;
				head->before=nuevo;
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
			temp->next->before=nuevo;
			nuevo->before=temp;
			temp->next=nuevo;
		}
		
		void printList(){
			Nodo<T> *temp=head;
			while(temp!=NULL){
				cout<<temp->value<<", ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		
		void remove(T value){
			Nodo<T> *temp=head;
			while(temp!=NULL){
				if(temp->value==value){
					if(temp->next!=NULL){
						temp->next->before=temp->before;
					}
					if(temp->before!=NULL){
						temp->before->next=temp->next;
					}
					if(temp==head){
						head=temp->next;
					}
					return;
				}else{
					temp=temp->next;
				}
			}
			
		}
};



int main(){
	doubleLinkedList<int> l;
	l.append(5);
	l.append(4);
	l.append(1);
	l.printList();
	l.insertar(2,10);
	l.printList();
	l.remove(5);
	l.printList();
}
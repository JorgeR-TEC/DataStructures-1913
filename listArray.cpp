#include <iostream>
using namespace std;
template <class T>
class Lista{
	public:
		int size;
		int count;
		T *values;
		
		Lista(){
			size=1024;
			count=0;
			values=new T[size];
		}
		
		Lista(int s){
			size=s;
			count=0;
			values=new T[size];
		}
		
		~Lista(){
			delete[](values);
		}
		
		void insertar(T value){
			if(count<size){
				values[count]=value;
				count++;
			}else{
				T *copia=new int[size*2];
				for(int i=0; i<size; i++){
					copia[i]=values[i];
				}
				delete[](values);
				values=copia;
				size=size*2;
				insertar(value);
			}
		}
		
		T operator[](int index){
			if(index<count){
				return values[index];
			}
		}
		
		
};


int main(){
	Lista<int> l(2);
	l.insertar(5);
	l.insertar(4);
	l.insertar(20);
	cout<<l.count<<endl;
	cout<<l.size<<endl;
	cout<<l[2]<<endl;
}
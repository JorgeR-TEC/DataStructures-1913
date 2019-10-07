#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <class T>
class Ordenar{
	public:
		virtual void sort(T* arreglo, int size);
		void intercambiar(T* arreglo, int a, int b){
			T temp=arreglo[a];
			arreglo[a]=arreglo[b];
			arreglo[b]=temp;
		}
		void imprimirArreglo(T *arreglo, int size){
			for(int i=0; i<size;i++){
				cout<<arreglo[i]<<",";
			}
			cout<<endl;
		}
};

template <class T>
class Selectionsort : public Ordenar<T>{
	public:
	void sort(T* arreglo, int size){
		
		for(int i=0; i<size-1; i++){
			int minimo=i;
			for(int j=i+1; j<size; j++){
				if(arreglo[j]<arreglo[minimo]){
					minimo=j;
				}
			}
			this->intercambiar(arreglo, i, minimo);
		}
	}
};
template <class T>
class Bubblesort : public Ordenar<T>{
	public:
	void sort(T* arreglo, int size){
		for(int i=0; i<size;i++){
			for(int j=0; j<size-1; j++){
				if(arreglo[j]>arreglo[j+1]){
					this->intercambiar(arreglo, j, j+1);
				}
			}
		}
	}
};

template <class T>
class Insertionsort : public Ordenar<T>{
	public:
	void sort(T* arreglo, int size){
		for(int i=1; i<size;i++){
			for(int j=i; j>0; j--){
				if(arreglo[j]<arreglo[j-1]){
					this->intercambiar(arreglo, j, j-1);
				}else{
					break;
				}
			}
		}
	}
};


int main(){
	srand(time(0));//srand es seed rand, que nos indica la semilla (numero inicial) del generador de numeros aleatorios. Le estoy diciendo time(0) para que tome el tiempo actual del sistema como semilla y asi garantizar que cada ejecucion genere numeros aleatorios diferentes
	Insertionsort<int> s;
	int size=5;
	int arreglo[size];
	for(int i=0; i<size;i++){
		arreglo[i]=rand()%100;
	}
	s.imprimirArreglo(arreglo, size);
	s.sort(arreglo,size);
	s.imprimirArreglo(arreglo, size);
}

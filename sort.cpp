#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <class T>
class Ordenar{
	public:
		virtual void sort(T* arreglo, int size)=0;
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
class SelectionSort : public Ordenar<T>{
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
class BubbleSort : public Ordenar<T>{
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
class InsertionSort : public Ordenar<T>{
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

template <class T>
class MergeSort: public Ordenar<T>{
	public:
	void sort(T *arreglo, int size){
		sortAux(arreglo, 0, size-1);
	}
	private:
	void sortAux(T *arreglo, int lo, int hi){
		if(lo<hi){
			int mid=lo+(hi-lo)/2;
			sortAux(arreglo, lo, mid);
			sortAux(arreglo, mid+1, hi);
			merge(arreglo, lo, mid, hi);
		}
	}
	
	void merge(T *arreglo, int lo, int mid, int hi){
		int lSize=mid-lo+1;
		int rSize=hi-mid;
		T *left=(T *)malloc(sizeof(T)*lSize);
		T *right=(T *)malloc(sizeof(T)*rSize);
		for(int i=0; i<lSize; i++){
			left[i]=arreglo[lo+i];
		}
		for(int i=0; i<rSize; i++){
			right[i]=arreglo[mid+1+i];
		}
		int l=0;
		int r=0;
		int pos=lo;
		while(l<lSize && r<rSize){
			if(left[l]<=right[r]){
				arreglo[pos]=left[l];
				l++;
			}else{
				arreglo[pos]=right[r];
				r++;
			}
			pos++;
		}
		while(l<lSize){
			arreglo[pos]=left[l];
			l++;
			pos++;
		}
		while(r<rSize){
			arreglo[pos]=right[r];
			r++;
			pos++;
		}
	}
};

template <class T>
class QuickSort: public Ordenar<T>{
	public:
	void sort(T *arreglo, int size){
		sortAux(arreglo, 0, size-1);
	}
	private:
	void sortAux(T *arreglo, int lo, int hi){
		if(lo<hi){
			int j=partition(arreglo, lo, hi);
			sortAux(arreglo, lo, j-1);
			sortAux(arreglo, j+1, hi);
		}
	}
	
	int partition(T * arreglo, int lo, int hi){
		T pivote=arreglo[lo];
		int i=lo+1;
		int j=hi;
		while(true){
			while(arreglo[i]<pivote){
				i++;
			}
			while(arreglo[j]>pivote){
				j--;
			}
			if(i>=j){
				break;
			}else{
				this->intercambiar(arreglo, i,j);
			}
		}
		this->intercambiar(arreglo, lo, j);
		return j;
	}
};


int main(){
	srand(time(0));//srand es seed rand, que nos indica la semilla (numero inicial) del generador de numeros aleatorios. Le estoy diciendo time(0) para que tome el tiempo actual del sistema como semilla y asi garantizar que cada ejecucion genere numeros aleatorios diferentes
	QuickSort<int> s;
	int size=5;
	int arreglo[size];
	for(int i=0; i<size;i++){
		arreglo[i]=rand()%100;
	}
	s.imprimirArreglo(arreglo, size);
	s.sort(arreglo,size);
	s.imprimirArreglo(arreglo, size);
}

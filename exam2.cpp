#include <iostream>

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
			while(arreglo[i]<=pivote){
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

int busquedaOrdenada1(int *arreglo, int size, int buscado){
	for(int i=0; i<size; i++){
		if(arreglo[i]==buscado){
			return i;
		}else if(arreglo[i]>buscado){
			return -1;
		}
	}
	return -1;

}


class LFO{
	public:
		int size=300;
		int cantidad=0;
		int pacientes[300];
		QuickSort<int> s;
		
	
	void insertar(int numero){
		if(cantidad<300){
			pacientes[cantidad]=numero;
			cantidad++;
			s.sort(pacientes, cantidad);
		}else{
			cout<<"no se pudo agregar paciente"<<endl;
		}
	}
	
	int verificarTurno(int numero){
		busquedaOrdenada1(pacientes, cantidad, numero);
	}
	
	int repetido(int numero){
		return repetidoAux(0, numero, 0);
	}
	
	int repetidoAux(int repetidos, int numero, int index){
		if(index==cantidad){
			return repetidos;
		}else{
			if(pacientes[index]==numero){
				return repetidoAux(repetidos+1, numero, index+1);
			}else{
				return repetidoAux(repetidos, numero, index+1);
			}
		}
	}
};

int main(){
	LFO f;
	f.insertar(10);
	f.insertar(20);
	f.insertar(30);
	cout<<f.verificarTurno(10)<<endl;
	cout<<f.verificarTurno(20)<<endl;
	cout<<f.verificarTurno(15)<<endl;
	cout<<f.repetido(10)<<endl;
	f.insertar(10);
	cout<<f.verificarTurno(20)<<endl;
	cout<<f.repetido(10)<<endl;
	
}
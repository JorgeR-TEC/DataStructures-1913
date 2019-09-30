#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busquedaSecuencial(int *arreglo, int size, int buscado){
	for(int i=0; i<size; i++){
		if(arreglo[i]==buscado){
			return i;
		}
	}
	return -1;

}


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

int ordenada2Aux(int *arreglo, int lo, int hi, int buscado){
	for(int i=lo; i<=hi; i++){
		if(arreglo[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaOrdenada2(int *arreglo, int size, int buscado){
	int paso=50;
	for(int i=0; i<size; i+=paso){
		if((i+paso)<size){//caso normal
			if(arreglo[i+paso]>buscado){
				return ordenada2Aux(arreglo, i, i+paso, buscado);
			}
		}else{//ultimo tramo
			if(arreglo[size-1]>buscado){
				return ordenada2Aux(arreglo, i, size-1, buscado);
			}
		}
	}
	return -1;

}

int main(){
	int size=10000;
	int a[size];
	
	for(int i=0; i<size; i++){
		a[i]=i;
		if(i==100){
			a[i]=99;
		}
	}
	
	auto inicio=high_resolution_clock::now();
	int posicion=busquedaSecuencial(a, size, 1000);
	auto fin=high_resolution_clock::now();
	cout<<"posicion: "<<posicion<<endl;
	auto duracion=fin-inicio;
	cout<<"tiempo: "<<duration_cast<microseconds>(duracion).count()<<endl;
	//
	inicio=high_resolution_clock::now();
	posicion=busquedaOrdenada1(a, size, 1000);
	fin=high_resolution_clock::now();
	cout<<"posicion Ordenada: "<<posicion<<endl;
	duracion=fin-inicio;
	cout<<"tiempo Ordenada1: "<<duration_cast<microseconds>(duracion).count()<<endl;
	//ordenada2
	inicio=high_resolution_clock::now();
	posicion=busquedaOrdenada2(a, size, 1000);
	fin=high_resolution_clock::now();
	cout<<"posicion Ordenada2: "<<posicion<<endl;
	duracion=fin-inicio;
	cout<<"tiempo Ordenada2: "<<duration_cast<microseconds>(duracion).count()<<endl;
	
}
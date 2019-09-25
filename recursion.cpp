#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

int mayorRec(int *arreglo, int size, int index, int valor){
	if(index==size){
		return valor;
	}else{
		if(arreglo[index]>valor){
			return mayorRec(arreglo, size, index+1,arreglo[index]); 
		}else{
			return mayorRec(arreglo, size, index+1,valor); 
		}
	}
}


int mayor(int *arreglo, int size){
	return mayorRec(arreglo, size, 0, arreglo[0]);
}
int cantidadLetras(char* s, int index){
	if(s[index]=='\0'){
		return index;
	}else{
		cantidadLetras(s, index+1);
	}
	
}


int factorialRecursivo(int n){
	if (n == 0){
		return 1;
	}else{
		return n * factorialRecursivo(n-1);
	}
}

int factorialCola(int n, int a){
	if (n == 0){
		return a;
	}else{
		return factorialCola(n-1, n*a);
	}
}

int factAux(int n){
	return factorialCola(n, 1);
}



int factorialNormal(int n){
	int res=1;
	while (n>0){
		res=res*n;
		n=n-1;
	}
	return res;
}

int main(){
	cout<<factAux(5)<<endl;
	int arr[6]={1,2,34,5,89,2};
	cout<<mayor(arr, 6)<<endl;;
	char* s="perros";
	cout<<cantidadLetras(s, 0)<<endl;
	return 0;
}
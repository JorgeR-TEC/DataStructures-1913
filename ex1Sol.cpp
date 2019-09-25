#include <iostream>
using namespace std;

class Sort{
	public:
		virtual void ordenar(int *a, int size)=0;
		
		void intercambiar(int *a, int p1, int p2, int &mayor){
			int temp=*(a+p1);//*(a+p1) es igual a[p1]
			a[p1]=*(a+p2);//*(a+p2) es igual a[p1]
			a[p2]=temp;
			if (mayor<a[p1]){
				mayor=a[p1];
			}
			if(mayor<a[p2]){
				mayor=a[p2];
			}
		}
};

class LuckySort: public Sort{
	public: 
		void ordenar(int *a, int size){
			int temp=0;
			intercambiar(a, 0, size-1, temp);
			//le mando temp por que no me importa que valor sea. intercambiar esta disponible por que es la misma clase.
		}
};

void printArray(int a[], int n){
	cout<<"{"<<a[0];
	for(int i=1; i<n; i++){
		cout<<","<<a[i];
	}
	cout<<"}"<<endl;
}

int main(){
	LuckySort L;
	int size=4;
	int *a=new int[size];
	a[0]=4;
	a[1]=3;
	a[2]=2;
	a[3]=1;
	int mayor=0;
	printArray(a, size);
	L.intercambiar(a, 1,2, mayor);
	printArray(a, size);
	L.ordenar(a,size);
	printArray(a, size);
	cout<<mayor<<endl;
	
	
	return 0;
}
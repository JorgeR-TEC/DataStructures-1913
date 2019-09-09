#include <iostream>
using namespace std;
int f(int copia, int &referencia, int *apuntador){
	copia++;
	referencia++;//modifica
	*apuntador=(*apuntador)+1;//modifica
	return copia+referencia+*apuntador;
}

int main(){
	int a=10;
	int b=20;
	int c=30;
	cout<<"variables antes de función"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	cout<<"c: "<<c<<endl;
	f(a,b,&c);
	cout<<"variables despues de función"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	cout<<"c: "<<c<<endl;
	return 0;
}
#include <iostream>
using namespace std;

int main(){
	int b=56;
	int *a=&b;//int * significa apuntador a entero
	//a es el nombre de variable
	//= asignacion
	//&dame la direccion de la siguiente variable
	//b variable b
	cout<<b<<endl;
	cout<<a<<endl;
	cout<<*a<<endl;
	return 0;
}
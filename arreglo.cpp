#include <iostream>

using namespace std;

int main(){
	int *arreglo=new int[4];
	arreglo[0]=10;
	arreglo[1]=20;
	arreglo[2]=30;
	cout<<arreglo[2]<<endl;
	delete[] arreglo;
	return 0;
}
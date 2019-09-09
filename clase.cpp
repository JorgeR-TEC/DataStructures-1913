#include <iostream>

using namespace std;

class Ejemplo{
	public:
		int size;
		int *arreglo;
		Ejemplo(int s){
			size=s;
			arreglo= new int[size];
		}
		~Ejemplo(){
			delete[] arreglo;
		}
};

int main(){
	Ejemplo e(5);
	e.arreglo[0]=120;
	cout<<e.arreglo[0]<<endl;
	return 0;
}
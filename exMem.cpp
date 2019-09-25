#include <iostream>
using namespace std;
void printArray(int a[], int n){
	cout<<"{"<<a[0];
	for(int i=1; i<n; i++){
		cout<<","<<a[i];
	}
	cout<<"}"<<endl;
}

int main(){
	int size=4;
	int *a=new int[size];
	a[0]=4;
	a[1]=3;
	a[2]=2;
	a[3]=1;
	printArray(a, size);
	
	return 0;
}
#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	
	int numeros[] = {1,2,3,4,5};
	int *dir_numeros; 
	
	dir_numeros = numeros;
	
	
	for(int i =0; i<5 ;i++){
	    
	    cout<<"\nValor: "<< dir_numeros[i]<< '\n';
        cout<<"\nApuntador: "<< &dir_numeros[i]<< '\n';
	    cout<<"\nValor: "<< numeros[i]<< '\n';
        cout<<"\nApuntador: "<< &numeros[i]<< '\n';
	    
	}
	

	getch();
	return 0;
	
}
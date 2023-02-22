
#include <stdlib.h>
#include <time.h>
#include<iostream>

int main(int argc, char** argv) {
	
	int NumeroAleatorio, Numero;
    srand(time(NULL));
    
    NumeroAleatorio = 1 + rand() % 100;
    
    std::cout << "Este programa hace un numero aleatorio y lo tienes que adivinar\n\n";
    do{
    	std::cout << "Dame un numero: ";
    	std::cin >> Numero;
    	
    	if(Numero > NumeroAleatorio){
    		std::cout << "El numero dado es mayor al numero aleatorio\nIntenta nuevamente :)\n";
		}
		if(Numero < NumeroAleatorio){
			std::cout << "El numero dado es menor al numero aleatorio\nIntenta nuevamente :)\n";
		}
    	
	}while(NumeroAleatorio != Numero);
	std::cout << "El numero aleatorio era: " << NumeroAleatorio;
    return 0;
}

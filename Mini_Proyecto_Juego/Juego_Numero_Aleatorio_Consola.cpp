#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int Intentos = 5, NumeroAleatorio;
int* Apuntador_NumeroAleatorio;

void Validar_Numero(int);

int main(int argc, char** argv) {
	
	int Numero, Rango_Inicio, Rango_Final;
    srand(time(NULL));
    
    //NumeroAleatorio = 1 + rand() % 100;
    
    cout << "En este juego tienes que adivinar el numero que la maquina piensa!\n\n";
    cout << "Dame el rango del numero aleatorio\nInicio del rango: ";
    cin >> Rango_Inicio;
    cout << "\nFinal del rango: ";
    cin >> Rango_Final;
    
    NumeroAleatorio = Rango_Inicio + rand() % (Rango_Final-Rango_Inicio + 1);
    Apuntador_NumeroAleatorio = &NumeroAleatorio;
    
    cout << "\nInicia el Juego!!!\n\n";
    do{
    	Intentos--;
    	cout << "Dame un numero: ";
    	cin >> Numero;
    	Validar_Numero(Numero);
    	
	}while(Numero != NumeroAleatorio && Intentos != 0);
	if(Intentos == 0){
		cout << "Se te acabaron los intentos :(\n GAME OVER!\n";
	}
	cout << "El numero aleatorio era: " << NumeroAleatorio << " y su direccion de memoria era: "<<Apuntador_NumeroAleatorio;
    return 0;
}

void Validar_Numero(int Numero){
	if(Numero > NumeroAleatorio){
    		if (Numero-10 <= NumeroAleatorio){
    			cout << "El numero dado esta muy cerca del numero!\nIntenta nuevamente :)\n";
			}
			else{
				cout << "El numero dado es mayor al numero aleatorio\nIntenta nuevamente :)\n";
			}
			cout << "\nTe faltan " << Intentos << " intentos para terminar el juego :D!\n";
		}
		if(Numero < NumeroAleatorio){
			if (Numero+10 >= NumeroAleatorio){
    			cout << "El numero dado esta muy cerca del numero!\nIntenta nuevamente :)\n";
			}
			else{
				cout << "El numero dado es menor al numero aleatorio\nIntenta nuevamente :)\n";
			}
			cout << "\nTe faltan " << Intentos << " intentos para terminar el juego :D!\n";
		}
}

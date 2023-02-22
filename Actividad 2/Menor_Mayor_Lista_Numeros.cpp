#include <iostream>

int Cantidad;
void Mostrar_Lista(int Lista[]);
void Ordenar_Menor_Mayor(int Lista[]);

void Mostrar_Lista(int Lista[]){
	for(int i = 0; i < Cantidad; i++){
		std::cout << Lista[i] << " ";
	}
	std::cout << "\n";
}

void Ordenar_Menor_Mayor(int Lista[]){
	int aux;
	for(int i = 0; i < Cantidad; i++){
		for(int x = 0; x < Cantidad; x++)
			if(Lista[x]>Lista[x+1]){
          		aux = Lista[x];
          		Lista[x]=Lista[x+1];
          		Lista[x+1]=aux;
        }
	}
	for(int j = 0; j < Cantidad; j++){
		std::cout << Lista[j] << " ";
	}
	std::cout << "\n";
}
int main(int argc, char** argv) {	
	
	std::cout << "Este programa te pide una cantidad de numeros que desees y lo ordena de menor a mayor\n";
	std::cout << "¿Cuantos Numeros desea ingresar?\n";
	std::cin >> Cantidad;
	
	int Numeros[Cantidad];
	for(int i = 0; i < Cantidad; i++){
		std::cout << "Dame un numero: \n";
		std::cin >> Numeros[i]; 
	}
	std::cout << "La lista sin ordenar es: \n";
	Mostrar_Lista(Numeros);
	
	std::cout << "La lista ordenada de menor a mayor es: \n";
	Ordenar_Menor_Mayor(Numeros);
	return 0;
}

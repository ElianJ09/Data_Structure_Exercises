#include <iostream>

int Cantidad;

int Mostrar_Mayor(int[]);
int Mostrar_Menor(int[]);

void Mostrar_Lista(int Lista[]){
	for(int i = 0; i < Cantidad; i++){ 
		std::cout << Lista[i] << " ";
	}
	std::cout << "\n";
}


int Mostrar_Menor(int Lista[]){
	int Menor = 99999;
	
	for(int i = 0; i < Cantidad; i++){ 
		if(Lista[i] < Menor){
			Menor = Lista[i];
		}
	}
	
	return Menor;
}
int Mostrar_Mayor(int Lista[]){
	int Mayor = 0;
	
	for(int i = 0; i < Cantidad; i++){ 
		if(Lista[i] > Mayor){
			Mayor = Lista[i];
		}
	}
	
	return Mayor;
}
int main(int argc, char** argv) {
	std::cout << "Este programa te pide una lista de numeros para despues decirte cual es el menor y el mayor\n";
	std::cout << "Cuantos numeros quieres ingresar?\n";
	std::cin >> Cantidad;
	int Lista[Cantidad];
	
	for(int i = 0; i < Cantidad; i++){
		std::cout << "Dame un numero: \n";
		std::cin >> Lista[i];
	}
	
	std::cout << "La lista es: \n";
	Mostrar_Lista(Lista);
	
	std::cout << "El numero menor es: " << Mostrar_Menor(Lista) << "\n";
	std::cout << "El numero mayor es: " << Mostrar_Mayor(Lista) << "\n";
	return 0;
}

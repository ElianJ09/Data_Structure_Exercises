#include <iostream>


void Llenar_Matriz();
void Mostrar_Matriz();
int Suma_Diagonal_Matriz();


int **Matriz_Punteada, Dimension;


void Llenar_Matriz(){
	
	Matriz_Punteada = new int*[Dimension];
	for(int i  =0; i < Dimension; i++){
		Matriz_Punteada[i] = new int[Dimension];
	}
	for(int i = 0; i < Dimension; i++){
		for (int j = 0; j < Dimension; j++){
			std::cout << "Ingresa el dato[" << i << "] [" << j << "]: ";
			std::cin >> *(*(Matriz_Punteada+i)+j);
		} 
	}
}

void Mostrar_Matriz(){
	std::cout << "\nEsta es la matriz: \n";
	for(int i = 0; i < Dimension; i++){
		for (int j = 0; j < Dimension; j++){
			std::cout << *(*(Matriz_Punteada+i)+j) << " ";
		} 
		std::cout << "\n";
	}
}

int Suma_Diagonal_Matriz(){
	int Suma = 0;
	
	for(int i = 0; i < Dimension; i++){
		for (int j = 0; j < Dimension; j++){
			if(i == j){
				Suma = Suma + *(*(Matriz_Punteada+i)+j);
			}
			
		} 
		std::cout << "\n";
	}
	
	return Suma;
}

int main(int argc, char** argv) {
	
	std::cout << "Este programa realiza la suma de elementos de la diagonal principal\n (Recuerda que debe ser una matriz cuadrada)\n";
	std::cout << "\nDame la dimension de la matriz: ";
	std::cin >> Dimension;
	
	Llenar_Matriz();
	Mostrar_Matriz();
	std::cout << "\nY la suma de la matriz es: " << Suma_Diagonal_Matriz()<< "\n";
	
	for(int i = 0; i < Dimension; i++){
		delete[] Matriz_Punteada[i];
	}
	delete[] Matriz_Punteada;
	return 0;
}

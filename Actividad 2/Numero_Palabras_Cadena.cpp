#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
	char Cadena[50];
	std::cout << "Este programa te pide una cadena de palabras y te devuelve el numero de palabras de la cadena\n";
	std::cout << "Dame una cadena: \n";
	std::cin.getline(Cadena, 30, '\n');
	
	std::cout << "El numero de palabras que tiene la cadena es de: ";
	int Palabras = 0, Caracteres = 0;
	for(int i = 0; Cadena[i] != '\0'; i++){
		if(Cadena[i-1] == ' ' && isalpha(Cadena[i])){
			Palabras++;
		}
		Caracteres++;
	}
	if(isalpha(Cadena[0])){
		Palabras++;
	}
	std::cout << Palabras << "\n";
	std::cout << "El numero de caracteres que tiene la cadena son de: "<< Caracteres- (Palabras-1) << "\n";
	
	return 0;
}


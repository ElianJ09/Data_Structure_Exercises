#include <iostream>

double Area_Triangulo(double Base, double Altura);
double Perimetro_Triangulo(double Base);

int main(int argc, char** argv) {
	double Base, Altura;
	std::cout << "Este programa realiza el area y perimetro de un triangulo\nDame su base:\n";
	std::cin >> Base;
	std::cout << "Dame su altura:\n";
	std::cin >> Altura;
	
	
	std::cout << "El area del triangulo es: " << Area_Triangulo(Base, Altura) <<"\n";
	std::cout << "El perimetro del triangulo es: "<< Perimetro_Triangulo(Base) <<"\n";
	
	
	return 0;
}

double Area_Triangulo(double Base, double Altura){
	return (Base*Altura)/2;
}
double Perimetro_Triangulo(double Base){
	return (Base*3);
}

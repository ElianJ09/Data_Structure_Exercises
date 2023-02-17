
#include <iostream>

struct Estudiante{
	double Calificacion1;
	double Calificacion2;
	double Calificacion3;
	char * Nombre;
	
	Estudiante *Siguiente;
};


void Agregar_Estudiante(Estudiante *& ,double ,double ,double);
void Mostrar_Promedios(Estudiante *);
void Mostrar_Calificaciones(Estudiante *);
int contador = 0;

void Agregar_Estudiante(Estudiante *&Lista, double calif1, double calif2, double calif3){
	Estudiante *Nuevo_Estudiante = new Estudiante();
	Nuevo_Estudiante->Calificacion1 = calif1;
	Nuevo_Estudiante->Calificacion2 = calif2;
	Nuevo_Estudiante->Calificacion3 = calif3;
	
	Nuevo_Estudiante->Siguiente = Lista;
	Lista = Nuevo_Estudiante;
	
	std::cout << "\nSe ha agregado un nuevo estudiante con calificaciones: \n";
	std::cout << "Calificacion 1: " << calif1 << "\n";
	std::cout << "Calificacion 2: " << calif2 << "\n";
	std::cout << "Calificacion 3: " << calif3 << "\n";
}
void Mostrar_Promedios(Estudiante *Lista){
	Estudiante *Actual = new Estudiante();
	Actual = Lista;
	int count = contador;
	double promedio = 0;
	
	while(Actual != NULL){
		promedio = (Actual->Calificacion1 + Actual->Calificacion2 + Actual->Calificacion3)/3;
		std::cout << "El estudiante numero "<< count <<" tiene un promedio de: " << promedio << "\n";
		
		count--;
		Actual = Actual->Siguiente;
	}
}

void Mostrar_Calificaciones(Estudiante *Lista){
	Estudiante *Actual = new Estudiante();
	Actual = Lista;
	int count = contador;
	
	while(Actual != NULL){
		std::cout << "El estudiante numero "<< count <<", sus calificaciones son: \n";
		std::cout << "Calificacion 1: " << Actual -> Calificacion1 << "\n";
		std::cout << "Calificacion 2: " << Actual -> Calificacion2 << "\n";
		std::cout << "Calificacion 3: " << Actual -> Calificacion3 << "\n";
		
		count--;
		Actual = Actual->Siguiente;
	}
}
int main(int argc, char** argv) {
	
	Estudiante *Lista = NULL;
	double calif1, calif2, calif3;
	int opcion = 0;
	
	std::cout << "Este programa agrega estudiantes con 3 calificaciones y te da sus promedios\n\n";
	do{
		contador++;
		std::cout << "\nNUEVO ESTUDIANTE: \n";
		std::cout << "Dame su calificacion 1: \n";
		std::cin >> calif1;
		std::cout << "Dame su calificacion 2: \n";
		std::cin >> calif2;
		std::cout << "Dame su calificacion 3: \n";
		std::cin >> calif3;
		
		Agregar_Estudiante(Lista, calif1, calif2, calif3);
		
		std::cout << "Quiere agregar otro Estudiante?\n1. Si\n2. No\n:";
		std::cin >> opcion;
		
	}while (opcion == 1);
	std::cout << "Los Estudiantes agregados son: \n\n";
	Mostrar_Calificaciones(Lista);
	
	std::cout << "Los promedios de los estudiantes agregados son: \n\n";
	Mostrar_Promedios(Lista);
	
	return 0;
}

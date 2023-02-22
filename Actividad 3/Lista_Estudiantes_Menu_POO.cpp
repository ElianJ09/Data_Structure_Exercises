#include <iostream>
#include <vector>
using namespace std;

class Estudiante{
	private: //Atributos
		char Nombre;
		char Identificacion;
		double &Calificacion;
	public: //Metodos
		Estudiante(char, char, double);
		void Agregar_Nuevo_Estudiante(char, char, double);
		void Actualizar_Calificacion_Estudiante(double, char);
		void Buscar_Estudiante_Identificacion(double, char);
};

Estudiante::Estudiante(char Nombre, char Identificacion, double &Calificacion){
	this->Nombre = Nombre;
	this->Identificacion = Identificacion;
	this->Calificacion = Calificacion;
}

void Estudiante::Agregar_Nuevo_Estudiante(char Nombre, char Identificacion, double Calificacion){
	
}

void Estudiante::Actualizar_Calificacion_Estudiante(double Calificacion, char Identificacion){
	
}

void Estudiante::Buscar_Estudiante_Identificacion(char Identificacion){
	
}

int main(int argc, char** argv) {
	
	return 0;
}

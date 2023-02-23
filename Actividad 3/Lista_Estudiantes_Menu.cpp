#include <iostream>
#include <string>
using namespace std;

struct Estudiante{
	double Calificacion;
	string Nombre;
	string Identificacion;
	
	Estudiante *Siguiente;
};


void Agregar_Estudiante(Estudiante *& ,double, string, string);
void Actualizar_Calificacion_Estudiante(Estudiante *);
void Buscar_Estudiante_Identificacion(Estudiante *, string);
void Mostrar_Lista_Estudiantes(Estudiante *);

int main(int argc, char** argv) {
	
	Estudiante *Lista = NULL;
	double Calificacion;
	string Nombre, Identificacion;
	int opcion = 0, AuxOpcion;
	
	
	do{
		cout << "Este programa puede hacer las siguientes cosas: \n1, Agregar Nuevo Estudiante\n2. Actualizar Calificacion de Estudiante\n3. Buscar Estudiante por Identificacion\n4. Mostrar Lista de Estudiantes\n";
		cout << "\nSi desea terminar el programa escriba 0\n";
	
		cout << "Selecciona una opcion: \n";
		cin >> opcion; 
		switch(opcion){
			case 0:
				break;
				
			case 1:
				do{
					cout << "\nNUEVO ESTUDIANTE: \n";
					cout << "\nDame su nombre: \n";
					cin >> Nombre;
					cout << "\nDame su Identificacion: \n";
					cin >>  Identificacion;
					cout << "\nDame su Calificacion: \n";
					cin >> Calificacion;
				
					Agregar_Estudiante(Lista, Calificacion, Nombre, Identificacion);
					
					cout << "\nQuiere agregar otro Estudiante?\n1. Si\n2. No\n:";
					cin >> AuxOpcion;
				}while(AuxOpcion == 1);
				break;
				
			case 2: 
				do{
					cout << "\nACTUALIZANDO CALIFICACION DE ESTUDIANTE: \n";
					Actualizar_Calificacion_Estudiante(Lista);
					
					cout << "\nQuiere actualizar otra calificacion de Estudiante?\n1. Si\n2. No\n:";
					cin >> AuxOpcion;
				}while(AuxOpcion == 1);
				break;
				
			case 3:
				do{
					cout << "\nBUSCANDO ESTUDIANTE: \n";
					cout << "\nDame su Identificacion: \n";
					cin >>  Identificacion;
				
					Buscar_Estudiante_Identificacion(Lista, Identificacion);
					
					cout << "\nQuiere buscar otro Estudiante?\n1. Si\n2. No\n:";
					cin >> AuxOpcion;
				}while(AuxOpcion == 1);
				break;
			case 4:
				cout << "Lista de Estudiantes: \n";
				Mostrar_Lista_Estudiantes(Lista);
				break;
				
			default:
				cout << "Dame una opcion valida!";
		}
	}while (opcion != 0);	
	return 0;
}



void Agregar_Estudiante(Estudiante *&Lista, double Calificacion, string Nombre, string Identificacion){
	//Inicializar un nuevo Estudiante para insertar el numero
	Estudiante* Nuevo_Estudiante = new Estudiante();
	Estudiante* Aux;
	
	//Asignacion del nuevo numero al Estudiante
	Nuevo_Estudiante -> Calificacion = Calificacion;
	Nuevo_Estudiante -> Nombre = Nombre;
	Nuevo_Estudiante -> Identificacion = Identificacion;
	Nuevo_Estudiante -> Siguiente = NULL;
	
	//Verificar que la lista este vacia para agregar un elemento
	if(Lista == NULL){
		Lista = Nuevo_Estudiante;
	}
	//Si no, apuntar a Aux al inicio de la lista y recorrer la lista
	else{
		Aux = Lista;
		while(Aux -> Siguiente != NULL){
			Aux = Aux -> Siguiente;
		}
		//Agregar el nuevo Estudiante a la lista(Ya con los datos)
		Aux -> Siguiente = Nuevo_Estudiante;
	}
	cout << "\nSe ha agregado un nuevo estudiante: \nNombre: " << Nombre << "\nIdentificacion: " << Identificacion << "\nCalificacion: " << Calificacion << "\n\n";
}

void Mostrar_Lista_Estudiantes(Estudiante *Lista){
	int Numero_Estudiantes = 0;
	while(Lista != NULL){
		Numero_Estudiantes++;
		cout << "\nEstudiante " << Numero_Estudiantes << ": \nNombre: " << Lista -> Nombre << "\nIdentificacion: " << Lista -> Identificacion << "\nCalificacion: " << Lista -> Calificacion << "\n\n";
		Lista = Lista -> Siguiente; //Avanza al siguiente nodo
	}
}

void Actualizar_Calificacion_Estudiante(Estudiante *Lista){
	int Numero_Estudiante = 0;
	double Calificacion;
	
	Mostrar_Lista_Estudiantes(Lista);
	cout << "Cual estudiante quiere actualizar? \n";
	cin >> Numero_Estudiante;
	
	//Avanzamos en la lista hasta que lleguemos al que deseamos
	int Numero_Estudiantes = 0;
	while(Lista != NULL){
		Numero_Estudiantes++;
		if(Numero_Estudiantes == Numero_Estudiante){
			cout << "\n\nQue calificacion nueva: \n";
			cin >> Calificacion;
			Lista -> Calificacion = Calificacion; //Asignamos el nuevo numero a la referencia de la Calificacion
		}
		Lista = Lista -> Siguiente; //Avanzamos de nodo
	}
	cout << "\nSe ha actualizado el Estudiante " << Numero_Estudiante << "\n";
}

void Buscar_Estudiante_Identificacion(Estudiante *Lista, string Identificacion){
	int Numero_Estudiantes = 0;
	while(Lista != NULL){
		Numero_Estudiantes++;
		if(Identificacion == Lista -> Identificacion){
			cout << "Estudiante " << Numero_Estudiantes << ": \nNombre: " << Lista -> Nombre << "\nIdentificacion: " << Lista -> Identificacion << "\nCalificacion: " << Lista -> Calificacion;
		}
		Lista = Lista -> Siguiente; //Avanza al siguiente nodo
	}
}






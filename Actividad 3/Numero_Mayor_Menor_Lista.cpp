#include <iostream>

using namespace std;

struct Nodo{
	int Numero;
	Nodo* Siguiente;
};

void NuevoNumero_Lista(Nodo *&, int);
void Mostrar_Lista(Nodo*);
void Mostrar_Mayor(Nodo*, int&);
void Mostrar_Menor(Nodo*, int&);


int main(int argc, char** argv) {
	Nodo* Lista = NULL;
	int Numero, Opcion = 1, Menor = 9999, Mayor = 0, NumeroRango;
	cout << "Este programa almacena una lista de numeros y te da el mayor y menor de la lista. \nDespues puedes darle un numero, y el programa te dira si el numero dado esta entre el mayor y menor de la lista.\n\n";
	
	do{
		cout << "Dame un numero: \n";
		cin >> Numero;
		
		NuevoNumero_Lista(Lista, Numero); //Llamada de la funcion para agregar un nuevo elemento
		
		cout << "Desea continuar?\n1. Si\n2. No\n";
		cin >> Opcion;
	}while(Opcion == 1);
	
	cout << "\nDame un numero para verificar si esta en el rango del mayor y menor: \n";
	cin >> NumeroRango;
	
	Mostrar_Mayor(Lista, Mayor);
	Mostrar_Menor(Lista, Menor);
	cout << "\nEl mayor de la lista es: " << Mayor;
	cout << "\nEl menor de la lista es: " << Menor; 
	
	if (NumeroRango > Menor && NumeroRango < Mayor){
		cout << "\nEl numero dado al final esta en el rango del mayor y menor\n";
	}
	else{
		cout << "\nEl numero dado al final no esta en el rango del mayor y menor\n";
	}
	
	cout << "\nLista de numeros ingresadas: ";
	Mostrar_Lista(Lista);
	
	return 0;
}

void NuevoNumero_Lista(Nodo *&Lista, int Numero){
	//Inicializar un nuevo nodo para insertar el numero
	Nodo* Nuevo_Nodo = new Nodo();
	Nodo* Aux;
	
	//Asignacion del nuevo numero al nodo
	Nuevo_Nodo -> Numero = Numero;
	Nuevo_Nodo -> Siguiente = NULL;
	
	//Verificar que la lista este vacia para agregar un elemento
	if(Lista == NULL){
		Lista = Nuevo_Nodo;
	}
	//Si no, apuntar a Aux al inicio de la lista y recorrer la lista
	else{
		Aux = Lista;
		while(Aux -> Siguiente != NULL){
			Aux = Aux -> Siguiente;
		}
		//Agregar el nuevo nodo a la lista(Ya con el dato)
		Aux -> Siguiente = Nuevo_Nodo;
	}
}


void Mostrar_Lista(Nodo* Lista){
	//Imprime todos los datos de los nodos hasta que sea el final de la lista
	while(Lista != NULL){
		cout << Lista -> Numero << " ";
		Lista = Lista -> Siguiente; //Avanza al siguiente nodo
	}
}


void Mostrar_Menor(Nodo* Lista, int& Menor){
	//Avanzamos en la lista hasta que lleguemos al final
	while(Lista != NULL){
		if(Lista -> Numero < Menor){
			Menor = Lista -> Numero; //Asignamos el nuevo numero a la referencia de la variable Menor
		}
		Lista = Lista -> Siguiente; //Avanzamos de nodo
	}
	
}
void Mostrar_Mayor(Nodo* Lista, int& Mayor){
	
	while(Lista != NULL){
		if(Lista -> Numero > Mayor){
			Mayor = Lista -> Numero;//Asignamos el nuevo numero a la referencia de la variable Mayor
		}
		Lista = Lista -> Siguiente; // Avanzamos de nodo
	}
	
}

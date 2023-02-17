
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	string OperacionAritmetica, OperacionParentesis;
	int LocationStart, LocationEnd;
	
	cout << "Este programa te resuelve una operacion aritmetica sencilla(suma, resta, division, multiplicacion)\n\n";
	cout << "Dame la operacion matematica: \n";
	getline(cin, OperacionAritmetica);
	
	
	cout << OperacionAritmetica << "\n";
	
	
	// while(OperacionAritmetica.find('(') != string::npos || OperacionAritmetica.find(')') != string::npos){
		LocationStart = OperacionAritmetica.find('(');
		LocationEnd = OperacionAritmetica.find(')');
		
		OperacionParentesis = OperacionAritmetica.substr(LocationStart+1, (LocationEnd-LocationStart)-1);
	//}
	
	//OperacionAritmetica.erase(remove(OperacionAritmetica.begin(), OperacionAritmetica.end(), '('), OperacionAritmetica.end()); 
	
	cout << OperacionParentesis << "\n";
	
}

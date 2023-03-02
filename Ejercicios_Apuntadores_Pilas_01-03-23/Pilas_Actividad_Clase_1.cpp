#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(10);
    pila.push(-5);
    cout << "Tamaño de la pila: " << pila.size() << '\n';
    cout << "Top: " << pila.top() << '\n';
    pila.pop();
    cout << "Top: " << pila.top() << '\n';
    return 0;
}
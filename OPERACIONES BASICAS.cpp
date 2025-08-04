/******************************************************************************

Pogramacion de lenguaje I 
Alumna: Veronica Nikey Ayon Diaz
fecha: 03 de Agosto 2025

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

double calcular(double primerNumero, double segundoNumero, string tipo) {
if (tipo == "SUMA")
    return primerNumero + segundoNumero;
else if (tipo == "RESTA")
    return primerNumero - segundoNumero;
else if (tipo == "MULTIPLICAR")
    return primerNumero * segundoNumero;
else if (tipo == "DIVIDIR")
    return primerNumero / segundoNumero;
}

int main() {
    double primerNumero, segundoNumero;

    std::cout << "Introduce el primer número: ";
    std::cin >> primerNumero;

    std::cout << "Introduce el segundo número: ";
    std::cin >> segundoNumero;

    double suma = calcular(primerNumero, segundoNumero, "SUMA");
    double resta = calcular(primerNumero, segundoNumero, "RESTA");
    double multiplicacion = calcular(primerNumero, segundoNumero, "MULTIPLICAR");
    double division = calcular(primerNumero, segundoNumero, "DIVIDIR");

    std::cout << "La suma es: " << suma<< endl;
    std::cout << "La resta es: " << resta<< endl;
    std::cout << "La multiplicacion es: " << multiplicacion<< endl;
    std::cout << "La division es: " << division<< endl;
    return 0;
}

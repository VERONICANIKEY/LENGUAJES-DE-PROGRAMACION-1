/*******************************************************************************

Código que genera el RFC de una persona
Autor: Francisco Ortega
Almna: Nikey Ayon
Fecha: 01 AGOSTO 2025

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

//diccionario de palabras no permitidas
const std::vector<std::string> palabrasprohibidas = {
    "vagina", "pene", "cola", "coger", "sexo", "popo", "pipi", "puta", "puto" 
};

// verificar y modificar palabras prohibidas del diccionario
std:: string corregirRFC(const std ::string& rfc){
    for (const std::string& palabra : palabrasprohibidas) {
        if (rfc == palabra){
            return rfc.substr(0, 3) +"X"; // remplaza la ultima letra por "X"
        }
    }
    return rfc;
}

// funcion para obteneerla primera vocal interna de una cadena
char obtenerprimeraVocalInterna(const std::string& str){
    for (size_t i= 1; i < str.length(); ++i) {
        char c = toupper(str[i]);
        if (c == 'A'|| c == 'E' || c == 'I'  || c == 'O' || c =='U')
        return  c;
    }
    return 'x'; // si no encuentra ninguna vocal interna, se usa una x
}

// funcion principal para calcular el rfc 
std::string calcularRFC(const std::string& nombre, const std::string&apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento){
    
// se declara la variable en donde guardaremos el rfc
std::string rfc;
    
// se obtiene la letra inicial y la primera Vocal Interna del apellido apellido Paterno
char letraInicial = apellidoPaterno[0];
char primeraVocalInterna = obtenerprimeraVocalInterna(apellidoPaterno);
    
// se obtiene la inicial del apellido materno o se pone una "X" si no existe
char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
  // se obtiene la inicial del primer nombre o se usa una "X" si no existe
  char inicialNombre = nombre[0];
  
  // se obtiene los dos ultimos digitos del año de fechanacimiento
  std::string anio = fechaNacimiento.substr(2, 2);
  
  // se obtiene el mes y el dia de fechaNacimiento
  std::string mes = fechaNacimiento.substr(5,2);
  std::string dia = fechaNacimiento.substr(8,2);
  
  // se construye el RFC sumando el texto de la informa que se  proporciono 
  rfc = letraInicial;
  rfc += primeraVocalInterna;
  rfc += inicialApellidoMaterno;
  rfc += inicialNombre;
  
  // Aqui se compara con la base de datos de palabras mal formadas y se sustituye con la letra "X"
  rfc = corregirRFC(rfc);
  
  // si no hay correccion se cpmtinua generando el rfc 
  rfc += anio;
  rfc += mes;
  rfc += dia;
  
  return rfc;
}

int main() {
    // envia a consola los datos que requiere para solicitar nombre, apellido y fecha de fechaNacimient
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout << "introduce tu nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "introduce tu apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "introduce tu apellido materno (si no cuenta con apellido materno, presione Enter: ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "introduce tu fecha de nacimiento en el siguiente formato (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}
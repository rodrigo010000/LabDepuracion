#include <iostream>
using namespace std;

// Función recursiva para calcular el factorial de un número
int factorial(int n) {
    // Verificamos si el número es negativo
    if (n < 0) {
        // Si es negativo, lanzamos una excepción para indicar que el factorial no está definido
        throw invalid_argument("Error: Factorial de un número negativo no está definido.");
    }
    // Caso base: el factorial de 0 o 1 es 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Llamada recursiva para calcular el factorial de n-1 y multiplicarlo por n
    return n * factorial(n - 1);
}

int main() {
    try {
        int numero;
        cout << "Introduce un número para calcular el factorial: "; // Pedimos al usuario que ingrese un número
        cin >> numero;
        int resultado = factorial(numero);

        // Mostramos el resultado en pantalla
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }

    // Bloque catch para manejar excepciones
    catch (invalid_argument& e) {
        // Si se lanza una excepción debido a un número negativo, la capturamos y mostramos el mensaje de error
        cerr << e.what() << endl;
    }
    catch (...) {
        // Este catch captura cualquier otro tipo de excepción que no sea específicamente invalid_argument
        cerr << "Se ha producido un error desconocido." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    string nombre;
    double valor;
    double peso;
};

int main() {
    double capacidad = 50;
    vector<Objeto> objetos = {
        {"A", 60, 10},
        {"B", 100, 20},
        {"C", 120, 30}
    };

    sort(objetos.begin(), objetos.end(), [](const Objeto& a, const Objeto& b) {
        return (a.valor / a.peso) > (b.valor / b.peso);
    });

    double valorTotal = 0.0;
    double restante = capacidad;

    cout << "Objetos seleccionados:\n";

    for (const auto& obj : objetos) {
        if (restante <= 0) break; 

        if (obj.peso <= restante) {
            cout << "- " << obj.nombre << " completo\n";
            restante -= obj.peso;
            valorTotal += obj.valor;
        } else {
            double fraccion = restante / obj.peso;
            cout << "- " << (int)restante << "/" << (int)obj.peso << " Parte del objeto " << obj.nombre << "\n";
            valorTotal += obj.valor * fraccion;
            restante = 0; 
        }
    }

    cout << "Valor total aproximado: " << valorTotal << endl;
    return 0;
}

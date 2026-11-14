#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Definimos las posiciones de las casas y el rango de cobertura de cada antena
    vector<long long> casas = {1, 2, 7, 11, 20, 21, 30};
    long long R = 5;

    // Ordenamos las casas de menor a mayor posición en la calle
    sort(casas.begin(), casas.end());

    vector<long long> antenas;
    size_t i = 0;
    size_t n = casas.size();

    cout << "=== COBERTURA DE ANTENAS ===\n";

    // Estrategia Greedy: avanzamos buscando casas sin cubrir de izquierda a derecha
    while (i < n) {
        // Colocamos la antena lo más a la derecha posible para alcanzar la primera casa libre
        long long posAntena = casas[i] + R;
        antenas.push_back(posAntena);

        // Calculamos el límite derecho hasta donde alcanza a cubrir esta antena
        long long limiteCobertura = posAntena + R;

        // Saltamos automáticamente todas las casas que ya quedan cubiertas dentro del rango
        while (i < n && casas[i] <= limiteCobertura) {
            i++;
        }
    }

    // Mostramos las posiciones finales de las antenas
    cout << "Antenas colocadas en:\n";
    for (long long pos : antenas) {
        cout << "- " << pos << "\n";
    }
    cout << "Cantidad total: " << antenas.size() << "\n";

    return 0;
}
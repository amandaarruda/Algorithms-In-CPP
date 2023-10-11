#include <iostream>
#include <vector>

using namespace std;

int contarQuantidadeDeSubconjuntos(vector<int>& A, int d, int index) {
    if (d == 0) { // se eu encontro um subconjunto com a soma d
        return 1; 
    }

    if (index < 0 || d < 0) {
        return 0; // bloqueio soluções com índice negativo ou soma negativa
    }

    int incluir = contarQuantidadeDeSubconjuntos(A, d - A[index], index - 1);

    int excluir = contarQuantidadeDeSubconjuntos(A, d, index - 1);

    return incluir + excluir;
}

int main() {
    int c;
    cin >> c; // quantidade de cass

    while (c--) {
        int n;
        cin >> n; // quantidade de elementos

        vector<int> A(n); // nosso conjunto
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        int d;
        cin >> d; // inteiro que queremos obter

        int totalDeSubconjuntos = contarQuantidadeDeSubconjuntos(A, d, n - 1);
        cout << totalDeSubconjuntos << endl;
    }

    return 0;
}

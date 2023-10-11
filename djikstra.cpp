#include <bits/stdc++.h>
using namespace std;

// Começo definindo um infinito para representar distâncias que não alcanço/visitei
const int INF = INT_MAX;

// Defino uma struct pra que a gente possa definir para onde a aresta vai e seu peso
struct Aresta {
    int destino, peso;
};

vector<int> dijkstra(vector<vector<Aresta>>& grafo, int origem) {
    int n = grafo.size(); //Pego o número de vértices
    vector<int> distancia(n, INF);
    vector<bool> visitado(n, false);
    distancia[origem] = 0; //Como eu sei que a distância da origem a si mesma é 0, deixo definida

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                u = j;
            }
        }

        if (distancia[u] == INF) {
            break;
        }

        visitado[u] = true;
        for (const Aresta& aresta : grafo[u]) {
            int v = aresta.destino;
            int peso = aresta.peso;
            if (distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
            }
        }
    }

    return distancia;
}

int main() {
    int t;
    cin >> t;
    for (int casoNum = 1; casoNum <= t; casoNum++) {
        int v, a;
        cin >> v >> a;
        vector<vector<Aresta>> grafo(v);

        for (int i = 0; i < a; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            grafo[u].push_back({v, w});
        }

        int origem;
        cin >> origem;

        vector<int> distancias = dijkstra(grafo, origem);

        cout << "Caso " << casoNum << endl;
        for (int i = 0; i < v; i++) {
            if (distancias[i] == INF) {
                cout << -1 << endl;
            } else {
                cout << distancias[i] << endl;
            }
        }
    }

    return 0;
}


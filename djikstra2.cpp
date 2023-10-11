#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20000;
const int MAX_M = 50000;
const int INF = INT_MAX;

struct Aresta {
    int para;  // Nó de destino da aresta
    int peso;  // Peso (distância) da aresta
};

vector<Aresta> adj[MAX_N]; // Lista de adjacência para representar o grafo
int distancia[MAX_N];      // Array para armazenar a distância mínima
int predecessores[MAX_N];  // Array para armazenar o nó predecessor

// Função para inicializar variáveis e estruturas de dados
void inicializar() {
    for (int i = 0; i < MAX_N; i++) {
        adj[i].clear();      // Limpa a lista de adjacência
        distancia[i] = INF;  // Define a distância como infinito
        predecessores[i] = -1; // Define o predecessor como nulo
    }
}

void dijkstra(int inicio) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila_prioridade;
    fila_prioridade.push({0, inicio});  // Inicializa a fila de prioridade com o nó de início
    distancia[inicio] = 0; // A distância para o nó de início é 0

    // Loop principal do algoritmo
    while (!fila_prioridade.empty()) {
        int u = fila_prioridade.top().second; // Obtém o nó com a menor distância
        fila_prioridade.pop();

        // Itera sobre todas as arestas (vizinhos) do nó atual
        for (const Aresta& aresta : adj[u]) {
            int v = aresta.para;  // Nó de destino da aresta
            int w = aresta.peso;  // Peso (distância) da aresta

            // Verifica se encontrou um caminho mais curto até v
            if (distancia[u] + w < distancia[v]) {
                distancia[v] = distancia[u] + w;  // Atualiza a distância mínima
                predecessores[v] = u; // Define u como o predecessor de v
                fila_prioridade.push({distancia[v], v}); // Adiciona v à fila de prioridade
            }
        }
    }
}

int main() {
    int N;
    cin >> N;  // Número de casos de teste

    // Loop pelos casos de teste
    for (int numCaso = 1; numCaso <= N; numCaso++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        
        inicializar(); // Inicializa as estruturas de dados

        // Lê as informações das arestas e constrói o grafo
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});  // Adiciona a aresta u-v no grafo
            adj[v].push_back({u, w});  // Adiciona a aresta v-u no grafo (grafo não direcionado)
        }

        dijkstra(S); // Executa o algoritmo de Dijkstra a partir do nó de início S

        cout << "Case #" << numCaso << ": ";
        if (distancia[T] == INF) {
            cout << "unreachable" << endl; // Se não houver caminho
        } else {
            cout << distancia[T] << endl; // Imprime a distância mínima de S para T
        }
    }

    return 0;
}

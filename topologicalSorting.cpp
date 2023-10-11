#include <bits/stdc++.h>
using namespace std;

// Função para realizar a busca topológica
bool buscaTopologica(int n, // Total de trabalhos (vértices)
unordered_map<int, vector<int>>& grafo, // Grafo de pré-requisitos
vector<int>& grauEntrada, // grau de cada entrada
vector<int>& resultado) { // Vetor com a ordem correta dos trabalhos
    priority_queue<int, vector<int>, greater<int>> fila; // Usa-se uma fila de prioridade para ordenar os trabalhos 

    // Inicializa a fila com trabalhos que não têm pré-requisitos
    for (int i = 1; i <= n; i++) {
        if (grauEntrada[i] == 0) { // Se for zero, o trabalho é colocado na fila de prioridade
            fila.push(i);
        }
    }

    while (!fila.empty()) { // continua até que a fila de prioridade esteja vazia
        int trabalhoAtual = fila.top(); // Pega o trabalho atual da fila de prioridade
        fila.pop(); // Remove o trabalho atual da fila
        resultado.push_back(trabalhoAtual); // Adiciona o trabalho atual ao resultado

        // Percorre os trabalhos vizinhos do trabalho atual no grafo
        for (int vizinho : grafo[trabalhoAtual]) { // Recebe o valor de cada trabalho vizinho do trabalho atual
            grauEntrada[vizinho]--; // Decrementa o grau de entrada do vizinho

            // Se o grau de entrada do vizinho se tornou zero, ele é colocado na fila
            if (grauEntrada[vizinho] == 0) {
                fila.push(vizinho);
            }
        }
    }

    // Se não incluímos todos os trabalhos, então há um ciclo no grafo
    return resultado.size() == n; // Se o tamanho do resultado for igual ao número de trabalhos, então não há ciclos
}

int main() {
    int n, m; 
    cin >> n >> m;

    unordered_map<int, vector<int>> grafo; // O grafo de pré-requisitos
    vector<int> grauEntrada(n + 1, 0); // Vetor que armazena o grau de entrada de cada trabalho
    vector<int> resultado; // Vetor para armazenar a ordem dos trabalhos

    // Lê os dados de entrada e constrói o grafo de pré-requisitos
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        grafo[x].push_back(y); // Invertendo a direção das arestas, pois estamos interessados nos pré-requisitos
        grauEntrada[y]++; // Incrementa o grau de entrada do trabalho y
    }

    if (buscaTopologica(n, grafo, grauEntrada, resultado)) {
        // Se a busca topológica for bem-sucedida, imprime a ordem dos trabalhos
        for (int i = 0; i < n; i++) {
            cout << resultado[i];

            // Adiciona um espaço após cada trabalho, menos o último
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        // Se não for possível realizar todos os trabalhos, imprime "Sandro fails."
        cout << "Sandro fails." << endl;
    }

    return 0;
}

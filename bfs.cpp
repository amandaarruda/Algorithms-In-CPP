#include <bits/stdc++.h>

using namespace std;

class Participante { // Representa o participante
public:
    string nome;
    int classificacao;

    Participante(const string& n, int c) : nome(n), classificacao(c) {} 
};

int main() {
    int casosTeste;
    cin >> casosTeste; // Recebe a quantidade de casos teste (de 0 a 10)

    for (int i = 0; i < casosTeste; i++) {
        int equipes; 
        cin >> equipes; // Recebe a quantidade de times (de 0 a 100)

        // O unordered_map irá armazenar os times e seus membros em uma hash table
        unordered_map<string, vector<string>> times;
        unordered_map<string, int> classificacao;

        // Iteração para ler informações sobre cada equipe
        for (int j = 0; j < equipes; j++) {
            string membro1, membro2, membro3;
            cin >> membro1 >> membro2 >> membro3;

            // Estabelecendo conexões entre os membros da equipe
            // Cada membro é conectado com os outros dois membros
            times[membro1].push_back(membro2);
            times[membro1].push_back(membro3);
            times[membro2].push_back(membro1);
            times[membro2].push_back(membro3);
            times[membro3].push_back(membro1);
            times[membro3].push_back(membro2);

            // Inicializar a classificação dos membros da equipe como -1
            // Isso indica que a classificação ainda é desconhecida
            classificacao[membro1] = -1;
            classificacao[membro2] = -1;
            classificacao[membro3] = -1;
        }
            
        // Inicializar classificação do Ahmad como 0, para construir uma BFS a partir dele
        string ahmad = "Ahmad";
        classificacao[ahmad] = 0;
        queue<string> q; // A fila q de srtings é criada para iniciar a busca em largura
        q.push(ahmad); // Adiciona Ahmad na fila

        // Para começar a explorar as relações dos membros com Ahmad na BFS:

        while (!q.empty()) { // Enquanto a fila não estiver vazia
            string atual = q.front(); // Recebe o primeiro elemento da fila
            q.pop(); // Remove o primeiro elemento da fila

            for (const string& companheiro : times[atual]) { // Para cada companheiro do atual
                if (classificacao[companheiro] == -1) { // Se a classificação do companheiro for -1
                    classificacao[companheiro] = classificacao[atual] + 1; // A classificação do companheiro recebe a classificação do atual + 1
                    q.push(companheiro); // Adiciona o companheiro na fila para que ele seja explorado posteriormente
                }
            }
        }

        vector<Participante> resultados; // Cria um vetor vazio de resultados
        for (const auto& entry : classificacao) { // Para cada entrada no unordered_map classificação
            resultados.push_back(Participante(entry.first, entry.second)); // Adiciona um novo participante no vetor de resultados
        }
        sort(resultados.begin(), resultados.end(), [](const Participante& a, const Participante& b) { /* Ordena o resultado com um iterador apontando para o primeiro 
            elemento e outro para o último e uma função que determina a ordem de resultados */
            if (a.classificacao == b.classificacao) { // Caso as classificações sejam iguais
                return a.nome < b.nome; // O nome será comparado para classificar em ordem alfabética
            }
            if (a.classificacao == -1) { // Caso a classificação seja indefinida
                return false;  // Considera-se maior para que ela apareça por último
            }
            if (b.classificacao == -1) { // Caso a classificação seja indefinida
                return true; // Considera-se maior para que ela apareça depois de a
            }
            return a.classificacao < b.classificacao; // Garante a ordenação alfabética
        });

        cout << resultados.size() << endl; // Informa quantos resultados foram gerados
        for (const Participante& participante : resultados) {
            if (participante.classificacao == -1) {
                cout << participante.nome << " undefined" << endl;
            } else {
                cout << participante.nome << " " << participante.classificacao << endl;
            }
        }
    }
    return 0;
}

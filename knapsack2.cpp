#include <bits/stdc++.h>
using namespace std;

struct Item {
    int tamanho;
    int valor;
};

int calcularValorMaximoMochila(int capacidadeMochila, vector<Item>& listaItens) {
    int numItens = listaItens.size();

    /* Criando uma matriz para a programação dinâmica, onde dp[i][w] representa o valor 
máximo que pode ser obtido com os primeiros 'i' itens e uma mochila de capacidade 'w'. */
    vector<vector<int>> dp(numItens + 1, vector<int>(capacidadeMochila + 1, 0)); 

    // Preenchendo a matriz dp usando programação dinâmica
    for (int i = 1; i <= numItens; i++) {
        for (int capacidadeAtual = 1; capacidadeAtual <= capacidadeMochila; capacidadeAtual++) {
            // Verificando se o tamanho do item é maior que a capacidade atual da mochila
            if (listaItens[i - 1].tamanho > capacidadeAtual) {
                // Não podemos incluir o item, então copiamos o valor da célula superior
                dp[i][capacidadeAtual] = dp[i - 1][capacidadeAtual];
            } else {
                // Podemos incluir o item, então escolhemos o valor máximo entre incluir ou não incluir o item
                dp[i][capacidadeAtual] = max(dp[i - 1][capacidadeAtual], dp[i - 1][capacidadeAtual - listaItens[i - 1].tamanho] + listaItens[i - 1].valor);
            }
        }
    }

    // O valor máximo estará na célula dp[numItens][capacidadeMochila]
    return dp[numItens][capacidadeMochila];
}

int main() {
    int capacidadeMochila, numItens;
    cin >> capacidadeMochila >> numItens;

    vector<Item> listaItens(numItens);

    // Lendo os itens
    for (int i = 0; i < numItens; i++) {
        cin >> listaItens[i].tamanho >> listaItens[i].valor;
    }

    int valorMaximo = calcularValorMaximoMochila(capacidadeMochila, listaItens);

    // Exibindo o valor máximo obtido
    cout << valorMaximo << endl;

    return 0;
}

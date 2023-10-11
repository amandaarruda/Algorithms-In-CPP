#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    // Inicializa um vetor dp para guardar os valores mínimos de custo até cada pedra.
    vector<int> dp(N, INT_MAX);

    // O custo para chegar à primeira pedra é zero, pois é o ponto de partida.
    dp[0] = 0;

    // Itera através das pedras e calcula os custos mínimos.
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K && i + j < N; j++) {
            // Calcula o custo se o sapo saltar para a pedra i + j.
            int custo = dp[i] + abs(heights[i] - heights[i + j]);
            
            // Atualiza o valor mínimo de custo se o custo calculado for menor.
            dp[i + j] = min(dp[i + j], custo);
        }
    }

    // O resultado estará no último elemento do vetor dp.
    cout << dp[N - 1] << endl;

    return 0;
}

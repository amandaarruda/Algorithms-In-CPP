#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila(int W, vector<int>& pesos, vector<int>& v, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - pesos[i - 1]] + v[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int c;
    cin >> c; // quantidade de casos

    while (c--) {
        int W; // capacidade da mochila
        cin >> W;

        int n; // quantidade de itens disponíveis
        cin >> n;

        vector<int> pesos(n); // pesos
        vector<int> v(n); // valores

        for (int i = 0; i < n; ++i) {
            cin >> pesos[i] >> v[i];
        }

        int valorMaximo = mochila(W, pesos, v, n);
        cout << valorMaximo << endl;
    }

    return 0;
}

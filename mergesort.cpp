#include <iostream>
using namespace std;

// chamo o Merge de mescla 
void mescla(int *dados, int esquerda, int direita, int meio) {
  int i, j, k, temp[direita - esquerda + 1];
  i = esquerda;
  j = meio + 1;
  k = 0; // Ã­ndice do temp

  while (i <= meio && j <= direita) {
    if (dados[i] < dados[j]) {
      temp[k] = dados[i];
      k++;
      i++;
    } else {
      temp[k] = dados[j];
      k++;
      j++;
    }
  }

  while (i <= meio) {
    temp[k] = dados[i];
    k++;
    i++;
  }

  while (j <= direita) {
    temp[k] = dados[j];
    k++;
    j++;
  }

  for (i = esquerda; i <= direita; i++) {
    dados[i] = temp[i - esquerda];
  }
}

// Chamo o MergeSort de separaÃ§Ã£o, uma vez que ele divide os elementos que temos
void separacao(int *dados, int esquerda, int direita) {
  int meio;
  if (esquerda < direita) { // if l < r then
    meio = (esquerda + direita) / 2; // m â (l + r)/2
    
    separacao(dados, esquerda, meio); // Mergesort(A, l, m);
    separacao(dados, meio + 1, direita); // Mergesort(A, m + 1, r);

    mescla(dados, esquerda, direita, meio); //Merge(A, l, r);
  }
}

int main() {
  int quantidade, i; // pego a quantidade de inteiros que vou ordenar e faÃ§o de i um Ã­ndice
  cin >> quantidade;

  int arr[quantidade];
  for (i = 0; i < quantidade; i++) {
    cin >> arr[i];
  }

  separacao(arr, 0, quantidade - 1);

  for (i = 0; i < quantidade; i++)
    cout << arr[i] << endl; // imprimo os resultados em ordem nÃ£o-descescente

  return 0;
}

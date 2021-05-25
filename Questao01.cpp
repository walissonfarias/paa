#include <iostream>
using namespace std;
#define TAM 9

// Uma funcao que ordena um array de inteiros usando o algoritmo de Bubble sort.
void bubbleSort(int vetor[], int n) {
	int k, j, aux;

	for (k = n - 1; k > 0; k--) {
		printf("\n[%d] ", k);

		for (j = 0; j < k; j++) {
			printf("%d, ", j);

			if (vetor[j] > vetor[j + 1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}
int main()
{
	int vetor[TAM], i;
	for (i = 0; i < TAM; i += 1)
	{
		cout << "digite a posicao" << i << endl;
		cin >> vetor[i];
	}
	bubbleSort(vetor, TAM);
	for (i = 0; i < TAM; i += 1){
		cout << vetor[i];
	}
}
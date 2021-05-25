#include <iostream>
using namespace std; 
#define TAM 5

//vetor sera ordenado colocando o menor elemento na primeira posição a cada iteração. 
void selectionSort(int vetor[], int tam) {
    for (int indice = 0; indice < tam; ++indice) { 
        int indiceMenor = indice;
        for (int indiceSeguinte = indice + 1; indiceSeguinte < tam; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
            cout << "indice" << indice << "----indiceMenor " << indiceMenor << "----indiceSeguinte" << indiceSeguinte << endl;
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}
//será feito a leitura do vetor e chamada a função de ordenação selection sort
int main() {
    int vetor[TAM];
    int a = 0;
    for (int i = 0; i < TAM; i++) {
        cout << "digite a posicao " << i << " do vetor:" << endl;
        cin >> vetor[i];
    }
    selectionSort(vetor, TAM);
    cout << "vetor ordenado:" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i];
    }
}

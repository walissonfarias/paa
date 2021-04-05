#include <iostream>
using namespace std;
template <typename T>;
//Implementar o algoritmo Selection Sort
int main() {

    int tam;
    int i, j, min, aux;





    cout << "Digite o tamanho do vetor\n";
    cin >> tam;

    T vetor[tam];


    cout << "digite os " << tam << " números do vetor\n" ;
    for (i = 0; i < tam; i++) {
        cin >> vetor[i];


    }
cout << "Ordem como foram inseridos\n";
    for (i = 0; i < tam; i++) {

        cout << vetor[i]<< " ";
    }


        for (i = 0; i < (tam - 1); i++) {
            // O minimo é o primeiro número não ordenado ainda
            min = i;
            for (j = i+1; j < tam; j++) {
                //Caso tenha algum numero menor ele faz a troca do minimo
                if (vetor[j] < vetor[min]) {
                    min = j;
                }



            }
            // Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los
            if (i != min) {
                aux = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = aux;
            }


        }

        cout << "\nNúmeros Ordenados\n";
        /* Imprime o vetor ordenado */
        for (i = 0; i < tam; i++) {
            cout << vetor[i] << " ";
        }



    return 0;

}

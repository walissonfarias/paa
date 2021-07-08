#include <iostream>
#include <vector>
using namespace std;

// retorna o máximo de dois inteiros
int maximo(int a, int b) { 
    return (a > b) ? a : b; 
}

// retorna o valor maximo para a capacidade da mochila
int knapSack(int W, const std::vector<int>& wt, const std::vector <int>& val, int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
	//verifica se o peso do ultmo elemento é maior que a capacidade da mcohila
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return maximo(val[n - 1] + knapSack(W - wt[n - 1],
            wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    int qtd = 0;
    cout << "insira a quantidade de objetos:";
    cin >> qtd;
    std::vector <int> wt(qtd);
    std::vector <int> val(qtd);
    int W = 5;
    cout << "vector"; 
    for (int i = 0; i < qtd; i++) {
        cout << "insira o valor do objeto" << i + 1 << endl;
        cin >> val[i];
        cout << "insira os peso do objeto" << i + 1 << endl;
        cin >> wt[i];
    }
    int n = sizeof(val) / sizeof(val[0]);
    cout << "o valor de n:" << n;
    cout << "o maximo de peso que pode ser carregado na mochila e:";
    cout << knapSack(W, wt, val, n);
}
//Rereferencia: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include<iostream>
#include<cstring>
#include <vector>
using namespace std;

int bruteforceStringMatch(const char t[], const char p[], int n, int m)
{
    int i, j;
    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && p[j] == t[i + j])
            j++;
        if (j == m) {
            cout << "o caracter esta na posicao :\n" << i;
            return i;
        }
    }
    cout << "A caracter nao esta presente dentro do vetor \n";
    return -1;
}
int main()
{
    int n, m, local;;
    char text[100], pattern[100];
    cout << "Informes os caracteres do vetor:";
    cin >> text;
    cout << "Informe o caracter a ser pesquisado:\n";
    cin >> pattern;
    n = strlen(text);
    m = strlen(pattern);
    local = bruteforceStringMatch(text, pattern, n, m);
    return 0;
}
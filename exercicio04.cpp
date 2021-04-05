#include<iostream>
#include<cstring>
using namespace std;
//Implementar o algoritmo BruteForceStringMatch apresentado na Se¸c˜ao 3.2 do Cap´ıtulo 31
int n;
int m;
char t[100];
char p[100];
int bruteforceStringMatch(char t[100],char p[100],int n,int m)
{
    int i;
    int j;
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m&&p[j]==t[i+j])
            j++;
        if(j==m){
            cout << "A caracter está na posição :\n" << i;
            return i;
        }

    }
    cout << "A caracter não está entre os digitados \n";
            return -1;
}
int main()
{
    int local;
    cout << "digite os caracteres \n";
    cin >> t;

    cout << "digite o caracter que deseja pesquisar\n";
    cin >> p;
    n=strlen(t);
    m=strlen(p);
    local=bruteforceStringMatch(t,p,n,m);
   //cout << local;
    return 0;
}

#include <iostream>
using namespace std;
//Implementar o algoritmo SequentialSearch2 apresentado na Se¸c˜ao 3.2 do Cap´ıtulo 31
int main() {

    int k;
    int n;

    
    int i = 0;
    cout << "Defina o tamanho da matriz K\n";
    cin >> n;
    int a[n];

    cout << "Entre com os " << n << " números e pressione enter, após digitar cada um:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Entre com o valor da chave de pesquisa\n";
    cin >> k;




         a[n]=k;

         i=0;



         while (a[i] != k)
                 i = i + 1;
            if (i < n) {

                cout <<"A posição do item é : " << i;
             
                return i;


            } else{
				cout <<"O item não existe na matrix:\n";
                cout << -1;
                return -1;
            }



}

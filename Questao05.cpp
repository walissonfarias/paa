//Algoritmo brute force closest pair em C ++ 
#include <iostream>
#include <float>
#include <stdlib>
#include <math>
using namespace std;
//Algoritmo  de Brute Force Closest Pair
// Um programa de divis�o e conquista para encontrar a menor dist�ncia de um
// determinado conjunto de pontos.
// Uma estrutura para representar um Ponto no plano 2D
struct Ponto
{
    int x, y;
};
// Necess�rio classificar a matriz de pontos de acordo com a coordenada X
int compararX(const void* a, const void* b)
{
    Ponto* p1 = (Ponto*)a, * p2 = (Ponto*)b;
    return (p1->x - p2->x);
}
// Necess�rio para classificar a matriz de pontos de acordo com a coordenada Y
int compararY(const void* a, const void* b)
{
    Ponto* p1 = (Ponto*)a, * p2 = (Ponto*)b;
    return (p1->y - p2->y);
}

// Uma fun��o de utilidade para encontrar a dist�ncia entre dois pontos
float dist(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y));
}

// Um m�todo de for�a bruta para retornar a menor dist�ncia entre dois pontos
// em P [] de tamanho n
float forcaBruta(Ponto P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// Uma fun��o de utilidade para encontrar um m�nimo de dois valores flutuantes
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// Uma fun��o de utilidade para encontrar a dist�ncia entre os pontos mais pr�ximos de
// tira de um determinado tamanho. Todos os pontos na faixa [] s�o classificados de acordo com
// coordenada y. Todos eles t�m um limite superior na dist�ncia m�nima como d.
// Observe que este m�todo parece ser um m�todo O (n ^ 2), mas � um m�todo O (n)
// m�todo j� que o loop interno � executado no m�ximo 6 vezes
float stripClosest(Ponto strip[], int tamanho, float d)
{
    float min = d; // Inicializa a dist�ncia m�nima como d

    // Escolha todos os pontos um por um e tente os pr�ximos pontos at� a diferen�a
    // entre as coordenadas y � menor que d.
    // � um fato comprovado que este loop roda no m�ximo 6 vezes
    for (int i = 0; i < tamanho; ++i)
        for (int j = i + 1; j < tamanho && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// Uma fun��o recursiva para encontrar a menor dist�ncia. A matriz Px cont�m
// todos os pontos classificados de acordo com as coordenadas x e Py cont�m todos os pontos
// classificado de acordo com as coordenadas y
float closestUtil(Ponto Px[], Ponto Py[], int n)
{
    // Se houver 2 ou 3 pontos, use for�a bruta
    if (n <= 3)
        return forcaBruta(Px, n);

    // Encontre o ponto m�dio
    int mid = n / 2;
    Ponto midPoint = Px[mid];

    // Divide os pontos no array ordenado y em torno da linha vertical.
    // Suposi��o: Todas as coordenadas x s�o distintas.
    Ponto Pyl[mid];     // y pontos classificados � esquerda da linha vertical
    Ponto Pyr[n - mid]; // y pontos classificados � direita da linha vertical
    int li = 0, ri = 0; // �ndices de subarrays esquerdo e direito
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x && li < mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    // Considere a linha vertical passando pelo ponto m�dio
    // calcula a menor dist�ncia dl � esquerda do ponto m�dio e
    // dr no lado direito
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n - mid);

    // Encontre a menor das duas dist�ncias
    float d = min(dl, dr);

    // Constr�i uma faixa de matriz [] que cont�m pontos pr�ximos (mais pr�ximos do que d)
    // para a linha que passa pelo ponto m�dio
    Ponto strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Encontre os pontos mais pr�ximos na faixa. Retorne o m�nimo de d e o mais pr�ximo
    // a dist�ncia � strip []
    return stripClosest(strip, j, d);
}

// A fun��o principal que encontra a menor dist�ncia
// Este m�todo usa principalmente closestUtil()
float closest(Ponto P[], int n)
{
    Ponto Px[n];
    Ponto Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Ponto), compararX);
    qsort(Py, n, sizeof(Ponto), compararY);

    // // Use a fun��o recursiva closestUtil() para encontrar a menor dist�ncia
    return closestUtil(Px, Py, n);
}

// Programa de driver para testar as fun��es acima
int main()
{
    Ponto P[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(P) / sizeof(P[0]);
    cout << "A menor distancia " << closest(P, n);
    return 0;
}
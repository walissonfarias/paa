//Implementar o algoritmo BruteForceClosestPair apresentado na Se¸c˜ao 3.2 do Cap´ıtulo 31

#include <bits/stdc++.h>
using namespace std;

//representa um Ponto no plano
class Point
{
public:
    int x, y;
};


int compareX(const void* a, const void* b)
{
    auto *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}


int compareY(const void* a, const void* b)
{
    auto *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// A utility function to find the
// distance between two points
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
    );
}

// método de força bruta para retornar o
// menor distância
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}


float min(float x, float y)
{
    return (x < y)? x : y;
}



float distanc_prox(Point *strip, int size, float d)
{
    float min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);


    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

//A matriz P contém
// todos os pontos classificados de acordo com a coordenada x
float md(Point *P, int n)
{

    if (n <= 3)
        return bruteForce(P, n);


    int mid = n/2;
    Point midPoint = P[mid];

  //  calcular
  //   a menor distância
    float dl = md(P, mid);
    float dr = md(P + mid, n - mid);

    // Find the smaller of two distances
    float d = min(dl, dr);


    Point faixa_pontos[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            faixa_pontos[j] = P[i], j++;

    // Find the menorDistancia points in faixa_pontos.
    // Return the minimum of d and menorDistancia
    // distance is faixa_pontos[]
    return min(d, distanc_prox(faixa_pontos, j, d) );
}


float menorDistancia(Point *P, int n)
{
    qsort(P, n, sizeof(Point), compareX);


    // menor distância
    return md(P, n);
}


int main()
{
    Point P[] = {{1, 2}, {1, 7}, {1, 8}, {2, 6},
                 {2, 3}, {3, 4}, {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "A menor distância é " << menorDistancia(P, n);
    return 0;
}


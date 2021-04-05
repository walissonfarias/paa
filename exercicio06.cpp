//Implementar um algoritmo que dado um conjunto de pontos S calcule sua casca convexa (convex
//hull) (Ver Se¸c˜ao 3.3 do Cap´ıtulo 31
//)

#include <iostream>
#include <stack>

using namespace std;

struct Point
{
    int x, y;
};

Point p0;


Point topo(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}


void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}


int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// 0 -> p, q e r são colineares
// 1 -> Sentido horário
// 2 -> Anti-horário
int caminho(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // colinear
    return (val > 0)? 1: 2;
}

//para classificar um array de ponto
int compare(const void *vp1, const void *vp2)
{
    auto *p1 = (Point *)vp1;
    auto *p2 = (Point *)vp2;

//
    int o = caminho(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

//Imprime o casco convexo
void convexHull(Point pontos[], int n)
{
//fim
    int ymin = pontos[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = pontos[i].y;

        //   // mais pontos em caso de empate
        if ((y < ymin) || (ymin == y &&
                           pontos[i].x < pontos[min].x))
            ymin = pontos[i].y, min = i;
    }

//
    swap(pontos[0], pontos[min]);


    p0 = pontos[0];
    qsort(&pontos[1], n - 1, sizeof(Point), compare);


    int m = 1; // inicializa array
    for (int i=1; i<n; i++)
    {

        while (i < n-1 && caminho(p0, pontos[i],
                                  pontos[i + 1]) == 0)
            i++;


        pontos[m] = pontos[i];
        m++; //incrementa o array
    }

// modifica se tiver menos de 3 pontos,
    if (m < 3) return;

// empurre os primeiros três pontos
    stack<Point> S;
    S.push(pontos[0]);
    S.push(pontos[1]);
    S.push(pontos[2]);

//  n-3 pontos
    for (int i = 3; i < m; i++)
    {
        
        while (S.size()>1 && caminho(topo(S), S.top(), pontos[i]) != 2)
            S.pop();
        S.push(pontos[i]);
    }

// imprime o conteúdo da pilha
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        S.pop();
    }
}


int main()
{
    Point pontos[] = {{1, 2}, {1, 7}, {1, 8}, {2, 6},
                      {2, 3}, {3, 4}, {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}};



    int n = sizeof(pontos) / sizeof(pontos[0]);
    convexHull(pontos, n);
    return 0;
}

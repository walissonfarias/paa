//Busca em Profundidade
#include <iostream>
#include <list>
#include <memory>
#include <algorithm> 
#include <stack> 
   
void Graph(int V, bool direcionado)
{
    int v = V;
    bool dir = direcionado;       
}   
   
void AddAresta(int v, int w)
{
    std::list<int>* adjacente = adj.get();
    adjacente[v].push_back(w);
   
    if (!_direcionado)
    {
        adjacente[w].push_back(v);
    }
}
  
void Busca(int v, bool visitado[])
{
    visitado[v] = true; 
    std::cout << v << " ";
  
    // Varre todos os v�rtices adjacentes a este v�rtice.
    std::list<int>::iterator i;
    for (i = (adj.get())[v].begin(); i != (adj.get())[v].end(); ++i)
        if (!visitado[*i])
            Busca(*i, visitado);
}
  
// busca em profundidade dos v�rtices alcan��veis de v. 
void dfs(int v)
{
    // Marque todos os v�rtices como n�o visitados
    std::unique_ptr<bool[]> visitado(new bool[_V]);
     
    for (int i = 0; i < _V; i++)
        visitado[i] = false;
  
    // Chame a fun��o auxiliar recursiva 
    //para imprimir o percurso da busca em proundidade
    Busca(v, visitado.get());
}
  
int main()
{
	int _V;// quantidade de v�rtices
	bool _direcionado;
	std::unique_ptr<std::list<int>> adj;  // ponteiro para um array contendo as listas de adjac�ncia

	// a partir de um v�rtice faz uma busca em profundidade	
    // Crie um graph fornecido no diagrama acima
    Graph(7, true);
    AddAresta(0, 1);
    AddAresta(0, 2);
    AddAresta(0, 3);
    AddAresta(1, 0);
    AddAresta(1, 5);
    AddAresta(2, 5);
    AddAresta(3, 0);
    AddAresta(3, 4);
    AddAresta(4, 6);
    AddAresta(5, 1);
    AddAresta(6, 5);
  
    std::cout << "Busca em profundidade come�ando com o vertice 2:\n";
    dfs(2);

    return 0;
}

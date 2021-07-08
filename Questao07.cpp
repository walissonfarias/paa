#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100
#define BRANCO 0 /* cores para pintura dos vertices na
construcao dos percursos */
#define CINZA  1
#define PRETO  2
#define SEM_CONEX -1  // sem conexao entre cidades
#define INF 1000000 // um valor muito grande

/* Fun��o LeMatriz -
Objetivo: Ler os valores da matriz de adjac�ncias
Par�metros de entrada:
FILE *fp  -  ponteiro para um arquivo de entrada
ma[][MAX] - Arranjo bidimensional para armazenar a mtriz em mem�ria */

int LeMatriz(FILE* fp, int ma[][MAX]) {

    int register i, j;
    int n = 0;

    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(fp, "%d", &ma[i][j]);
    return n;
}

/* Fun��o PrintMatriz -
Objetivo: Imprime uma matriz quadrada na saida padr�o
Par�metros de entrada:
 ma[][MAX] - Arranjo bidimensional para armazenar a mtriz em mem�ria
 n - dimens�o da matriz */

void PrintMatriz(int ma[][MAX], int n) {
    int register i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            std::cout << ma[i][j];
        std::cout << std::endl;
    }
}

void Visita(int u, int ma[][MAX], int n) {
    int v, i;
    cor[u] = CINZA; /* pinta u de cinza para evitar
                  a constru��o de um ciclo no  percurso*/
    rota[visitas] = u; // a cidade u � incluida no percurso
    for (v = 0; v < n; v++)
        if (ma[u][v] != SEM_CONEX)
            if (cor[v] == BRANCO) { /* para todas as cidades adjacentes
                                  a u e de cor branca*/
                visitas++;  /* incremento o n�mero de cidades visitadas*/
                custo = custo + ma[u][v]; /*Contabilizo o custo da proxima visita*/
                pred[v] = u;  /* especifico quem � a cidade que entecede a pr�xima */
                            /*   visita*/
                Visita(v, ma, n);  /* visito a nova cidade v*/

            }

    cor[u] = BRANCO; /* se a cidade u n�o tiver mais nem
                      uma cidade adjacente que */
                      /*n�o tenha sido  visitada retorno a
                         cor dela para branco*/

                         /*Se nem todas as cidades foram visitada ou nao  existe
                         um conexao da �ltima  cidade ate a primeira entao apago
                         a ultima cidade do percurso*/


    if ((visitas < n - 1) || (ma[u][0] == SEM_CONEX)) {
        rota[visitas] = 0;
    }

    /*Se  todas as cidades foram visitada e
    existe uma conexao da �ltima cidade ate a
    primeira entao contabilizo o custo da
    conexao entre a ultima cidade e a primeira*/


    if ((visitas == n - 1) && (ma[u][0] != SEM_CONEX)) {
        //rota[visitas]=u;
        custo = custo + ma[u][0];

        /*Se o custo do percurso encontrado for menor que
         o menor  custo, copio a nova rota para menorrota
         e atualizo o menorcusto
        */

        if (custo < menorcusto) {
            menorcusto = custo;
            memcpy(menorrota, rota, n * sizeof(int));

        }
        custo = custo - ma[u][0];
    }
    /* decremento o n�mero de visitas e o custo
       para procurar outro percurso */
    visitas--;
    custo = custo - ma[pred[u]][u];
}
void VisitaEmProfundidade(int ma[][MAX], int n) {
    int register i, j, k;

    // inicializa vetores de cores e  precedentes
    for (i = 0; i < n; i++) {
        cor[i] = BRANCO;
        pred[i] = 0;
    }
    visitas = 0;
    Visita(0, ma, n); // encontrar a menor rota a partir  da cidade 0

}

/* defini��o de variaveis globais do programa */

int n = 0; // numero de vertice do grafo: numero de cidades
FILE* fp;

int ma[MAX][MAX]; /* matriz de adjascencia: Guarda
os custos de deslocamentos ntre as cidades */

/* Os arranjos Cor e Pred s�o usado na montagem
dos percurso pela fun��o isita que esta baseado
no algoritmo de busca em profundidade em grafos*/

int cor[MAX];
int pred[MAX];

/* Variaveis para armanzenamento de percursos
e custos dos percursos*/
int menorrota[MAX], rota[MAX];
int custo, menorcusto;

int visitas; /* Contar� o numero de visitas a cidades
durante a constru��o de um novo percurso */

main() {

    int i;
    /* tenta abrir o arquivo de dados:   entrada*/
    if (!(fp = fopen("entrada", "r"))) {
        printf("Problemas com a abertura do  arquivo\n");
        return 0;
    }

    /* Tenta Ler a inst�ncia do problema e armazena na matriz ma*/
    n = LeMatriz(fp, ma);

    fclose(fp);
    /*verifica se houve algum problema na leitura dos dados*/
    if (n == 0) {
        std::cout << "Problemas com a leitura dos dados" << std::endl;
        return 0;
    }

    /* inicializa o menorcusto com um valor alto (INF)inito */
    menorcusto = INF;
    custo = 0;
    for (i = 0; i < n; i++) {
        rota[i] = 0;
        menorrota[i] = 0;
    }
    /* chama o procedimento para encontrar a
     melhor solu��o: menor custo */
    VisitaEmProfundidade(ma, n);
    std::cout << menorcusto;
}
//referencia: N�vio Ziviani https://homepages.dcc.ufmg.br/~nivio/cursos/pa02/tp2/tp21/tp21.html
#include <stdio.h>

/* questao numero 18 */
/* implementaçao do dfs recursivo e iterativo */

#define V 6

const int am[V][V] =
{
  {0, 1, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0},
  {1, 0, 0, 1, 1, 1},
  {0, 0, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 0}
};

int stack[50];
int sp = 0;

void iterative_dfs() 
{
  int sv         = 0;
  stack[sp++]    = sv;
  int visited[V] = {0}; // array de linhas ja visitadas
  while (sp > 0) {
    int i = stack[--sp];

    if (visited[i]) // se o vertice i ja foi explorado, pula
      continue;
    
    // explorar
    visited[i] = 1;
    printf("%d, ", i);
    for (int j = 0; j < V; j++) 
      if (am[i][j] == 1 && !visited[j]) 
        stack[sp++] = j;
  }
}

int rstack[50];
int rvisited[V] = {0};
int rsp = 0;

void recursive_dfs(int sv) 
{
  rstack[rsp++] = sv;
  int i = rstack[--rsp];

  if (rvisited[i])
    return;

  // explorar
  rvisited[i] = 1; 
  printf("%d, ", i);
  for (int j = 0; j < V; j++) 
    if (am[i][j] == 1 && !rvisited[j]) 
      rstack[rsp++] = j;

  if (rsp > 0) 
    recursive_dfs(rstack[--rsp]);
}

int main(void) 
{
  // ambos começam do vertice 0
  iterative_dfs();
  printf("\n");
  recursive_dfs(0);
  printf("\n");
}

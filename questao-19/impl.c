#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int q[50];
int qs = 0;
int qe = 0;

int bfs(int start, int end) // start = 0, end = 4
{
	qs = 0;
	qe = 0;
	int visited[V] = {0};
	int found = 0;
	q[qe++] = start; // q[qe] = 0
	visited[start] = 1; // visited[0] = 1
	int way[V] = {0};  

	for (int i = 0; i < V; i++)
		way[i] = -1; // -1 -1 -1 -1 -1 -1

	while (qe > qs && !found) {
		int i = q[qs++]; // i = 0

		if (i == end) { // if 0 == 4
			found = 1;
			break; 
		}

		for (int j = 0; j < V; j++) 
			if (am[i][j] == 1 && !visited[j]) {
				q[qe++] = j; // empurrando pra fila
										 // i = 0, j
				visited[j] = 1; // marcando o indice como visitado
				way[j] = i; // lembrando o no para o no que encontrou ele
						// iteraçoes:
						// i = 0, j = 1
						// i = 0, j = 2
						// queue: 1, 2
						// visited: 1, 1, 1, 0, 0, 0
						// way: -1, 0, 0, -1, -1, -1
						// i = 1 . ignorado, porque j não acha 1 valido
						// queue: 2
						// visited: 1, 1, 1, 0, 0, 0
						// way: -1, 0, 0, -1, -1, -1
						// i = 2, j = 3
						// queue: 3
						// visited: 1, 1, 1, 1, 0, 0
						// way: -1, 0, 0, 2, -1, -1
						// i = 2, j = 4
						// queue: 3
						// visited: 1, 1, 1, 1, 1, 0
						// way: -1, 0, 0, 2, 2, -1
						// i = 2, j = 5
						// queue: 3
						// visited: 1, 1, 1, 1, 1, 1
						// way: -1, 0, 0, 2, 2, 2
						// queue: 3, 4, 5
						// visited: 1, 1, 1, 1, 1, 1
						// way: -1, 0, 0, 2, 2, 2
						// i = 3 . ignorado, porque j acha 2, porem ja visitado
						// queue: 4, 5
						// visited: 1, 1, 1, 1, 1, 1
						// way: -1, 0, 0, 2, 2, 2
						// i = 4!! i == end.
						// queue: 5
						// visited: 1, 1, 1, 1, 1, 1
						// way: -1, 0, 0, 2, 2, 2
						// acabou.
			}
	}
	if (found) {
		printf("encontrado:\n");

		int path[V];
		int len = 0;
		int curr = end;

		while (curr != -1) {
			path[len++] = curr;
			curr = way[curr];
		}

		for (int i = len - 1; i >= 0; i--) {
			printf("%d", path[i]);
			if (i > 0) 
				printf(" -> ");
		}
		printf("\n");
		return 0;
	}
	printf("nao encontrado\n");
	return -1;
}

int main(void) 
{
	char buf[5];
	printf("modelo: primeiro_node:node_alvo\n");
	printf("caminho a achar: ");
	fgets(buf, sizeof buf, stdin);
	char* mid = strchr(buf, ':');

	if (mid) {
		*mid = '\0';
		*(mid + 2) = '\0';
	}

	int x = atoi(mid - 1);
	int y = atoi(mid + 1);

	printf("x: %d\ny: %d\n", x, y);

	bfs(x, y);
}

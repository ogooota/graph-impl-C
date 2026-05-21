#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// este programa e apenas uma demonstraçao

#define V 6
#define size 3

const int am[V][V] =
{
	{0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0}
};

const int al[V][V] =
{
	[0] = {1, 2},
	[1] = {0},
	[2] = {0, 3, 4, 5},
	[3] = {2},
	[4] = {2},
	[5] = {2},
};

int** list_to_matrix(const int al[size][size], int n)
{
	int** am = malloc(sizeof(int*) * n);

	if (!am) {
		perror("malloc");
		return NULL;
	}

	for (int i = 0; i < n; i++) 
		am[i] = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) 
		memset(am[i], 0, n);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (al[i][j] != -1) {
				am[i][j] = 1;
				continue;
			}
			am[i][j] = 0;
		}
	}
	return am;
}

void print_matrix() 
{
	printf("representaçao em matriz:\n");
	for (int i = 0; i < V; i++) {
		printf("| ");
		for (int j = 0; j < V; j++) {
			printf("%d", am[i][j]);
			if (j < V - 1) 
				printf(", ");
		}
		printf(" |\n");
	}
}

void print_list()
{
	printf("representaçao em lista:\n");
	for (int i = 0; i < V; i++) {
		printf("%d -> ", i);
		for (int j = 0; j < V; j++) {
			if (al[i][j] == 0)
				continue;
			printf("%d", al[i][j]);
			if (j < V - 1) 
				printf(", ");
		}
		printf("\n");
	}
}


int main(void) 
{
	print_matrix();
	print_list();

	printf("esta e uma lista criada apenas para a conversao:\n");
	const int conversion[size][size] = {
		[0] = {-1, 1, 2},
		[1] = {-1, -1, -1}, // tive que colocar -1 para representar nada
		[2] = {-1, -1, -1}
	};

	printf("formato lista:\n");
	for (int i = 0; i < size; i++) {
		printf("%d -> ", i);
		for (int j = 0; j < size; j++) {
			if (conversion[i][j] < 0)
				continue;

			printf("%d", conversion[i][j]);
			if (j < V - 1) 
				printf(", ");
		}
		printf("\n");
	}

	int** converted = list_to_matrix(conversion, size);

	printf("apos conversao:\n");
	for (int i = 0; i < size; i++) {
		printf("| ");
		for (int j = 0; j < size; j++) {
			printf("%d", converted[i][j]);
			if (j < size - 1) 
				printf(", ");
		}
		printf(" |\n");
	}
}

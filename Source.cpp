#include <stdio.h>

#define NORDS 4
#define INFINITE 100000000

int visited[NORDS];
int cost[NORDS];
int prev[NORDS];
int route[NORDS][NORDS];

void search(int start) {
	int min;
	int next;
	int newcost;

	cost[start] = 0;
	while (start != -1) {
		min = INFINITE;
		next = -1;
		visited[start] = true;
		for (int i = 0; i < NORDS; i++) {
			if (visited[i] == false && route[start][i] != 0) {
				newcost = cost[start] + route[start][i];
				if (newcost < cost[i]) {
					cost[i] = newcost;
					prev[i] = start;
				}
				if (cost[i] < min) {
					min = cost[i];
					next = i;
				}
			}
		}
		start = next;
	}
}

void printPath(int start, int goal) {
	int node;
	node = goal;
	while (node != start) {
		printf("%d < ", node);
		node = prev[node];
	};
	printf("%d", node);

}

int main() {
	route[0][0] = 0;
	route[0][1] = 2;
	route[0][2] = 4;
	route[0][3] = 0;
	route[1][0] = 2;
	route[1][1] = 0;
	route[1][2] = 1;
	route[1][3] = 3;
	route[2][0] = 4;
	route[2][1] = 1;
	route[2][2] = 0;
	route[2][3] = 1;
	route[3][0] = 0;
	route[3][1] = 3;
	route[3][2] = 1;
	route[3][3] = 0;
	for (int i = 0; i < NORDS; i++) {
		cost[i] = INFINITE;
		visited[i] = false;
	}

	search(0);
	printPath(0, 3);

	return 0;
}

#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int bestPath[MAX];
int tempPath[MAX];
int minCost = INT_MAX;

void tsp(int city, int count, int totalCost, int start) {
    tempPath[count - 1] = city;  // store current city in path

    if (count == n && cost[city][start] > 0) {
        int finalCost = totalCost + cost[city][start];
        if (finalCost < minCost) {
            minCost = finalCost;
            for (int i = 0; i < n; i++)
                bestPath[i] = tempPath[i];
            bestPath[n] = start;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, totalCost + cost[city][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start = 0;
    visited[start] = 1;

    tsp(start, 1, 0, start);

    printf("\nMinimum Cost: %d\n", minCost);
    printf("Optimal Path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d", bestPath[i]);
        if (i < n) printf(" -> ");
    }
    printf("\n");

    return 0;
}

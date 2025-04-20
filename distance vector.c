#include <stdio.h>

#define INF 999
#define N 3

void distanceVector(int cost[N][N]) {
    int dist[N][N], i, j, k;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = cost[i][j];

    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];  // Update shortest path

    printf("Final Distance Table:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
}

int main() {
    int cost[N][N] = { {0, 2, INF}, {2, 0, 3}, {INF, 3, 0} };

    distanceVector(cost);

    return 0;
}

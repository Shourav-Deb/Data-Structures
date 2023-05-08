//  Write a program that takes a directed graph as input. It will classify the edges after applying DFS search algorithm.

#include <stdio.h>
#include <stdlib.h>
#define Node 100


int graph[Node][Node], visit[Node], n;
char edges[Node][Node][60];


void DFS(int node) {

    visit[node] = 1;

    for (int j = 0; j < n; j++)
    {
        if (graph[node][j] == 0)
            continue;


        if (visit[j] == 0)
        {
            sprintf(edges[node][j], "Has Not visited!");
            DFS(j);
        }

        else
        {
            if (visit[j] == 1)
                sprintf(edges[node][j], "Visited & it is in the current path.");
            else
                sprintf(edges[node][j], "Visited but it is in the different path.");
        }
    }
    visit[node] = 2;
}

int main() {
    printf("Enter the number of vertex for creating the graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix for the directed graph:\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Connection from %d to %d: ",i,j);
            scanf("%d", &graph[i][j]);
            sprintf(edges[i][j], "NULL");
        }
        visit[i] = 0;
    }


    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
            DFS(i);
    }


    printf("\nEdge Details:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("(%d, %d): %s\n", i, j, edges[i][j]);
            }
        }
    }

    return 0;
}

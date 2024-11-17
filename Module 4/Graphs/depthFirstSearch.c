#include <stdio.h>
#define MAX_VERTICES 10

void depthFirstSearch(int vertex, int visited[MAX_VERTICES], int adjMat[MAX_VERTICES][MAX_VERTICES], int numVer){
    printf("V%d ", vertex);
    visited[vertex] = 1;

    // Visiting all unvisited neighbours:
    for(int i=0; i<numVer; i++){
        if(adjMat[vertex][i] == 1 && !visited[i])
            depthFirstSearch(i,visited,adjMat,numVer);
    }
}

int main(){
    int num;
    printf("Enter the number of vertices: ");
    scanf("%d",&num);
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the Adjacency Matrix: \n");
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal: ");
    for(int i=0; i<num; i++){
        if(!visited[i])
            depthFirstSearch(i,visited,adjacencyMatrix,num);
    }
    return 0;
}
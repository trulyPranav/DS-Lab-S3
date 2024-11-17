#include <stdio.h>
#define MAX_VERTICES 10

void breadthFirstSearch(int startVertex, int visited[MAX_VERTICES], int adjMat[MAX_VERTICES][MAX_VERTICES], int numVer){
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while(front!=rear){
        int currVertex = queue[++front];
        printf("V%d ", currVertex);

        for(int i=0; i<numVer; i++){
            if(adjMat[currVertex][i] == 1 && !visited[i]){
                queue[++rear]  = i;
                visited[i] = 1;
            }
        }
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
    printf("BFS Traversal: ");
    for(int i=0; i<num; i++){
        if(!visited[i])
            breadthFirstSearch(i,visited,adjacencyMatrix,num);
    }
    return 0;
}
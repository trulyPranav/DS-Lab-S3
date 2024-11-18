#include <stdio.h>
#include <stdlib.h>
#define TREE_SIZE  7

void setNode(int tree[], int index, int value){
    tree[index] = value;
}

void setLeftChild(int tree[], int parentIndex, int value){
    if(0<=parentIndex<=TREE_SIZE){
        int leftChildIndex = 2*parentIndex + 1;
        if(leftChildIndex < TREE_SIZE)
            setNode(tree,leftChildIndex,value);
        else
            printf("\nLeft Child Index Out of Bounds\n");
    }
    else printf("\nInvalid Parent Index!\n");
}

void setRightChild(int tree[], int parentIndex, int value){
    if(0<=parentIndex<=TREE_SIZE){
        int rightChildIndex = 2*parentIndex + 2;
        if(rightChildIndex < TREE_SIZE)
            setNode(tree, rightChildIndex, value);
        else 
            printf("\nRight Child Index Out of Bounds\n");
    }
    else printf("\nInvalid Parent Index!\n");
}

void printRep(int tree[], int n){
    printf("Array Representation of Binary Tree is: ");
    for(int i=0; i<n; i++){
        if(tree[i] != -1)
            printf("%d", tree[i]);
        else printf("-");
    }
    printf("\n");
}

int main(){
    //     1
    //    /  \
    //   2    3
    //  / \     \
    // 4   5     6    
    int binaryTree[] = {-1,-1,-1,-1,-1,-1,-1};
    setNode(binaryTree,0,1);
    setNode(binaryTree,1,2);
    setNode(binaryTree,2,3);
    setLeftChild(binaryTree, 1, 4);
    setRightChild(binaryTree, 1, 5);

    setRightChild(binaryTree,2,6);

    printRep(binaryTree, TREE_SIZE);
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int key){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> key = key;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int key){
    if(root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insertNode(root->left,key);
    else if (key > root->key)
        root->right = insertNode(root->right,key);
    return root;
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
    printf("\n");
}

void preOrder(struct Node *root){
    if(root!=NULL){
        printf("%d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->key);
    }
}

struct Node *search(struct Node *root, int key){
    if(root == NULL || root->key == key)
        return root;
    if(key < root->key)
        return search(root->left, key);
    if(key > root->key)
        return search(root->right,key);
}

int findMin(struct Node *root){
    while(root->left != NULL)
        root = root->left;
    return root->key;
}

int findMax(struct Node *root){
    while(root->right != NULL)
        root = root->right;
    return root->key;
}

struct Node *inOrderSuccessor(struct Node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int key){
    if(root == NULL)
        return root;
    else if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL){
            struct Node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = inOrderSuccessor(root->right);
        root -> key = temp -> key;
        root-> right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main(){
    printf("Welcome to Binary Search Tree!");
    while(1){
        printf("\n1)Insert\n2)PreOrder Traversal\n3)InOrder Traversal\n4)PostOrder Traversal\n5)Delete\n6)Search\n7)Minumum Element\n8)Maximum Element\n9)Exit\nChoose the Operation: ");
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                printf("\nEnter element to insert: ");
                int elm;
                scanf("%d", &elm);
                if(root == NULL)
                    root = insertNode(root,elm);
                else 
                    insertNode(root,elm);
                break;
            case 2:
                printf("\nPreOrder Traversal: ");
                preOrder(root);
                break;
            case 3:
                printf("\nInOrder Traversal: ");
                inOrder(root);
                break;
            case 4:
                printf("\nPostOrder Traversal: ");
                postOrder(root);
                break;
            case 5:
                int del;
                printf("\nEnter element to delete: ");
                scanf("%d",&del);
                root = deleteNode(root,del);
                printf("\nIn-Order Traversal after Deleting %d: ", del);
                inOrder(root);
                break;       
            case 6:
                printf("Enter the key to search:");
                int key;
                scanf("%d",&key);
                struct Node *temp = NULL;
                temp=search(root,key);
                if (temp==NULL)
                printf("Key NOT Found \n");
                else
                printf("Key Found \n");
                break;
            case 7: 
                printf("Minimum key element is = %d\n",findMin(root));
                break;
            case 8:
                printf("Maximum key element is = %d\n",findMax(root));
                break;
            case 9:
                exit(1);
                break;
            default:
                printf("\nChoose a valid Operation!");
        }
    }
    return 0;
}
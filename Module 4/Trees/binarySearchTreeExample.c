#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node *root=NULL,*temp=NULL;

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int key) {
    // Base case: if the tree is empty, create a new node
    if (node == NULL) {
        return createNode(key);
    }

    // Compare the key with the current node's key
    if (key < node->key) {
        // Recursively insert into the left subtree
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        // Recursively insert into the right subtree
        node->right = insert(node->right, key);
    }

    // Return the modified node
    return node;
}
void inOrderTraversal(struct Node* node) {
    if (node != NULL) {
        // Traverse the left subtree
        inOrderTraversal(node->left);

        // Visit the current node
        printf("%d---",node->key);

        // Traverse the right subtree
        inOrderTraversal(node->right);
    }
}
void preOrderTraversal(struct Node* node) {
    if (node != NULL) {
        // Visit the current node
         printf("%d---",node->key);

        // Traverse the left subtree
        preOrderTraversal(node->left);

        // Traverse the right subtree
        preOrderTraversal(node->right);
    }
}
void postOrderTraversal(struct Node* node) {
    if (node != NULL) {
        // Traverse the left subtree
        postOrderTraversal(node->left);

        // Traverse the right subtree
        postOrderTraversal(node->right);

        // Visit the current node
         printf("%d---",node->key);
    }
}

struct Node* search(struct Node* root, int key) {
    // Base cases: the key is not present or the root is null
    if (root == NULL || root->key == key) {
        return root;
    }

    // Key is smaller than the root's key, search in the left subtree
    if (key < root->key) {
        return search(root->left, key);
    }

    // Key is greater than the root's key, search in the right subtree
    return search(root->right, key);
}

int findMinimum(struct Node* root) {
    // Base case: the leftmost leaf node contains the minimum value
    while (root->left != NULL) {
        root = root->left;
    }
    return root->key;
}
int findMaximum(struct Node* root) {
    // Base case: the rightmost leaf node contains the maximum value
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}
struct Node* inordersucc(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
// Function to delete a key from a BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = inordersucc(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int main()
{
    int op,key;
     do
    {
    printf("\n.menu\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.search\n7.Minimum\n8.Maximum\n9.exit\nenter option\n");
    scanf("%d",&op);
     switch(op)
     {
        case 1:printf("Enter the key:");
               scanf("%d",&key);
               if (root==NULL)
                root=insert(root,key);
                else
                insert(root,key);
                break;
        case 2:printf("Preorder Traversal\n");
               preOrderTraversal(root);
               break;
	    case 3:printf("Postorder Traversal\n");
	           postOrderTraversal(root);
	           break;
	    case 4:
	            printf("Inorder traversal\n");
	            inOrderTraversal(root);
	            break;
	   case 5:
	          printf("Enter the key to delete:");
              scanf("%d",&key);
	          root = deleteNode(root, key);
              printf("In-Order Traversal after deleting %d: ", key);
              inOrderTraversal(root);
	          break;
	   case 6:
	          printf("Enter the key to search:");
              scanf("%d",&key);
	          temp=search(root,key);
	          if (temp==NULL)
	           printf("Key not Found \n");
	          else
	           printf("key found \n");
	          break;
	  case 7:printf("Minimum key element is =%d\n",findMinimum(root));
	         break;
	  case 8:printf("Maximum key element is =%d\n",findMaximum(root));
	         break;
      }
     }
   while(op!=9);
  return 0;
    
}


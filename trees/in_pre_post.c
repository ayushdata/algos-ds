// C Program for Level Order Tree Traversal.

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in the tree
typedef struct node {
    struct node *left;
    int info;
    struct node *right;
} node;

// Function to allocate memory and to initialize the node
node *makenode(int info) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->info = info;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(node *root) {
    if (root){
        inorder(root -> left);
        printf("%d ", root -> info);
        inorder(root -> right);
    }
}
void preorder(node *root) {
    if (root){
        printf("%d ", root -> info);
        inorder(root -> left);
        inorder(root -> right);
    }
}
void postorder(node *root) {
    if (root){
        inorder(root -> left);
        inorder(root -> right);
        printf("%d ", root -> info);
    }
}

int main(void) {
    // Constructing the tree
    node *root = makenode(99);
    root -> left = makenode(12);
    root -> right = makenode(18);
    root -> left -> left = makenode(23);
    root -> left -> right = makenode(49);
    root -> left -> right -> left = makenode(50);
    root -> left -> right -> right = makenode(78);
    root -> right -> left = makenode(58);
    root -> right -> right = makenode(67);

    // Print in different orders
    printf("Inorder: ");
    inorder(root);
    printf("\nPre Order: ");
    preorder(root);
    printf("\nPost Order: ");
    postorder(root);

    printf("\n");
}
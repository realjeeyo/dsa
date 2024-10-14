#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

typedef struct{
    NodePtr front;
    NodePtr last;
} Queue;

bool insertBST(BST *b, int data); // Done
void initBST(BST *b); // Done
BST createBST(); // Done

void preorder(BST b); // Done
void inorder(BST b); // Done
void postorder(BST b); // Done

// void BFS(BST b);

void main(){
    BST b = createBST();
    
    insertBST(&b, 10);
    insertBST(&b, 8);
    insertBST(&b, 100);
    insertBST(&b, 5);
    insertBST(&b, 9);
    insertBST(&b, 16);
    insertBST(&b, 7);
    insertBST(&b, 69);
    insertBST(&b, 24);
    insertBST(&b, 78);
    
    inorder(b);
}

// void BFS(BST b){
//     Queue q;
//     q->front = NULL;
//     q->last = NULL;
    
    
// }

void preorder(BST b){
    if(b!=NULL){
        printf("%d ", b->data);
        preorder(b->left);
        preorder(b->right);
    }
}
void inorder(BST b){
    if(b!=NULL){
        inorder(b->left);
        printf("%d ", b->data);
        inorder(b->right);
    }
}
void postorder(BST b){
    if(b!=NULL){
        postorder(b->left);
        postorder(b->right);
        printf("%d ", b->data);
    }
}

void initBST(BST *b){
    *b = NULL;
}

BST createBST(){
    BST b = NULL;
    return b;
}

bool insertBST(BST *b, int data){
    NodePtr *trav = b;
    while (*trav != NULL && (*trav)->data != data){
        trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
    } 
    if (*trav == NULL){
        *trav = calloc(1, sizeof(NodeType));
        (*trav)->data = data;
        return true;
    }
    return false;
    
}

#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct node{
    lint data;
    struct node* left;
    struct node* right;
} node;

node* CreateNode(lint val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* InsertToBST(node* head, lint val) {
    if(head == NULL) return CreateNode(val);
    if(val < (head)->data) (head)->left =  InsertToBST(((head)->left), val);
    if(val > (head)->data) (head)->right =  InsertToBST(((head)->right), val);
    return head;
}

void PreorderTraversal(node* head) {
    if(head == NULL) return;
    printf("%lld->", (head)->data);
    PreorderTraversal((head)->left);
    PreorderTraversal((head)->right);
}

void InorderTraversal(node* head) {
    if(head == NULL) return;
    InorderTraversal((head)->left);
    printf("%lld->", (head)->data);
    InorderTraversal((head)->right);
}

void PostorderTraversal(node* head) {
    if(head == NULL) return;
    PostorderTraversal((head)->left);
    PostorderTraversal((head)->right);
    printf("%lld->", (head)->data);
}

int main() {
    node* BST = NULL;
    BST = InsertToBST(BST, 10);
    BST = InsertToBST(BST, 11);
    BST = InsertToBST(BST, 12);
    BST = InsertToBST(BST, 9);
    BST = InsertToBST(BST, 3);
    BST = InsertToBST(BST, 5);
    BST = InsertToBST(BST, 7);
    BST = InsertToBST(BST, 6);
    InorderTraversal(BST);
    return 0;
}
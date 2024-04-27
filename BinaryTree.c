#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct node {
    lint data;
    struct node* left;
    struct node* right;
}node;

node* CreateNode(lint val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = val;
    return new_node;
}

void InsertLeft(node** N, lint val) {
    if(*N != NULL) (*N)->left = CreateNode(val);
    else *N = CreateNode(val);
}

void InsertRight(node** N, lint val) {
    if(*N != NULL) (*N)->right = CreateNode(val);
    else *N = CreateNode(val);
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
    node* BT = NULL;
    InsertLeft(&BT, 10);
    InsertRight(&BT, 11);
    InsertLeft(&(BT->left), 12);
    InsertRight(&(BT->left), 13);
    InsertLeft(&(BT->right), 14);
    InsertRight(&(BT->right), 15);
    PreorderTraversal(BT);
    printf("\n");
    InorderTraversal(BT);
    printf("\n");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct node{
    lint data;
    struct node * next;
} node;

typedef struct que {
    node* head;
    node* tail;
    lint size;
} que;

que* CreateQueue() {
    que* new_q = (que*)malloc(sizeof(que));
    new_q->head = NULL;
    new_q->tail = NULL;
    new_q->size = 0;
    return new_q;
}

node* CreateNode(int val) {
    node* new_node = (node*)malloc(sizeof(new_node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void Enqueue(que* Q, lint val) {
    node* newnode = CreateNode(val);
    if(Q->head == NULL && Q->tail == NULL) {
        Q->head = newnode;
        Q->tail = Q->head;
    } else {
        Q->tail->next = newnode;
        Q->tail = Q->tail->next;
    }
    Q->size++;
}

void Dequeue(que* Q) {
    if(Q->head == NULL && Q->tail == NULL) {
        printf("--Que is empty--\n");
    } else if(Q->head->next == NULL) {
        node* to_delete = Q->head;
        Q->head = NULL;
        Q->tail = NULL;
        free(to_delete);
        Q->size--;
    } else {
        node* to_delete = Q->head;
        Q->head = Q->head->next;
        free(to_delete);
        Q->size--;
    }
}

//utility funciton:
void PrintQueue(que* Q) {
    for(node* it = Q->head; it != Q->tail->next; it = it->next) printf("%lld ", it->data);
    printf("\n");
}

int main() {
    que* Q = CreateQueue();
    Enqueue(Q, 10);
    Enqueue(Q, 11);
    Enqueue(Q, 12);
    Dequeue(Q);
    Enqueue(Q, 13);
    Dequeue(Q);
    PrintQueue(Q);
    return 0;
}
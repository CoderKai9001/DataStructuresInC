#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct node {
    lint data;
    struct node* next;
    struct node* prev;
} node;

node* CreateNode(lint val){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void InsertAtEnd(node** head, lint val) {
    if(*head == NULL) {
        *head = CreateNode(val);
    } else {
        node* it = *head;
        while(it->next != NULL) it = it->next;
        it->next = CreateNode(val);
        node* new = it->next;
        new->prev = it;
    }
}

void InsertAtBeginning(node** head, lint val) {
    if(*head == NULL) {
        *head = CreateNode(val);
    } else {
        node* new_node = CreateNode(val);
        new_node->next = (*head);
        (*head)->prev = new_node;
        (*head) = new_node;
    }
}

void DeleteAtBeginning(node** head) {
    if(*head == NULL) {
        printf("--empty--\n");
    } else {
        if((*head)->next == NULL) {
            node* to_delete = (*head);
            (*head) = NULL;
            free(to_delete);
        } else {
            node* to_delete = (*head);
            (*head) = (*head)->next;
            (*head)->prev = NULL;
            free(to_delete);
        }
    }
}

void DeleteAtEnd(node** head) {
    if(*head == NULL) {
        printf("--empty--\n");
    } else {
        if((*head)->next == NULL) {
            node* to_delete = (*head);
            (*head) = NULL;
            free(to_delete);
        } else {
            node* fast = (*head);
            node* slow = (*head);
            fast = fast->next;
            while(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = NULL;
            free(fast);
        }
    }
}

//utility function to print list:
void PrintList(node** head) {
    if(*head == NULL) printf("--empty--\n");
    else {
        node* it = *head;
        while(it->next != NULL){
            printf("%lld->", it->data);
            it = it->next;
        }
        printf("%lld\n", it->data);
    }
}

int main() {
    node* dll = NULL;
    InsertAtEnd(&dll, 10);
    InsertAtEnd(&dll, 11);
    InsertAtEnd(&dll, 12);
    InsertAtBeginning(&dll, 9);
    InsertAtEnd(&dll, 13);
    InsertAtBeginning(&dll, 8);
    InsertAtEnd(&dll, 14);
    DeleteAtBeginning(&dll);
    DeleteAtEnd(&dll);
    DeleteAtBeginning(&dll);
    DeleteAtEnd(&dll);
    PrintList(&dll);
    return 0;
}
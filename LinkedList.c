#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct node {
    lint data;
    struct node* next;
} node;

node* CreateNode(lint val) {
    node* Newnode = (node*)malloc(sizeof(node));
    Newnode->data = val;
    Newnode->next = NULL;
    return Newnode;
}

void InsertAtBeginning(node** list, lint val) {
    if(*list == NULL) {
        *list = CreateNode(val);
    } else {
        node* newHead = CreateNode(val);
        newHead->next = *list;
        *list = newHead;
    }
}

void InsertAtEnd(node** list, lint val) {
    if(*list == NULL) {
        *list = CreateNode(val);
    } else {
        node* it = *list;
        while(it->next != NULL) it = it->next;
        it->next = CreateNode(val);
    }
}

void AddAtPosition(node** list, int val, int pos) {
    node* newNode = CreateNode(val);
    if (pos == 0) {
        newNode->next = *list;
        *list = newNode;
    } else if (pos > 0) {
        node* it = *list;
        int k = pos - 1;
        while (k-- && it != NULL) it = it->next;
        if (it == NULL) {
            free(newNode);
            return;
        }
        newNode->next = it->next;
        it->next = newNode;
    } else {
        free(newNode);
    }
}

void DeleteAtBeginning(node** list) {
    if(*list == NULL) {
        printf("--List is enpty--\n");
    } else {
        node* to_delete = *list;
        *list = (*list)->next;
        free(to_delete);
    }
}

void DeleteAtEnd(node** list) {
    if(*list == NULL) {
        printf("--List is enpty--\n");
    } else {
        node* it = *list;
        if(it->next == NULL) {
            free(it);
            *list = NULL;
        } else {
            while(it->next->next != NULL) it = it->next;
            free(it->next);
            it->next = NULL;
        }
    }
}

void DeleteAtPosition(node** list, int pos) {
    if(*list == NULL) {
        printf("--List is empty--\n");
    } else {
        if (pos == 0) {
            node* to_delete = *list;
            *list = (*list)->next;
            free(to_delete);
        } else if (pos > 0) {
            node* it = *list;
            int k = pos - 1;
            while (k-- && it != NULL && it->next != NULL) {
                it = it->next;
            }
            if (it == NULL || it->next == NULL) {
                return;
            }
            node* to_delete = it->next;
            it->next = it->next->next;
            free(to_delete);
        } else {
            printf("--position is negative--\n");
        }
    }
}

void PrintList(node* list) {
    node* it = list;
    if(it == NULL) printf("Empty :(\n");
    else {
        while(it->next != NULL) {
           printf("%lld->", it->data);
           it = it->next;
        }
        printf("%d\n", it->data);
    }
}

int main() {
    node* LL = NULL;
    AddAtPosition(&LL, 10, 0);
    AddAtPosition(&LL, 12, 1);
    AddAtPosition(&LL, 11, 1);
    DeleteAtPosition(&LL, 1);
    AddAtPosition(&LL, 11, 1);
    DeleteAtPosition(&LL, 0);
    AddAtPosition(&LL, 10, 0);
    DeleteAtPosition(&LL, 2);
    AddAtPosition(&LL, 12, 2);
    PrintList(LL);
    return 0;
}
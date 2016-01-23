#include <stdio.h>
#include <stdlib.h>

struct linkedNode {
    struct linkedNode   *next;
    int payLoad;
};

static struct linkedNode *head = 0;

static void printList(struct linkedNode *start) {
    while (start) {
        printf("%d\n", start->payLoad);
        start = start->next;
    }
}

static void addToEnd(struct linkedNode **start, int payload) {
    struct linkedNode *node = (struct linkedNode *) malloc(sizeof(struct linkedNode));
    struct linkedNode *cur = *start;

    node->next = NULL;
    node->payLoad = payload;

    if (*start == NULL) {
        *start = node;
        return;
    }

    while (cur->next) {
        cur = cur->next;
    }

    cur->next = node;
}

int runLinkedList() {

    printf("Test Linked List:\n");
    addToEnd(&head, 1);
    addToEnd(&head, 2);
    addToEnd(&head, 3);
    addToEnd(&head, 4);

    printList(head);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char *name;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(const char *name)
{

    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->name = malloc(sizeof(name));

    if (node->name == NULL)
    {
        free(node);
        return NULL;
    }

    node->next = NULL;
    node->prev = NULL;

    strcpy(node->name, name);

    return node;
}

struct Node *insert(struct Node *currentNode, struct Node *targetNode)
{
}

int main(void)
{

    return 1;
}
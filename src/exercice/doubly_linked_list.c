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

struct Node *insertNext(struct Node *currentNode, struct Node *nextNode)
{
    currentNode->next = nextNode;

    nextNode->prev = currentNode;

    return nextNode;
}

struct Node *insertPrevious(struct Node *currentNode, struct Node *prevNode)
{
    currentNode->prev = prevNode;

    prevNode->next = currentNode;

    return prevNode;
}

struct Node *deleteNext(struct Node *node)
{
    struct Node *nextNode = node->next;

    node->next = NULL;

    return nextNode;
}

struct Node *deletePrev(struct Node *node)
{
    struct Node *prevNode = node->prev;

    node->prev = NULL;

    return prevNode;
}

void printNodeName(struct Node *node)
{

    if (node == NULL)
    {
        return;
    }

    printf("%s", node->name);
}

struct Node *findNode(struct Node *currentNode, char *c)
{
    struct Node *nodePtr = currentNode->next;

    while (nodePtr != NULL)
    {

        if (strcmp(nodePtr->name, c) == 0)
        {
            return nodePtr;
        }

        nodePtr = nodePtr->next;
    }
}

int main(void)
{

    struct Node *rootNode = createNode("Root");

    struct Node *l1Node = createNode("L1");

    struct Node *l2Node = createNode("L2");

    insertNext(rootNode, l1Node);
    insertNext(l1Node, l2Node);

    

    struct Node* result = findNode(rootNode,"L2");

    printNodeName(result);

    return 1;
}
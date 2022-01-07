#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

struct AdjList {
    struct AdjListNode *head;
};

struct Graph {
    int V;
    struct AdjList *array;
};

struct AdjListNode *create_node(int dest) {
    struct AdjListNode *node
        = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
        
    node->dest = dest;
    node->next = NULL;

    return node;
}

void add_edge(struct Graph *graph, int src, int dest) {

    struct AdjListNode *newNode;

    newNode = create_node(dest);

    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = create_node(src);

    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void print_graph(struct Graph *graph) {
    int i;
    struct AdjListNode *tmp;

    for (i=0; i<graph->V; i++) {
        tmp = graph->array[i].head;
        printf("%d: ", i);
        while (tmp) {
            printf("%d - ", tmp->dest);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

struct Graph *create_graph(int V) {
    int i;
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;
    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));
    
    for (i=0; i<V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

int main() {
    int V = 5;
    struct Graph *graph = create_graph(V);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    print_graph(graph);

    return 0;
}
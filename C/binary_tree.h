#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



typedef struct tree_node_s {
    int value;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

typedef struct list_s {
	tree_node_t *item;
	struct list_s *next;
}list_t; 

tree_node_t *insert(tree_node_t *node, int value);
tree_node_t *dfs(tree_node_t *node, int value);
tree_node_t *bfs(tree_node_t *node, int value);

#endif /*BINARY_TREE_H*/
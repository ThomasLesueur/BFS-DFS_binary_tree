#include "binary_tree.h"

tree_node_t *pop_front(list_t **l)
{
    tree_node_t *returned = NULL;
    list_t *tmp = *l;

    if (tmp == NULL) {
        printf("Error: No item to remove\n");
        return NULL;
    }
    returned = tmp->item;
    *l = tmp->next;
    free(tmp);
    return returned;
}

void append(list_t **l, tree_node_t *item)
{
    list_t *new = NULL;
    list_t *tmp = *l;

    new = malloc(sizeof(*new));
    if (!(new))
        return;
    new->item = item;
    new->next = NULL;
    if (*l == NULL)
        *l = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

tree_node_t *insert(tree_node_t *node, int value)
{
    tree_node_t *new = NULL;

    if (node == NULL) {
        new = malloc(sizeof(*new));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else {
        if (value < node->value) {
            node->left = insert(node->left, value);
            return node;
        }
        else if (value > node->value) {
            node->right = insert(node->right, value);
            return node;
        }
        else {
            printf("Value \"%d\" already exist.\n", value);
            return node;
        }
    }
}

tree_node_t *dfs(tree_node_t *node, int value)
{
    if (node == NULL)
        return NULL;
    if (value < node->value)
        return dfs(node->left, value);
    else if (value > node->value)
        return dfs(node->right, value);
    else
        return node;
}

tree_node_t *bfs(tree_node_t *node, int value)
{
    list_t *to_visit = NULL;
    tree_node_t *current = NULL;

    if (node != NULL)
        append(&to_visit, node);
    current = node;
    while (to_visit != NULL) {
        current = pop_front(&to_visit);
        if (current->value == value)
            return current;
        if (current->left != NULL)
            append(&to_visit, current->left);
        if (current->right != NULL)
            append(&to_visit, current->right);
    }
    return NULL;
}

/*Test main*/
int main()
{
    tree_node_t *t = NULL;
    tree_node_t *res = NULL;

    t = insert(t, 10);
    t = insert(t, 4);
    t = insert(t, 9);
    t = insert(t, 3);
    t = insert(t, 1);
    t = insert(t, 2);
    t = insert(t, 7);
    t = insert(t, 5);
    t = insert(t, 6);

//    res = bfs(t, 7);
    res = dfs(t, 7);

    printf("%d\n", res->value);
    printf("%d\n", res->left->right->value);

    return 0;
}

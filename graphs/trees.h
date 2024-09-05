#ifndef _TREES_H_
#define _TREES_H_

typedef struct tn {
    struct tn * left_child;             // pointer to the left child
    struct tn * right_sibling;          // pointer to the right sibling
    struct tn * parent;                 // pointer to the parent
    int info;                           // information stored in the node
} tree_node;


typedef tree_node * tree;

tree_node * add_node(tree_node ** node_pointer, int info);
void print_tree(tree_node * node);
void stampa_outline_ricorri_a(tree_node * node, int prof);
void stampa_outline_a(tree_node* node);
void stampa_albero_sperimentale(tree_node* node);
int tree_height_ste(tree_node * node);

#endif
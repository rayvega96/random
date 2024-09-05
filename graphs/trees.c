#include <stdlib.h>
#include <stdio.h>
#include "trees.h"

// Add a node to a tree
tree_node * add_node(tree_node ** node_pointer, int info) {

    tree_node * new_node = (tree_node*) malloc(sizeof(tree_node));

    new_node->info = info;
    new_node->left_child = NULL;
    new_node->parent = (* node_pointer);

    if( (* node_pointer) == NULL ) {
        new_node->right_sibling = NULL;
        (* node_pointer) = new_node;
    } else {
        // imposta come fratello destro il figlio sinistro del nodo padre
        new_node->right_sibling = (* node_pointer)->left_child;
        // prende il posto del figlio sinistro, bastardo
        (* node_pointer)->left_child = new_node;
    }
    return new_node;
}

int calc_siblings(tree_node * node) {
    if (node == NULL) return 0;
    return 1 + calc_siblings(node->right_sibling);
}


int tree_height_ste(tree_node * node) {
    if (node == NULL) return -1;
    tree_node * temp = node->left_child;
    int max_height = -1;
    while (temp != NULL) {
        int temp_height = tree_height_ste(temp);
        if (temp_height > max_height) {
            max_height = temp_height;
        }
        temp = temp->right_sibling;
    }
    return max_height+1;
}

// Print a tree
void print_tree(tree_node * node) {
    if (node == NULL) return;
    printf("Node: %d\n", node->info);
    print_tree(node->right_sibling);
    print_tree(node->left_child);
    
}

// Print a tree in a less readable way
void stampa_outline_ricorri_a(tree_node * node, int prof) {
    if( node == NULL ) return;
    int i;
    for(i = 0; i < prof; i++){
        printf("  ");
    }
    printf("%d\n",node->info);
    tree_node * node_temp = node->left_child;
    while( node_temp != NULL ) {
       stampa_outline_ricorri_a(node_temp, prof+1);
       node_temp = node_temp->right_sibling;
    }
}

void stampa_outline_a(tree_node* node) {
    stampa_outline_ricorri_a(node, 0);
}

void print_space(int space) {
    for(int i = 0; i < space; i++) {
        printf(" ");
    }
}


  
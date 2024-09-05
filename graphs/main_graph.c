#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"
#include "trees.h"

int main() {

    graph * graph_test_1 = create_graph();

    // prima componente connessa
    node * node_1 = create_node(graph_test_1, 1);
    node * node_2 = create_node(graph_test_1, 2);
    node * node_3 = create_node(graph_test_1, 3);
    node * node_4 = create_node(graph_test_1, 4);
    node * node_5 = create_node(graph_test_1, 5);
 

    // seconda componente connessa
    node * node_6 = create_node(graph_test_1, 6);  
    node * node_7 = create_node(graph_test_1, 7);
    node * node_8 = create_node(graph_test_1, 8);
    node * node_9 = create_node(graph_test_1, 9);
    node * node_10 = create_node(graph_test_1, 10);
    node * node_11 = create_node(graph_test_1, 11);

    // nodo isolato
    node * node_12 = create_node(graph_test_1, 12);

    // nodo isolato
    node * node_13 = create_node(graph_test_1, 13); 

    // prima componente connessa
    arch * arch_1 = create_arch(node_1, node_2, graph_test_1);
    arch * arch_2 = create_arch(node_2, node_3, graph_test_1);
    arch * arch_3 = create_arch(node_3, node_4, graph_test_1);
    arch * arch_4 = create_arch(node_4, node_5, graph_test_1);

    // seconda componente connessa
    arch * arch_5 = create_arch(node_6, node_7, graph_test_1);
    arch * arch_6 = create_arch(node_7, node_8, graph_test_1);
    arch * arch_7 = create_arch(node_7, node_9, graph_test_1);
    arch * arch_8 = create_arch(node_8, node_10, graph_test_1);
    arch * arch_9 = create_arch(node_9, node_10, graph_test_1);
    arch * arch_10 = create_arch(node_10, node_11, graph_test_1);


    // print_graph_o(graph_test_1);
    
    tree tree_test_1 = NULL;
    tree_node * root = add_node(&tree_test_1, 1);
    // altezza 1
    tree_node * node_1_4 = add_node(&root, 4);
    tree_node * node_1_3 = add_node(&root, 3);
    tree_node * node_1_2 = add_node(&root, 2);
    // altezza 2
    tree_node * node_2_6 = add_node(&(root->left_child), 6);
    tree_node * node_2_5 = add_node(&(root->left_child), 5);
    tree_node * node_2_8 = add_node(&(root->left_child->right_sibling->right_sibling), 8);
    tree_node * node_2_7 = add_node(&(root->left_child->right_sibling->right_sibling), 7);
    // altezza 3
    tree_node * node_3_14 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 14);
    tree_node * node_3_13 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 13);
    tree_node * node_3_12 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 12);
    tree_node * node_3_11 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 11);
    tree_node * node_3_10 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 10);
    tree_node * node_3_9 = add_node(&(root->left_child->right_sibling->right_sibling->left_child), 9);


    stampa_albero_sperimentale(tree_test_1);
 

    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphs.h"
#include "trees.h"

// Function to create a new graph
graph * create_graph() {
    graph * g = (graph *) malloc(sizeof(graph));
    g->nodes = NULL;
    g->arches = NULL;
    g->nodes_number = 0;
    g->arches_number = 0;
    return g;
}

// Function to create node and add it to a graph
node * create_node(graph * g, int value_to_recognize) {
    node * new_node = (node *) malloc(sizeof(node));
    new_node->color = 0;
    new_node->node_arch_pointer = NULL;
    // remove if not needed
    new_node->value_to_recognize = value_to_recognize;

    list_node_elem * lne = (list_node_elem *) malloc(sizeof(list_node_elem));
    lne->prev = NULL;        // inserimento in testa: il nodo precedente e' NULL
    lne->next = g->nodes;    // inserimento in testa: il nodo successivo e' il primo nodo della lista
    if (g->nodes != NULL) {
        g->nodes->prev = lne;
    }
    lne->node_pointer = new_node;        // aggiungiamo il puntatore al nodo, alla lista dei nodi generica
    new_node->position = lne;    // il nodo ha un puntatore alla sua posizione nella lista di nodi
    g->nodes = lne;              // aggiorniamo il puntatore alla lista di nodi del grafo
    
    g->nodes_number++;               // incrementiamo il numero di nodi del grafo

    return new_node;
}

// Function to create an arch and add it to a graph
arch * create_arch(node * from, node * to, graph * g) {
    
    arch * new_arch = (arch *) malloc(sizeof(arch));
    new_arch->from = from;
    new_arch->to = to;
                                            // pointer della lista dove lo si vuole aggiungere
    new_arch->position      = add_arch_to_list(&(g->arches)                , new_arch);
    new_arch->from_position = add_arch_to_list(&(from->node_arch_pointer)  , new_arch);
    new_arch->to_position   = add_arch_to_list(&(to->node_arch_pointer)    , new_arch);

    g->arches_number++;
    
    return new_arch;
}

list_arch_elem * add_arch_to_list(list_arch_elem ** pointer_list_arch, arch * a) {

    list_arch_elem * new_la_elem = ( list_arch_elem * ) malloc(sizeof(list_arch_elem));
    new_la_elem->prev = NULL; // lo metto all'inizio della lista
    new_la_elem->next = (*pointer_list_arch);  // il primo blocchetto che era già in lista
    // se c'e' gia' un elemento in lista, sistemo il suo prev
    if (( * pointer_list_arch )!=NULL) ( * pointer_list_arch )->prev = new_la_elem;

    ( * pointer_list_arch ) = new_la_elem;
    new_la_elem->arch_pointer = a;

    return new_la_elem;
}

void print_graph_o(graph * g) {

    printf("Total nodes: %d\n", g->nodes_number);
    printf("Node list: \n");

    list_node_elem* lne = g->nodes;
    while( lne != NULL ) {
        printf("[Node: %-5d - Address: %p] \n",lne->node_pointer->value_to_recognize, lne->node_pointer);
        lne = lne->next;
    }

    
    printf("\nTotal arches: %d\n", g->arches_number);
    printf("Arches list: \n");

    list_arch_elem* lae = g->arches;
    while( lae != NULL ) {
        printf("[Arch Address: %p]  =====  [From Node %-5d : %p] --->  [To Node %-5d : %p]\n",lae->arch_pointer, lae->arch_pointer->from->value_to_recognize, lae->arch_pointer->from, lae->arch_pointer->to->value_to_recognize, lae->arch_pointer->to);
        lae = lae->next;
    }
}
#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct n node;
typedef struct a arch;

// in totale avremo:
// 1) una lista di nodi
// 2) una lista di archi
// 3) Ogni nodo ha un attributo 'position' che e' un puntatore alla sua posizione nella lista di nodi
// 4) Ogni nodo ha un attributo 'arch' che e' un puntatore alla lista dei suoi archi
// 4) Ogni arco ha un attributo 'position' che e' un puntatore alla sua posizione nella lista di archi

// [ <- , node, -> ]

typedef struct nl {
    struct nl * next;    // pointer to the next node in the list
    struct nl * prev;    // pointer to the previous node in the list
    node      * node_pointer;    // pointer to the node
} list_node_elem;

typedef struct al {
    struct al * next;    // pointer to the next arch in the list
    struct al * prev;    // pointer to the previous arch in the list
    arch      * arch_pointer;         // pointer to the arch
} list_arch_elem;

typedef struct n {
	list_node_elem * position;               // pointer to the position in the list of nodes
    list_arch_elem * node_arch_pointer;     // pointer to the list of arches departing from this node
    int color;
    int value_to_recognize;
} node;

typedef struct a {
    node * from;                        // pointer to the node from which the arch starts
    node * to;                          // pointer to the node to which the arch arrives
    list_arch_elem * from_position;          // pointer to the position in the list of arches of the 'from' archlist
    list_arch_elem * to_position;            // pointer to the position in the list of arches of the arch 'to' archlist
    list_arch_elem * position;              // pointer to the position in the list of arches of the general 'graph' 

} arch;

typedef struct g {
    list_node_elem * nodes;                  // pointer to the list of nodes
    list_arch_elem * arches;                 // pointer to the list of arches
    int nodes_number;                        // number of nodes
    int arches_number;                       // number of arches
} graph;



graph * create_graph();
node * create_node(graph * g, int value_to_recognize);
arch * create_arch(node * from, node * to, graph * g);
list_arch_elem * add_arch_to_list(list_arch_elem ** pointer_list_arch, arch * a);
void print_graph_o(graph * g);

#endif
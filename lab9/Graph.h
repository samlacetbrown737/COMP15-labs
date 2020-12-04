/*
 * Graph.h
 * Project 2: Six Degrees of Collaboration
 * Graph class updated by rgilk01 and jdavid07 11/13/20
 */

#include <iostream>
#include <ostream>
#include <queue>
#include "Artist.h"

#ifndef GRAPH_H
#define GRAPH_H

const std::string NULL_EDGE = "-1";
const int NULL_PRED = -1;

// wrapper functions
int index_is(Artist *vertices, Artist v);

class Graph
{
public:
    Graph();
    Graph(int);
    ~Graph();
    Graph(const Graph &);
    Graph & operator = (const Graph &);

    // Mutator functions

    // Function initialize_graph
    // Parameters: int
    // Returns: void
    // Does: allocates space needed for graph according
    //       to inputed size int   
    void initialize_graph(int);
    // Function add_vertex
    // Parameters: Vertex, by value
    // Returns: void
    // Does: Add a new vertex to the end of the 2d array
    //       Initializes every from/to edge to be NULL
    void add_vertex(Artist);
    // Function add_edge
    // Parameters: Two vertices (from and to), weight of the edge
    // Returns: void
    // Does: updates edges array to have the given weight
    void add_edge(Artist, Artist, std::string);

    // Accessor functions

    // Function print_matrix
    // Parameters: ostream
    // Returns: void
    void        print_matrix(std::ostream &) const;
    // Function get_edge
    // Parameters: Two vertices (from and to)
    // Returns: string, the name of the edge (sort of a weight)
    std::string get_edge(Artist, Artist)     const;

    // Helpers for BFS, DFS

    // Function get_to_vertices
    // Parameters: Vertex, queue of vertices by reference
    // Returns: void
    // Does: Finds all neighbors of the given vertex and enqueues
    void get_to_vertices(Artist, std::queue<Artist> &)        const;
    // Function clear_marks
    // Parameters: none
    // Returns: none
    // Does: For algorithms that need to mark vertices (BFS, DFS)
    //       sets all the marks to be false
    void clear_marks();
    // Function mark_vertex
    // Parameters: Vertex
    // Returns: none
    // Does: Sets the mark of this vertex to true
    void mark_vertex(Artist);
    // Function is_marked
    // Parameters: Vertex
    // Returns: bool
    // Does: returns value in marks array for this vertex
    bool is_marked(Artist)                                    const;
    // Function is_vertex
    // Parameters: Vertex
    // Returns: bool
    // Does: returns true if vertex exists in the graph,
    //       false otherwise.
    bool is_vertex(Artist)                                    const;
    // Function initialize_path
    // Parameters: none
    // Returns: none
    // Does: Sets every value in the predecessor path to be the NULL edge
    void initialize_path();
    // Function update_predecessor
    // Parameters: Two vertices, the predecessor and the current
    // Returns: None
    // Does: Finds the location in the vertices array for predecessor
    //       and current. Updates the path array to reflect pred relationship.
    void update_predecessor(Artist, Artist);
    // Function report_path
    // Parameters: Ostream to print, start and end vertices
    // Returns: nonde
    // Does: Finds path from start to end on the predecessor path and prints
    void report_path(std::ostream &, Artist, Artist)          const;

    // Getter functions

    // Function get_vertex
    // Parameters: int, a position
    // Returns: vertex at that given position
    Artist      get_vertex(int)     const;

private:
    int           curr_vertex;
    int           num_vertices;
    Artist       *vertices;
    std::string **edges;
    int          *path;
    bool         *marks;
};

#endif
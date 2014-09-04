/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * Functionality: Search the shortest path from one vertex to others in the undigraph
 */

#ifndef IMPERIALMESSAGERS_GRAPH_H
#define IMPERIALMESSAGERS_GRAPH_H

#include "config.h"

typedef struct _citygraph {
    int    count;
    TIME*   matrix;
} citygraph;

// <summary> Search the shortest path from an specfic vertex of matrix to others </summary>
// <param name="graph">The param is a citygraph struct, which contain matrix and matrix sizes</param>
// <param name="paths">The param is array and will be filled with shortest path</param>
// <param name="departure">The param is the start vertex</param>
// <returns> return an array which contained the distances from departure vertex to others </returns>
// <remarks> </remarks>
extern TIME* dijkstra(citygraph graph, int** tree, int departure);

// <summary> Free the memory of citygraph struct </summary>
// <param name="cities">The param is the citygraph to be freed</param>
extern void free_citygraph(citygraph cities);

// <summary> print the searched paths from start_vertex to other vertexes </summary>
// <param name="tree">The param is a array which store the search tree data structure </param>
// <param name="size">The param is the array length for the above param</param>
// <param name="departure">The param is tree root id and also is the id of start vertex to search</param>
extern void print_tree(int* const tree, const int size, int departure);

#endif

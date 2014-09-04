/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * Functionality: Search the shortest path from vertex1 to vertex2 in the undigraph
 */

#include "graph.h"
#include <math.h>
#include <stdio.h>

TIME get_item_value(TIME* const matrix, int size, int i, int j)
{
    TIME temp;
    assert(matrix);
    assert(size > 0);
    if (i == j)
        return 0;
    temp = matrix[i * size + j];
    return temp > 0 ? temp : 0; // negative value doesn't make sense
}

void free_citygraph(citygraph cities)
{
    free(cities.matrix);
    cities.matrix = NULL;
}

TIME* dijkstra(citygraph graph, int** tree, int departure)
{
    int i, j, cv;
    TIME min_dist, tmp;
    int* prev_vertex;
    const int vertex_num = graph.count;
    int* flags = (int*)malloc(sizeof(int)* vertex_num); //mark the vertex is reached or not: 1 mean reached | 0 mean not reached
    TIME* dist = (TIME*)malloc(sizeof(TIME)* vertex_num); // record the distance between departure vertex to others
    prev_vertex = *tree = (int*)malloc(sizeof(int) * vertex_num); //this array store their previous vertex in tree

    //initialize the distance array, flag array, and path tree array
    for (i = 0 ; i< vertex_num; i++)
    {
        flags[i] = 0; 
        dist[i] = get_item_value(graph.matrix, graph.count, departure, i);
        prev_vertex[i] = departure;
    }
    flags[departure] = 1;
    cv = departure;

    for (i = 1; i < vertex_num; i++)
    {
        min_dist = INFINITY;
        for (j = 0 ; j < vertex_num; j++)
        {
            if ((0 == flags[j]) && (min_dist > dist[j]))
            {
                min_dist = dist[j];
                cv = j;
            }
        }
        flags[cv] = 1;
        for (j = 0 ; j < vertex_num; j++)
        {
            if (0 == flags[j])
            {
                tmp = get_item_value(graph.matrix, graph.count, cv, j);
                if ((tmp != INFINITY) 
                    && ((dist[cv] + tmp) > tmp) //prevent out of range
                    && (dist[j] > (dist[cv] + tmp))) 
                {
                    dist[j] = dist[cv] + tmp;
                    prev_vertex[j] = cv;
                }
            }
        }
    }

    free(flags);
    flags = NULL;
    return dist;
}

void print_path(int* const tree, int departure, int dest)
{
    assert(tree);
    assert(departure >=0 );
    assert(dest >= 0);
    if (tree[dest] != departure)
    {
        print_path(tree, departure, tree[dest]);
    }
    printf(" -> %d ", dest);
}

void print_tree(int* const tree, const int size, int departure)
{
    int i;
    assert(tree);
    assert(size > 0);
    assert(departure >=0);

    for (i = 0; i < size; i++)
    {
        printf("=>Path for %d to %d : %d", departure, i, departure);
        print_path(tree, departure, i);
        printf("\n");
    }
}



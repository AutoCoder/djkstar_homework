/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * 
 */

#include "graph.h"
#include "consume.h"
#include <stdlib.h>
#include <stdio.h>

TIME get_max_item(TIME* list, int size)
{
    int i;
    TIME tmp;
    assert(list && size > 0);
    tmp = list[0];
    for (i = 1; i < size; i++)
    {
        if (tmp < list[i])
            tmp = list[i];
    }
    return tmp;
}

int main() 
{
    //consume input data
    int departure = -1;
    int* tree = NULL;
    TIME* dist = NULL;
    citygraph _citys;

    if (consume_console_input(&_citys.matrix, &_citys.count))
    {
        printf("=>Input matrix as follows: \n");
        print_matrix(_citys.matrix, _citys.count);
        printf("=>Input departure city id : ");
        while(true)
        {
            scanf("%d", &departure);
            if(departure < 0 || departure >= _citys.count)
                printf("=>Departure city id should be in the range (0, %d), input again: ", _citys.count - 1);
            else
                break;
        } 
        assert(departure > -1 && departure < _citys.count);
        dist = dijkstra(_citys, &tree, departure);
        printf("=>The minimal time for a message to spread out from captiol to whole empire is %u ...\n", get_max_item(dist, _citys.count));

        print_tree(tree, _citys.count, departure);

        free(tree); tree = NULL;
        free(dist); dist = NULL;
        free_citygraph(_citys);
    }

    system("pause");
    return 0;
}






/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * Functionality: Consume the console input, return the undigraph(matrix)
 */

#include "consume.h"
#include <stdio.h>
#include <string.h>

void print_matrix(TIME* const matrix, const int size)
{
    int i, j;
    assert(matrix);
    assert(size > 0);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("    %u    ", matrix[i * size + j]);
        }
        printf("\r\n");
    }
    printf("\r\n");
}

//This function is used to initialize the undigraph matrix
void init_undigraph(TIME* city_matrix, int matrix_size)
{
    int i, array_size;
    assert(city_matrix);
    if (!city_matrix)
        return;
    array_size = matrix_size * matrix_size;
    for (i = 0; i< array_size; i++)
    {
        if (i % (matrix_size + 1) == 0)//check the item is on the diagonal or not
            city_matrix[i] = 0;
        else
            city_matrix[i] = INFINITY;
    }
}

/*This function is used to convert int to string. 
If the param equal with 'x', it will return INFINITY, 
If the string contain non-numeric chars, it will return 0 */
unsigned int str2uint(char* str_input)
{
    unsigned int temp;
    if (0 == strcmp(str_input, "x"))
        return INFINITY;

    temp = (unsigned int)atoi(str_input);
    return temp >= 0 ? temp : 0;
}

//This function not used, but if we want to support double input, we can use it instead of str2uint
double str2double(char* str_input) 
{
    double temp;
    if (0 == strcmp(str_input, "x"))
        return INFINITY;

    temp = atof(str_input);
    return temp >= 0 ? temp : 0;
}

bool consume_undigraph(TIME* undigraph_matrix, int size, TIME (*func)(char* str_input))
{
    int i, j;
    char* str_input;
    assert(undigraph_matrix);
    if(!undigraph_matrix)
        return false;

    //initialize the matrix data
    init_undigraph(undigraph_matrix, size);

    str_input = (char*)malloc(sizeof(char)* 100);
    printf("=>Please input matrix, all elements in one row should be separated by ' '\n\n");
    for (i = 1; i < size; i++)
    {
        printf("=>For matrix row %d  :  ", i);
        j = 0; 
        while (j < i)
        {
            scanf("%s", str_input);
            undigraph_matrix[j * size + i] = undigraph_matrix[i * size + j] = func(str_input);
            j++;
        }
    }

    free(str_input);
    str_input = NULL;
    return true;
}

bool consume_console_input(TIME** city_matrix, int* city_num)
{
    int matrix_size;

    //input city_num 
    printf("=>Please input number of cities...\n");
    assert(city_num);
    scanf("%d",city_num);

    //validate the city_num input
    matrix_size = *city_num;
    assert(matrix_size > 1);
    if (matrix_size < 2)
    {
        printf("=>invalid number of cities...exit()\n");
        return false;
    }

    *city_matrix = (TIME*)malloc(sizeof(TIME) * matrix_size * matrix_size);

    //input city_matrix
    return consume_undigraph(*city_matrix, matrix_size, str2uint);
}

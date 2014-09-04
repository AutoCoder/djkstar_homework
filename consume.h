/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * Functionality: Consume the console input, return the undigraph(matrix)
 */

#ifndef IMPERIALMESSAGERS_CONSUME_H
#define IMPERIALMESSAGERS_CONSUME_H

#include "config.h"

// <summary> Consume and verify the data input </summary>
// <param name="city_matrix">The param is a matrix pointer, which will be filled by user input</param>
// <param name="city_num">The param is the matrix size</param>
// <returns> If this function consume console input successfully, it return true. Otherwise it will return false </returns>
// <remarks> </remarks>
extern bool consume_console_input(TIME** city_matrix, int* city_num);

// <summary> Print the matrix </summary>
// <param name="matrix">The param is the matrix to be printed</param>
// <param name="size">The param is the matrix size</param>
// <returns></returns>
// <remarks></remarks>
extern void print_matrix(TIME* const matrix, const int size);

#endif

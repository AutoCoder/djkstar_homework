/*
 * Project: ImperialMessagers
 * Author: Yuanbo Li
 * Date: 2013.06.09
 * Functionality: define macro and include some common-used the header files.
 */

#ifndef IMPERIALMESSAGERS_CONFIG_H
#define IMPERIALMESSAGERS_CONFIG_H

#define bool int
#define true 1
#define false 0

typedef unsigned int TIME;

#include <assert.h>
#include <stdlib.h>
#include <limits.h>

//If type of TIME changed, this MACRO need to adapt.
#define INFINITY UINT_MAX 

#endif

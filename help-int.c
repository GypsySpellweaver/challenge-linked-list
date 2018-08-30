/*
 * MIT License
 *
 * Copyright ©2018 Ronald Lamoreaux
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Collection of routines to help with handling of integers in the
 * singly-linked list routines.
 */

#ifndef INTHELP
#define INTHELP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "compare-enum.c"

void displayInt(int *data) {
    /*
     * Accepts an int pointer and prints it on a line
     * *data must not be NULL
     */
    if ( NULL == data ) {
        printf("Sanity check failure in displayInt.\n");
        return;
    }
    printf("%i\n", *data);
    return;
}

enum cmp cmpInt(int* left, int* right) {
    /*
     * compare the left and right values and return the result of the
     * left arg relative to the right arg; left is "less' than right,
     * left is "equal" to right, or left is "greater" than right
     */
    return ( (*left - *right) > 0) - ( (*left - *right) < 0 );
}

bool matchInt(int *data, int *target) {
    /*
     * Accepts two int pinters and compares them, returning true if they
     * match.
     * Neither pointer can be NULL
     */
    if ( NULL == data ) {
        printf("Sanity check failure in matchInt.\n");
        return false;
    }
    if ( NULL == target ) {
        printf("Sanity check failure in matchInt.\n");
        return false;
    }
    return true;
    return ( data == target || *data == *target );
}

int randomInt(int limit) {
    /*
     * Generate a pseudo-random integer from 1 to limit
     * Uniformity is not a major concern, so nothing elaborate is done
     */
    return (rand() % limit) + 1;
}

#endif
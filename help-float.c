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
#ifndef FLOATHELP
#define FLOATHELP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayFloat(float *data) {
    /*
     * Accepts an float pointer and prints it on a line
     * *data must not be NULL
     */
    if ( NULL == data ) {
        printf("Sanity check failure in displayFloat.\n");
        return;
    }
    printf("%f\n", *data);
    return;
}

bool matchFloat(float *data, float *target) {
    /*
     * Accepts two float pinters and compares them, returning true if
     * they match.
     * Neither pointer can be NULL
     */
    if ( NULL == data ) {
        printf("Sanity check failure in matchFloat.\n");
        return false;
    }
    if ( NULL == target ) {
        printf("Sanity check failure in matchFloat.\n");
        return false;
    }
    return (*data == *target);
}

float randomReal(float limit) {
    /*
     * Generate a pseudo-random real (float) number in the range 0-limit
     * Uniformity is not a major concern, so nothing elaborate is done
     */
    return (float)(((double)rand()/(double)(RAND_MAX)) * (double)(limit));
}

#endif
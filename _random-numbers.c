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

#include <stdio.h>

#include "help-int.c"
#include "help-float.c"
#include "single-link-list.c"
#include "single-link-list-sort.c"

/*
 * Fill the list with random numbers, dynamically stored, and then sort
 * it. Make a list of integers, and a list of floats
 */
void workOutWithRandomNumbers(int list_size) {
    LLNode* int_head_ptr = newListNode(NULL);
    LLNode* float_head_ptr = newListNode(NULL);
    int *i_var;
    float *f_var;
    int lcv;
    for (lcv = 0; lcv < list_size; lcv++) {
        i_var = (int*)malloc(sizeof(int));
        f_var = (float*)malloc(sizeof(float));
        *i_var = randomInt(360);
        *f_var = randomReal(360.0);
        appendNode(int_head_ptr, i_var);
        appendNode(float_head_ptr, f_var);
    }
    printf("\tUnsorted integers\n----------------\n");
    walkList(int_head_ptr, displayInt);
    printf("\t  Sorted integers\n++++++++++++++++\n");
    mergeSort(int_head_ptr, cmpInt);
    walkList(int_head_ptr, displayInt);
    printf("=====================================\n\n");
    printf("\tUnsorted floats\n------------------\n");
    walkList(float_head_ptr, displayFloat);
    printf("\t  Sorted floats\n++++++++++++++++++\n");
    mergeSort(float_head_ptr, cmpFloat);
    walkList(float_head_ptr, displayFloat);
    printf("=====================================\n\n");
    clearList(int_head_ptr, free);
    clearList(float_head_ptr, free);
    free(int_head_ptr);
    free(float_head_ptr);
}


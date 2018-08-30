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

void workOutWithRandomNumbersRemotely(int list_size, LLNode* head_ptr) {
    float* n_var;
    int lcv;
    for (lcv = 0; lcv < list_size; lcv++) {
        n_var = (float*)malloc(sizeof(float));
        *n_var = randomReal(360.0);
        appendNode(head_ptr, n_var);
    }
}
void workOutWithRandomNumbersRemotelyFinal(LLNode* head_ptr) {
    printf("\tUnsorted numbers\n-----------------\n");
    walkList(head_ptr, displayFloat);
    printf("\t  Sorted numbers\n+++++++++++++++++\n");
    mergeSort(head_ptr, cmpFloat);
    walkList(head_ptr, displayFloat);
    printf("=====================================\n\n");
    clearList(head_ptr, free);
    return;
}


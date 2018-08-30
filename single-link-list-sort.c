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

#ifndef SINGLELINKSORT
#define SINGLELINKSORT

#include <stdlib.h>
#include <stdbool.h>

#include "help-int.c"
#include "help-float.c"
#include "compare-enum.c"
#include "single-link-list.c"

/*
 * Routines to do a merge sort on a singly-linked list
 *
 * The passed in head_ptr should be the top-most node, first on the list
 * if the sort is to be of any value. It is not a requirement, however,
 * of the routines. They will happily sort the last 10 recodrs of a list
 * with thousands of entries.
 */


void mergeSort(LLNode* head_ptr, enum cmp (*cmp_func)()) {
    /*
     * Main routine for sorting the list.
     * head_ptr is presumed to be the first node in the list
     * cmp_func finds the larger of two arguments, and is used by the
     * sortedMerge routine. (passthrough until then)
     */

    // List of 0 or 1 is already sorted.
    if ( NULL == head_ptr->next || NULL == head_ptr->next->next ) {
        return;
    }
    LLNode* left_ptr = newListNode(NULL);
    LLNode* right_ptr = newListNode(NULL);
    // cut the list in half, or nearly so
    splitLeftRight(head_ptr, left_ptr, right_ptr);
    // recursively sort each half
    mergeSort(left_ptr, cmp_func);
    mergeSort(right_ptr, cmp_func);
    // merge the left and right, already sorted, lists in order
    head_ptr->next = sortedMerge(left_ptr, right_ptr, cmp_func);
    // cleanup
    free(left_ptr);
    free(right_ptr);
}

#endif
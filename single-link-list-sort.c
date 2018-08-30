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


static LLNode* sortedMerge(LLNode* left_ptr, LLNode* right_ptr, enum cmp (*cmp_func)()) {
    // empty left, use the right, even if NULL
    if ( NULL == left_ptr->next ) {
        return right_ptr->next;
    }
    // non-empty left, empty right, left wins
    else if ( NULL == right_ptr->next ) {
        return left_ptr->next;
    }
    //
    LLNode* next_node = NULL;
    if ( greater == (cmp_func)(left_ptr->next->data, right_ptr->next->data) ) {
        // left is larger, use first one on the right
        next_node = right_ptr->next;
        // back again to find the next one
        next_node->next = sortedMerge(left_ptr, right_ptr->next, cmp_func);
    }
    else {
        // left is not larger, use it
        next_node = left_ptr->next;
        // back again to find the next one
        next_node->next = sortedMerge(left_ptr->next, right_ptr, cmp_func);
    }
    // send the final list back up the chain
    return next_node;
}


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
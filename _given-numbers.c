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

/*
 * Series of calls that build a list, and manipulate it, using known
 * numbers and a given sequence.
 * Expected status is given, and real status provided, after each step
 *
 * This is the first series of test to use dynamically allocated memory
 * for the data in the list.
 */

void workOutWithGivenNumbers() {
    LLNode* test_head_prt = newListNode(NULL);
    LLNode* point_ptr = NULL;
    LLNode* point_b_ptr = NULL;
    LLNode* point_a_ptr = NULL;
    float *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *f9, *fx;
    f1 = (float*)malloc(sizeof(float));
    f2 = (float*)malloc(sizeof(float));
    f3 = (float*)malloc(sizeof(float));
    f4 = (float*)malloc(sizeof(float));
    f5 = (float*)malloc(sizeof(float));
    f6 = (float*)malloc(sizeof(float));
    f7 = (float*)malloc(sizeof(float));
    f8 = (float*)malloc(sizeof(float));
    f9 = (float*)malloc(sizeof(float));
    fx = (float*)malloc(sizeof(float));
    *f1 = 64.23;
    *f2 = 59.28;
    *f3 = 43.51;
    *f4 = 55.17;
    *f5 = 1.64;
    *f6 = 2.9;
    *f7 = 15.21;
    *f8 = 45.40;
    *f9 = 57.42;
    insertNodeAfter(test_head_prt, f3);
    printf("Looking for\n\t%6.2f\n--------------\n",*f3);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    appendNode(test_head_prt, f1);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    appendNode(test_head_prt, f2);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    appendNode(test_head_prt, f4);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f4);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    appendNode(test_head_prt, f5);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f4,*f5);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    appendNode(test_head_prt, f8);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f4,*f5,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    *fx = 59.28;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    insertNodeAfter(point_ptr, f9);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f9,*f4,*f5,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    *fx = 1.64;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    insertNodeAfter(point_ptr, f7);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f9,*f4,*f5,*f7,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    insertNodeAfter(point_ptr, f6);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f3,*f1,*f2,*f9,*f4,*f5,*f6,*f7,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    *fx = 57.42;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_ptr, test_head_prt);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f9,*f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    *fx = 43.51;
    point_a_ptr = findNode(test_head_prt, fx, matchFloat);
    *fx = 55.17;
    point_b_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_a_ptr, point_b_ptr);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f9,*f1,*f2,*f4,*f3,*f5,*f6,*f7,*f8);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    *fx = 45.4;
    point_a_ptr = findNode(test_head_prt, fx, matchFloat);
    *fx = 57.42;
    point_b_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_a_ptr, point_b_ptr);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f8,*f1,*f2,*f4,*f3,*f5,*f6,*f7,*f9);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    walkList(test_head_prt, free);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    clearList(test_head_prt, NULL);
    printf("Looking for\n\tnothing\n--------------\n");
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    f1 = (float*)malloc(sizeof(float));
    f2 = (float*)malloc(sizeof(float));
    f3 = (float*)malloc(sizeof(float));
    f4 = (float*)malloc(sizeof(float));
    f5 = (float*)malloc(sizeof(float));
    f6 = (float*)malloc(sizeof(float));
    f7 = (float*)malloc(sizeof(float));
    f8 = (float*)malloc(sizeof(float));
    f9 = (float*)malloc(sizeof(float));
    fx = (float*)malloc(sizeof(float));
    *f1 = 2.9;
    *f2 = 15.21;
    *f3 = 45.40;
    *f4 = 57.42;
    *f5 = 64.23;
    *f6 = 59.28;
    *f7 = 43.51;
    *f8 = 55.17;
    *f9 = 1.64;
    insertNodeAfter(test_head_prt, f3);
    appendNode(test_head_prt, f1);
    appendNode(test_head_prt, f2);
    appendNode(test_head_prt, f4);
    appendNode(test_head_prt, f5);
    appendNode(test_head_prt, f8);
    *fx = 55.17;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    insertNodeAfter(point_ptr, f9);
    *fx = 1.64;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    insertNodeAfter(point_ptr, f7);
    insertNodeAfter(point_ptr, f6);
    *fx = 57.42;
    point_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_ptr, test_head_prt);
    *fx = 43.51;
    point_a_ptr = findNode(test_head_prt, fx, matchFloat);
    *fx = 55.17;
    point_b_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_a_ptr, point_b_ptr);
    *fx = 55.17;
    point_a_ptr = findNode(test_head_prt, fx, matchFloat);
    *fx = 57.42;
    point_b_ptr = findNode(test_head_prt, fx, matchFloat);
    swapNodes(point_a_ptr, point_b_ptr);
    printf("Looking for\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n\t%6.2f\n--------------\n",*f8,*f1,*f2,*f3,*f5,*f7,*f9,*f6,*f4);
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    clearList(test_head_prt, free);
    printf("Looking for\n\tnothing\n--------------\n");
    walkList(test_head_prt, displayFloat);
    printf("**************\n");
    free(test_head_prt);
    return;
}


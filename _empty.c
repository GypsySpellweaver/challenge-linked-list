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
 * collection of calls that exercise the routines using an empty list
 */

void workOutWithEmptyList() {
    LLNode* head_ptr = newListNode(NULL);
    int num1 = 13;
    printf("****************************************** With an empty list:\n");
    printf("============================== prependNode and clearList\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== cleared\n");
    clearList(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== prependNode and deleteNode head\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== deleted\n");
    deleteNode(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== prependNode and removeNode head\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== removed\n");
    removeNode(head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== prependNode and findNode &num1\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("Value of found node is %i\n", *(int*)(findNode(head_ptr, &num1, matchInt)->next->data));
    printf("============================== prependNode and swapNodes\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodes(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodes(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== prependNode and swapNodePointers\n");
    clearList(head_ptr, NULL);
    prependNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodePointers(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodePointers(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("*********************\n\n");

    printf("============================== insertNodeBefore and clearList\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== cleared\n");
    clearList(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeBefore and deleteNode head\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== deleted\n");
    deleteNode(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeBefore and removeNode head\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== removed\n");
    removeNode(head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeBefore and findNode &num1\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("Value of found node is %i\n", *(int*)(findNode(head_ptr, &num1, matchInt)->next->data));
    printf("============================== insertNodeBefore and swapNodes\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodes(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodes(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeBefore and swapNodePointers\n");
    clearList(head_ptr, NULL);
    insertNodeBefore(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodePointers(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodePointers(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("*********************\n\n");

    printf("============================== insertNodeAfter and clearList\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== cleared\n");
    clearList(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeAfter and deleteNode head\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== deleted\n");
    deleteNode(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeAfter and removeNode head\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== removed\n");
    removeNode(head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeAfter and findNode &num1\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("Value of found node is %i\n", *(int*)(findNode(head_ptr, &num1, matchInt)->next->data));
    printf("============================== insertNodeAfter and swapNodes\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodes(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodes(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== insertNodeAfter and swapNodePointers\n");
    clearList(head_ptr, NULL);
    insertNodeAfter(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodePointers(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodePointers(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("*********************\n\n");

    printf("============================== appendNode and clearList\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== cleared\n");
    clearList(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== appendNode and deleteNode head\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== deleted\n");
    deleteNode(head_ptr, NULL);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== appendNode and removeNode head\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("===================== removed\n");
    removeNode(head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== appendNode and findNode &num1\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("Value of found node is %i\n", *(int*)(findNode(head_ptr, &num1, matchInt)->next->data));
    printf("============================== appendNode and swapNodes\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodes(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodes(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodes(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("============================== appendNode and swapNodePointers\n");
    clearList(head_ptr, NULL);
    appendNode(head_ptr, &num1);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with head\n");
    swapNodePointers(head_ptr, head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with &num1\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping head with &num1\n");
    swapNodePointers(head_ptr, findNode(head_ptr, &num1, matchInt));
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("--------------------- swapping &num1 with head\n");
    swapNodePointers(findNode(head_ptr, &num1, matchInt), head_ptr);
    printf("--------------------- walking\n");
    walkList(head_ptr, displayInt);
    printf("*********************\n\n");
    clearList(head_ptr, NULL);
    free(head_ptr);
}


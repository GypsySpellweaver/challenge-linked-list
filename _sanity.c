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
 * Collection of procedure calls which should all trigger sanity check
 * failures.
 */

void sanityChecksFloat() {
    LLNode* head_ptr = newListNode(NULL);
    float num1 = 13.05;
    printf("\tChecking matchFloat(NULL, NULL);\t\t");
    matchFloat(NULL, NULL);
    printf("\tChecking matchFloat(NULL, &num1);\t\t");
    matchFloat(NULL, &num1);
    printf("\tChecking matchFloat(&num1, NULL);\t\t");
    matchFloat(&num1, NULL);
    printf("\tChecking walkList(NULL, NULL);\t\t\t");
    walkList(NULL, NULL);
    printf("\tChecking walkList(NULL, displayFloat);\t\t");
    walkList(NULL, displayFloat);
    printf("\tChecking prependNode(NULL, NULL);\t\t");
    prependNode(NULL, NULL);
    printf("\tChecking prependNode(NULL, &num1);\t\t");
    prependNode(NULL, &num1);
    printf("\tChecking appendNode(NULL, &num1);\t\t");
    appendNode(NULL, &num1);
    printf("\tChecking insertNodeAfter(NULL, &num1);\t\t");
    insertNodeAfter(NULL, &num1);
    printf("\tChecking insertNodeBefore(NULL, &num1);\t\t");
    insertNodeBefore(NULL, &num1);
    printf("\tChecking swapNodePointers(NULL, NULL);\t\t");
    swapNodePointers(NULL, NULL);
    printf("\tChecking swapNodePointers(head_ptr, NULL);\t");
    swapNodePointers(head_ptr, NULL);
    printf("\tChecking swapNodePointers(NULL, head_ptr);\t");
    swapNodePointers(NULL, head_ptr);
    printf("\tChecking swapNodePointers(head_ptr, head_ptr);\t");
    swapNodePointers(head_ptr, head_ptr);
    printf("\tChecking swapNodes(NULL, NULL);\t\t\t");
    swapNodes(NULL, NULL);
    printf("\tChecking swapNodes(head_ptr, NULL);\t\t");
    swapNodes(head_ptr, NULL);
    printf("\tChecking swapNodes(NULL, head_ptr);\t\t");
    swapNodes(NULL, head_ptr);
    printf("\tChecking swapNodes(head_ptr, head_ptr);\t\t");
    swapNodes(head_ptr, head_ptr);
    printf("\tChecking clearList(NULL);\t\t\t");
    clearList(NULL, NULL);
    printf("\tChecking countNodes(NULL);\t\t\t");
    countNodes(NULL);
    printf("\tChecking deleteNode(NULL);\t\t\t");
    deleteNode(NULL, NULL);
    printf("\tChecking deleteNode(head_ptr);\t\t\t");
    deleteNode(head_ptr, NULL);
    printf("\tChecking removeNode(NULL);\t\t\t");
    removeNode(NULL);
    printf("\tChecking removeNode(head_ptr);\t\t\t");
    removeNode(head_ptr);
    printf("\tChecking findNode(NULL, NULL, NULL);\t\t");
    findNode(NULL, NULL, NULL);
    printf("\tChecking findNode(NULL, NULL, matchFloat);\t");
    findNode(NULL, NULL, matchFloat);
    printf("\tChecking findNode(NULL, &num1, NULL);\t\t");
    findNode(NULL, &num1, NULL);
    printf("\tChecking findNode(NULL, &num1, matchFloat);\t");
    findNode(NULL, &num1, matchFloat);
    printf("\tChecking findNode(head_ptr, NULL, NULL);\t");
    findNode(head_ptr, NULL, NULL);
    printf("\tChecking findNode(head_ptr, &num1, NULL);\t");
    findNode(head_ptr, &num1, NULL);
}

void sanityChecksInt() {
    LLNode* head_ptr = newListNode(NULL);
    int num1 = 13;
    printf("\tChecking matchInt(NULL, NULL);\t\t\t");
    matchInt(NULL, NULL);
    printf("\tChecking matchInt(NULL, &num1);\t\t\t");
    matchInt(NULL, &num1);
    printf("\tChecking matchInt(&num1, NULL);\t\t\t");
    matchInt(&num1, NULL);
    printf("\tChecking walkList(NULL, NULL);\t\t\t");
    walkList(NULL, NULL);
    printf("\tChecking walkList(NULL, displayInt);\t\t");
    walkList(NULL, displayInt);
    printf("\tChecking prependNode(NULL, NULL);\t\t");
    prependNode(NULL, NULL);
    printf("\tChecking prependNode(NULL, &num1);\t\t");
    prependNode(NULL, &num1);
    printf("\tChecking appendNode(NULL, &num1);\t\t");
    appendNode(NULL, &num1);
    printf("\tChecking insertNodeAfter(NULL, &num1);\t\t");
    insertNodeAfter(NULL, &num1);
    printf("\tChecking insertNodeBefore(NULL, &num1);\t\t");
    insertNodeBefore(NULL, &num1);
    printf("\tChecking swapNodePointers(NULL, NULL);\t\t");
    swapNodePointers(NULL, NULL);
    printf("\tChecking swapNodePointers(head_ptr, NULL);\t");
    swapNodePointers(head_ptr, NULL);
    printf("\tChecking swapNodePointers(NULL, head_ptr);\t");
    swapNodePointers(NULL, head_ptr);
    printf("\tChecking swapNodePointers(head_ptr, head_ptr);\t");
    swapNodePointers(head_ptr, head_ptr);
    printf("\tChecking swapNodes(NULL, NULL);\t\t\t");
    swapNodes(NULL, NULL);
    printf("\tChecking swapNodes(head_ptr, NULL);\t\t");
    swapNodes(head_ptr, NULL);
    printf("\tChecking swapNodes(NULL, head_ptr);\t\t");
    swapNodes(NULL, head_ptr);
    printf("\tChecking swapNodes(head_ptr, head_ptr);\t\t");
    swapNodes(head_ptr, head_ptr);
    printf("\tChecking clearList(NULL);\t\t\t");
    clearList(NULL, NULL);
    printf("\tChecking countNodes(NULL);\t\t\t");
    countNodes(NULL);
    printf("\tChecking deleteNode(NULL);\t\t\t");
    deleteNode(NULL, NULL);
    printf("\tChecking deleteNode(head_ptr);\t\t\t");
    deleteNode(head_ptr, NULL);
    printf("\tChecking removeNode(NULL);\t\t\t");
    removeNode(NULL);
    printf("\tChecking removeNode(head_ptr);\t\t\t");
    removeNode(head_ptr);
    printf("\tChecking findNode(NULL, NULL, NULL);\t\t");
    findNode(NULL, NULL, NULL);
    printf("\tChecking findNode(NULL, NULL, matchInt);\t");
    findNode(NULL, NULL, matchInt);
    printf("\tChecking findNode(NULL, &num1, NULL);\t\t");
    findNode(NULL, &num1, NULL);
    printf("\tChecking findNode(NULL, &num1, matchInt);\t");
    findNode(NULL, &num1, matchInt);
    printf("\tChecking findNode(head_ptr, NULL, NULL);\t");
    findNode(head_ptr, NULL, NULL);
    printf("\tChecking findNode(head_ptr, &num1, NULL);\t");
    findNode(head_ptr, &num1, NULL);
}

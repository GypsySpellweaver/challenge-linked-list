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
#include <stdlib.h>

/* Pointers to the list, head_ptr, curr_ptr, etc., should always point
 * to the node that points to the target. head_ptr points to the node
 * without data which points to the first item on the list.
 * Hence, head_ptr->next = *first_node.
 * If at some point the third item in the list is to be the target of a
 * pointer, curr_ptr,
 * then curr_ptr->next = *third_node
 * and  curr_ptr       = *second_node
 * Even though it might not seem correct, if there is a tail_ptr
 * then tail_ptr->next = *last_node
 * and  tail_ptr       = *second_last_node
 */

struct ListNode {
    void *data;             // pointer to what this node should hold
    struct ListNode *next;  // pointer to the next node in the list
    /*
     *  +------+------+
     *  | data |   ------>
     *  +------+------+
     *
     */
};

void displayInt(int *data) {
    printf("%i\n", *data);
    return;
}

void displayFloat(float *data) {
    printf("%f\n", *data);
    return;
}

void walkList(struct ListNode *head_ptr, void (*display_proc)()) {
    /*
     * head_ptr: the current head_ptr of the list
     * *display_proc: pointer to the procedure to display whatever is
     *    held in the memory pointed to by the data field
     */
    struct ListNode *temp_ptr = head_ptr;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+
     *  | NULL |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ------> NULL
     *  +------+------+
     */
    while (temp_ptr->next != NULL) {
        (display_proc)(temp_ptr->next->data);
        temp_ptr = temp_ptr->next;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  | NULL |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+
     *  | data |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ------> NULL
     *  +------+------+
     */
    }
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  | NULL |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+
     *  | data |   ------> NULL
     *  +------+------+
     */
}

void addNode(struct ListNode *head_ptr, void *new_data) {
    /*
     * head_ptr: the current head_ptr of the list
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concert
     */
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = new_data;
    new_node->next = NULL;
    /*
     *    new_node ----->+
     *     +-------------+
     *     V
     *  +------+------+
     *  |*data |   ------> NULL
     *  +------+------+
     *
     */
    struct ListNode *temp_ptr = head_ptr;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+            new_node ----->+
     *  | NULL |   ----->+          +-------------+
     *  +------+------+  |          V
     *     +-------------+       +------+------+
     *     V                     |*data |   ------> NULL
     *  +------+------+          +------+------+
     *  | data |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ------> NULL
     *  +------+------+
     */
    while ( temp_ptr->next != NULL ) {
        temp_ptr = temp_ptr->next;
        /*
         *   head_ptr ------>+
         *     +-------------+
         *     V
         *  +------+------+
         *  | NULL |   ----->+
         *  +------+------+  |
         *     +-------------+
         *     |<------------- temp_ptr
         *     V
         *  +------+------+             new_node ----->+
         *  | data |   ----->+           +-------------+
         *  +------+------+  |           V
         *     +-------------+        +------+------+
         *     V                      |*data |   ------> NULL
         *  +------+------+           +------+------+
         *  | data |   ------> NULL
         *  +------+------+
         */
    }
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  | NULL |   ----->+
     *  +------+------+  |       new_node ----->+
     *     +-------------+        +-------------+
     *     V                      V
     *  +------+------+        +------+------+
     *  | data |   ----->+     |*data |   ------> NULL
     *  +------+------+  |     +------+------+
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+
     *  | data |   ------> NULL
     *  +------+------+
     */
    temp_ptr->next = new_node;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  | NULL |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     V
     *  +------+------+
     *  | data |   ----->+
     *  +------+------+  |
     *     +-------------+
     *     |<------------- temp_ptr
     *     V
     *  +------+------+
     *  | data |   ------+
     *  +------+------+  |
     *     +-------------+
     *     |<------------- new_node
     *     V
     *  +------+------+
     *  |*data |   ------> NULL
     *  +------+------+
     */
    return;
}

int main() {
    // create the forever empty head node
    struct ListNode* head_ptr = NULL;
    //  head_ptr -------> ??
    head_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  |  ??  |   ------> ??
     *  +------+------+
     *
     */
    // make it point nowhere, start with an empty list
    head_ptr->next = NULL;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  |  ??  |   ------> NULL
     *  +------+------+
     *
     */
    // make the data explicitly NULL for safety
    head_ptr->data = NULL;
    /*
     *   head_ptr ------>+
     *     +-------------+
     *     V
     *  +------+------+
     *  | NULL |   ------> NULL
     *  +------+------+
     *
     */
    return 0;
}

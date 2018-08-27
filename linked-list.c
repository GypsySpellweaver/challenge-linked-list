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
};

struct ListNode* newListNode(void *new_data) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
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
    while (temp_ptr->next != NULL) {
        (display_proc)(temp_ptr->next->data);
        temp_ptr = temp_ptr->next;
    }
    return;
}

void prependNode(struct ListNode *head_ptr, void *new_data) {
    /*
     * head_ptr: the current head_ptr of the list
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    struct ListNode *new_node = newListNode(new_data);
    new_node->next = head_ptr->next;
    head_ptr->next = new_node;
    return;
}

void appendNode(struct ListNode *head_ptr, void *new_data) {
    /*
     * head_ptr: the current head_ptr of the list
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    struct ListNode* new_node = newListNode(new_data);
    struct ListNode* temp_ptr = head_ptr;
    while ( temp_ptr->next != NULL ) {
        temp_ptr = temp_ptr->next;
    }
    temp_ptr->next = new_node;
    return;
}

void insertNodeAfter(struct ListNode *curr_ptr, void *new_data) {
    /*
     * curr_ptr: the pointer whos next points to the node after which
     *      the new node should be added. (See comment at the top.)
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    struct ListNode* new_node = newListNode(new_data);
    new_node->next = curr_ptr->next->next;
    curr_ptr->next->next = new_node;
    return;
}

void insertNodeBefore(struct ListNode *curr_ptr, void *new_data) {
    /*
     * curr_ptr: the pointer whos next points to the node before which
     *      the new node should be added. (See comment at the top.)
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    struct ListNode* new_node = newListNode(new_data);
    new_node->next = curr_ptr->next;
    curr_ptr->next = new_node;
    return;
}

void swapNodes(struct ListNode *a_ptr, struct ListNode *b_ptr) {
    /*
     * a_ptr and b_ptr point to a pair of nodes, once removed from their
     * address, as all _ptr values are. a_ptr->next will be what was in
     * b_ptr->next, and visa-versa. The nodes following the swap nodes
     * will __not__ switch with the swap, but keep their position in the
     * list relative to the head, not the switched nodes.
     */
    void *temp = a_ptr->next->data;
    a_ptr->next->data = b_ptr->next->data;
    b_ptr->next->data = temp;
    return;
}

int main() {
    // create the forever empty head node
    struct ListNode* head_ptr = newListNode(NULL);
    return 0;
}

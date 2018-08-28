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
#include <stdbool.h>

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
    if ( NULL == data ) {
        printf("Sanity check failure in displayInt.\n");
        return;
    }
    printf("%i\n", *data);
    return;
}

bool matchInt(int *data, int *target) {
    if ( NULL == data ) {
        printf("Sanity check failure in matchInt.\n");
        return false;
    }
    return (*data == *target);
}

void displayFloat(float *data) {
    if ( NULL == data ) {
        printf("Sanity check failure in displayFloat.\n");
        return;
    }
    printf("%f\n", *data);
    return;
}

bool matchFloat(float *data, float *target) {
    if ( NULL == data ) {
        printf("Sanity check failure in matchFloat.\n");
        return false;
    }
    return (*data == *target);
}

void walkList(struct ListNode *head_ptr, void (*action_proc)()) {
    /*
     * head_ptr: the current head_ptr of the list
     * *action_proc: pointer to the procedure for perfoming whatever
     *       action the caller needs done to the contents of the data
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in walkList procedure.\n");
        return;
    }
    if ( NULL == action_proc ) {
        return; // don't bother walking the list if their is no action
    }
    if ( NULL == head_ptr->next ) {
        return; // don't bother walking an empty list
    }
    struct ListNode *index_ptr = head_ptr;
    while (index_ptr->next != NULL) {
        (action_proc)(index_ptr->next->data);
        index_ptr = index_ptr->next;
    }
    return;
}

void prependNode(struct ListNode *head_ptr, void *new_data) {
    /*
     * head_ptr: the current head_ptr of the list
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in prependNode procedure.\n");
        return;
    }
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
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in appendNode procedure.\n");
        return;
    }
    struct ListNode* new_node = newListNode(new_data);
    struct ListNode* index_ptr = head_ptr;
    while ( index_ptr->next != NULL ) {
        index_ptr = index_ptr->next;
    }
    index_ptr->next = new_node;
    return;
}

void insertNodeAfter(struct ListNode *index_ptr, void *new_data) {
    /*
     * index_ptr: the pointer whos next points to the node after which
     *      the new node should be added. (See comment at the top.)
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    if ( NULL == index_ptr ) {
        printf("Sanity check failure in insertNodeAfter procedure.\n");
        return;
    }
    struct ListNode* new_node = newListNode(new_data);
    if ( index_ptr->next == NULL ) {
        new_node->next = NULL;
        index_ptr->next = new_node;
    }
    else {
        new_node->next = index_ptr->next->next;
        index_ptr->next->next = new_node;
    }
    return;
}

void insertNodeBefore(struct ListNode *index_ptr, void *new_data) {
    /*
     * index_ptr: the pointer whos next points to the node before which
     *      the new node should be added. (See comment at the top.)
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    if ( NULL == index_ptr ) {
        printf("Sanity check failure in insertNodeBefore procedure.\n");
        return;
    }
    struct ListNode* new_node = newListNode(new_data);
    new_node->next = index_ptr->next;
    index_ptr->next = new_node;
    return;
}

void swapNodePointers(struct ListNode *index_a_ptr, struct ListNode *index_b_ptr) {
    /*
     * index_a_ptr and index_b_ptr point to a pair of nodes, once
     * removed from their address, as all _ptr values are. Thus
     * index_a_ptr->next will be what was in index_b_ptr->next, and
     * visa-versa. The nodes following the swap nodes will __not__
     * switch with the swap, but keep their position in the list
     * relative to the head, not the switched nodes.
     */
    if ( NULL == index_a_ptr || NULL == index_b_ptr ) {
        printf("Sanity check failure in swapNodePointers procedure.\n");
        return;
    }
    if ( NULL == index_a_ptr->next || NULL == index_b_ptr->next ) {
        printf("Attempt to swap an empty node is not allowed.\n");
        return;
    }
    if ( index_a_ptr == index_b_ptr ) {
        return; // no point wasting time swapping a node with itself
    }
    if ( index_a_ptr->next == index_b_ptr ) {
        index_a_ptr->next = index_b_ptr->next;
        index_b_ptr->next = index_b_ptr->next->next;
        index_a_ptr->next->next = index_b_ptr;
    }
    else if ( index_b_ptr->next == index_a_ptr ) {
        index_b_ptr->next = index_a_ptr->next;
        index_a_ptr->next = index_a_ptr->next->next;
        index_b_ptr->next->next = index_a_ptr;
    }
    else {
        struct ListNode* a_follow = index_a_ptr->next->next;
        struct ListNode* b_follow = index_b_ptr->next->next;
        struct ListNode* temp_ptr = index_a_ptr->next;
        index_a_ptr->next = index_b_ptr->next;
        index_b_ptr->next = temp_ptr;
        index_a_ptr->next->next = a_follow;
        index_b_ptr->next->next = b_follow;
    }
    return;
}

void swapNodes(struct ListNode *index_a_ptr, struct ListNode *index_b_ptr) {
    /*
     * index_a_ptr and index_b_ptr point to a pair of nodes, once
     * removed from their address, as all _ptr values are. Thus
     * index_a_ptr->next will be what was in index_b_ptr->next, and
     * visa-versa. The nodes following the swap nodes will __not__
     * switch with the swap, but keep their position in the list
     * relative to the head, not the switched nodes.
     */
    if ( NULL == index_a_ptr || NULL == index_b_ptr ) {
        printf("Sanity check failure in swapNodes procedure.\n");
        return;
    }
    if ( NULL == index_a_ptr->next || NULL == index_b_ptr->next ) {
        printf("Attempt to swap an empty node is not allowed.\n");
        return;
    }
    if ( index_a_ptr == index_b_ptr ) {
        return; // no point wasting time swapping a node with itself
    }
    void *temp = index_a_ptr->next->data;
    index_a_ptr->next->data = index_b_ptr->next->data;
    index_b_ptr->next->data = temp;
    return;
}

struct ListNode* findNode(struct ListNode *head_ptr, void *target_ptr, bool (*match_proc)()) {
    /*
     * head_ptr: the current head_ptr of the list
     * target_ptr: a pointer to what is being searched for in the list
     * *match_proc: pointer to the procedure to compare what is in the
     *      pointed to data and the target. Should be able to handle the
     *      type of data itself, and return true/false based on a match.
     *      What constitutes a "match" is beyond the concern of the list
     *
     * returns the first node in the list which causes the match_proc
     * to return a true value. NULL if no match is found.
     */
    if ( NULL == head_ptr || NULL == match_proc ) {
        printf("Sanity check failure in findNode procedure.\n");
        return NULL;
    }
    if ( NULL == head_ptr->next ) {
        return NULL; // don't bother searching an empty list
    }
    struct ListNode* found_ptr = NULL;
    struct ListNode* index_ptr = head_ptr;
    while ( found_ptr == NULL && index_ptr->next != NULL ) {
        if ( (match_proc)(index_ptr->next->data, target_ptr) ) {
            found_ptr = index_ptr;
        }
        else {
            index_ptr = index_ptr->next;
        }
    }
    return found_ptr;
}

void clearList(struct ListNode* head_ptr) {
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in clearList procedure.\n");
        return;
    }
    if ( NULL == head_ptr->next ) {
        return; // don't bother emptying an empty list
    }
    struct ListNode *index_node,  *next_node;
    index_node = head_ptr->next;
    while ( index_node != NULL ) {
        next_node = index_node->next;
        index_node->next = NULL;
        free(index_node);
        index_node = next_node;
    }
    head_ptr->next = NULL;
    return;
}

int countNodes(struct ListNode *head_ptr) {
    /*
     * head_ptr: the current head_ptr of the list
     * Find out how many nodes there are in the list. The "blank" node
     *     that head_ptr points to is not included
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in countNodes procedure.\n");
        return 0;
    }
    int node_count = 0;
    struct ListNode* index_ptr = head_ptr;
    while ( index_ptr->next != NULL ) {
        index_ptr = index_ptr->next;
        node_count++;
    }
    return node_count;
}

void deleteNode(struct ListNode *index_ptr) {
    /*
     * index_ptr: index_ptr->next is the node to remove
     * removes the node, and frees the memory, without returning any
     * data.
     */
    if ( NULL == index_ptr || NULL == index_ptr->next ) {
        printf("Sanity check failure in deleteNode procedure.\n");
        return;
    }
    struct ListNode* target_node = index_ptr->next;
    index_ptr->next = index_ptr->next->next;
    free(target_node);
    return;
}

void* removeNode(struct ListNode *index_ptr) {
    /*
     * index_ptr: index_ptr->next is the node to remove
     * removes the node, and frees the memory, returning a pointer to
     * the data to the caller
     */
    if ( NULL == index_ptr || NULL == index_ptr->next ) {
        printf("Sanity check failure in removeNode procedure.\n");
        return NULL;
    }
    struct ListNode* target_node = index_ptr->next;
    void* data_ptr = target_node->data;
    index_ptr->next = index_ptr->next->next;
    free(target_node);
    return data_ptr;
}

int main() {
    // create the forever empty head node
    struct ListNode* head_ptr = newListNode(NULL);
    return 0;
}

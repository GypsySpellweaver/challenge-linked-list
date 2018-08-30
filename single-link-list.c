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

#ifndef SINGLELINK
#define SINGLELINK

#include <stdlib.h>
#include <stdbool.h>
#define LLNode struct ListNode

/*
 * collection of routines for implementing a singly-linked list.
 *
 * The data in the list is a pointer to something, which need not be
 * the same in every node. The list itself never handles the target of
 * the data pointer, only the pointer itself.
 *
 * The implementation of the list requires that there be a Boolean
 * function that can compare the data from two pointers and judge if
 * they "match" or not. What constitutes a "match" is out of scope for
 * the list, only true or false from the match function.
 *
 * Pointers to the list, head_ptr, curr_ptr, etc., should always point
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
 *
 * The findNode function returns a pointer that meets this pattern, thus
 * in a list 2->4->8->16->32, findNode for 16, will return a pointer
 * such that findNode->next->data = *16.
 */

LLNode {  // the structure of a node
    void* data;    // pointer to what this node should hold
    LLNode* next;  // pointer to the next node in the list
};

LLNode* newListNode(void* new_data) {
    /*
     * create a new node, with a NULL next, and the supplied pointer in
     * data. The new_data pointer can be NULL.
     */
    LLNode* new_node = (LLNode*)malloc(sizeof(LLNode));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void prependNode(LLNode* head_ptr, void* new_data) {
    /*
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in prependNode procedure.\n");
        return;
    }
    LLNode* new_node = newListNode(new_data);
    new_node->next = head_ptr->next;
    head_ptr->next = new_node;
    return;
}

void insertNodeBefore(LLNode* index_ptr, void* new_data) {
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
    LLNode* new_node = newListNode(new_data);
    new_node->next = index_ptr->next;
    index_ptr->next = new_node;
    return;
}

void insertNodeAfter(LLNode* index_ptr, void* new_data) {
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
    LLNode* new_node = newListNode(new_data);
    if ( NULL == index_ptr->next ) {  // if there is no node to insert
        index_ptr->next = new_node;   // "after" then it is the end of
    }                                 // the list, act like appendNode
    else {
        new_node->next = index_ptr->next->next;
        index_ptr->next->next = new_node;
    }
    return;
}

void appendNode(LLNode* head_ptr, void* new_data) {
    /*
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
     * If head_ptr is not the first node, the results are the same since
     * the end of the list does not change based on where you start.
     * new_data: pointer to the new data, pointer value is supplied to
     *      the procedure, not the data itself, which is of no concern
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in appendNode procedure.\n");
        return;
    }
    LLNode* new_node = newListNode(new_data);
    LLNode* index_ptr = head_ptr;
    while ( NULL != index_ptr->next ) {
        index_ptr = index_ptr->next;
    }
    index_ptr->next = new_node;
    return;
}

void swapNodes(LLNode* index_a_ptr, LLNode* index_b_ptr) {
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
    void* temp = index_a_ptr->next->data;
    index_a_ptr->next->data = index_b_ptr->next->data;
    index_b_ptr->next->data = temp;
    return;
}

void swapNodePointers(LLNode* index_a_ptr, LLNode* index_b_ptr) {
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
        LLNode* a_follow = index_a_ptr->next->next;
        LLNode* b_follow = index_b_ptr->next->next;
        LLNode* temp_ptr = index_a_ptr->next;
        index_a_ptr->next = index_b_ptr->next;
        index_b_ptr->next = temp_ptr;
        index_a_ptr->next->next = a_follow;
        index_b_ptr->next->next = b_follow;
    }
    return;
}

LLNode* findNode(LLNode* head_ptr, void* target_ptr, bool (*match_func)()) {
    /*
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
     * Using a different node as the sublist head_ptr allows for doing
     * incremental findNode calls as findNode will return the first
     * node that matches, even if there are multiple matches.
     * target_ptr: a pointer to what is being searched for in the list
     * *match_func: pointer to the procedure to compare what is in the
     *      pointed to data and the target. Should be able to handle the
     *      type of data itself, and return true/false based on a match.
     *      What constitutes a "match" is beyond the concern of the list
     *
     * returns the first node in the list which causes the match_func
     * to return a true value. NULL if no match is found. In this case
     * it is considered that NULL == NULL and handled without a call to
     * the match_func. This means that any side effects from that call
     * will not occur if. Likewise, if any of the data pointers are set
     * NULL, then match_func is not called since NULL is not a match for
     * anything except NULL.
     */
    if ( NULL == head_ptr || NULL == match_func ) {
        printf("Sanity check failure in findNode procedure.\n");
        return NULL;
    }
    if ( NULL == head_ptr->next ) {
        return NULL; // don't bother searching an empty list
    }
    LLNode* found_ptr = NULL;
    LLNode* index_ptr = head_ptr;
    while ( NULL == found_ptr && NULL != index_ptr->next ) {
        if ( NULL == target_ptr ) { // save a procedure call for NULL
            if ( NULL == index_ptr->next->data ) { // as the target
                found_ptr = index_ptr;
            }
            else {
                index_ptr = index_ptr->next;
            }
        }
        else if ( NULL != index_ptr->next->data && (match_func)(index_ptr->next->data, target_ptr) ) {
            found_ptr = index_ptr;
        }
        else {
            index_ptr = index_ptr->next;
        }
    }
    return found_ptr;
}

int countNodes(LLNode* head_ptr) {
    /*
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
     * Find out how many nodes there are in the list. The "blank" node
     *     that head_ptr points to is excluded
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in countNodes procedure.\n");
        return 0;
    }
    int node_count = 0;
    LLNode* index_ptr = head_ptr;
    while ( NULL != index_ptr->next ) {
        index_ptr = index_ptr->next;
        node_count++;
    }
    return node_count;
}

void* removeNode(LLNode *index_ptr) {
    /*
     * index_ptr: index_ptr->next is the node to remove
     * removes the node, and frees the memory, returning the data
     * pointer to the caller
     */
    if ( NULL == index_ptr ) {
        printf("Sanity check failure in removeNode procedure.\n");
        return NULL;
    }
    if ( NULL == index_ptr->next ) {
        printf("Nothing to remove in removeNode procedure.\n");
        return NULL;
    }
    LLNode* target_node = index_ptr->next;
    void* data_ptr = target_node->data;
    index_ptr->next = index_ptr->next->next;
    free(target_node);
    return data_ptr;
}

void deleteNode(LLNode* index_ptr, void (*clear_proc)()) {
    /*
     * index_ptr: index_ptr->next is the node to remove
     * removes the node, and frees the memory, without returning any
     * data.
     *
     * If clear_proc is not NULL, then it is passed the data pointer to
     * handle it. Presumably to free the memory allocated for it.
     */
    if ( NULL == index_ptr ) {
        printf("Sanity check failure in deleteNode procedure.\n");
        return;
    }
    if ( NULL == index_ptr->next ) {
        printf("Nothing to delete in deleteNode procedure.\n");
        return;
    }
    LLNode* target_node = index_ptr->next;
    index_ptr->next = index_ptr->next->next;
    if ( NULL != clear_proc ) {
        (clear_proc)(target_node->data);
    }
    free(target_node);
    return;
}

void clearList(LLNode* head_ptr, void (*clear_proc)()) {
    /*
     * clears all nodes on the list, freeing the allocated memory for
     * each node, starting at head_ptr->next, which need not be the head
     * of the entire list.
     *
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
     *
     * If clear_proc is not NULL, then it is passed the data pointesr to
     * handle them. Presumably to free the memory allocated to them.
     */
    if ( NULL == head_ptr ) {
        printf("Sanity check failure in clearList procedure.\n");
        return;
    }
    if ( NULL == head_ptr->next ) {
        return; // don't bother emptying an empty list
    }
    LLNode *index_node,  *next_node;
    index_node = head_ptr->next;
    while ( NULL != index_node ) {
        next_node = index_node->next;
        index_node->next = NULL;
        if ( NULL != clear_proc ) {
            (clear_proc)(index_node->data);
        }
        free(index_node);
        index_node = next_node;
    }
    head_ptr->next = NULL;
    return;
}

void walkList(LLNode* head_ptr, void (*action_proc)()) {
    /*
     * Process the list, from the point marked by the passed in pointer
     * head_ptr: the current head_ptr of the list, or sublist. head_ptr
     * may point to any node on the list, not just the first node.
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
    LLNode* index_ptr = head_ptr;
    while ( NULL != index_ptr->next ) {
        (action_proc)(index_ptr->next->data);
        index_ptr = index_ptr->next;
    }
    return;
}

#endif
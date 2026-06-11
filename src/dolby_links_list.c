#include <stdlib.h>
#include "../include/ds/csweets.h"

bool create_dll(dll_head *head)
{
    dll_node *header = malloc(sizeof(dll_node));
    if (header == NULL) {
        return false;
    }
    dll_node *trailer = malloc(sizeof(dll_node));
    if (trailer == NULL) {
        return false;
    }

    header->next = trailer;
    trailer->previous = header;
    trailer->next = header->previous = NULL;
    head->header = header;
    head->trailer = trailer;
    head->length = 0;
    return true;
}

bool push_front_dll(dll_head *head, int item)
{
    dll_node *new_node = malloc(sizeof(dll_node));
    if (new_node == NULL) {
        return false;
    }
    dll_node *old_first = head->header->next;
    old_first->previous = new_node;
    new_node->next = old_first;
    new_node->previous = head->header;
    new_node->item = item;
    head->header->next = new_node;
    head->length++;
    return true;
}

bool push_back_dll(dll_head *head, int item)
{
    dll_node *new_node = malloc(sizeof(dll_node));
    if (new_node == NULL) {
        return false;
    }
    dll_node *old_last = head->trailer->previous;
    old_last->next = new_node;
    new_node->next = head->trailer;
    new_node->previous = old_last;
    new_node->item = item; 
    head->trailer->previous = new_node;
    return true;
}

bool insert_at_dll(dll_head *head, size_t index, int item)
{
    size_t index_from_top = (head->length - index) + 1;
    dll_node *new_node = malloc(sizeof(dll_node));
    if (new_node == NULL) {
        return false;
    }
    dll_node *pointer;
    dll_node *tmp;
    if (index > head->length / 2) {
        pointer = head->trailer;
        for (size_t i = 0; i < index_from_top; i++) { 
            pointer = pointer->previous;
        }
    } else {
        pointer = head->header;
        for(size_t i = 0; i < index; i++) {
            pointer = pointer->next;
        }
    }
    dll_node *break_node = pointer->previous; 
    break_node->next = new_node;
    new_node->previous = break_node;
    new_node->next = pointer;
    new_node->item = item;
    pointer->previous = new_node;
    head->length++;
    return true;
}

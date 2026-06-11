#include <stdlib.h>
#include "../include/ds/csweets.h"

bool create_list(ll_head *new_head)
{
    new_head->head = NULL;
    new_head->length = 0;
    return true;
}

bool push_front(ll_head *head, int item)
{
    ll_node *new_node = malloc(sizeof(ll_node));
    if (new_node == NULL) {
        return false;
    }
    new_node->next = head->head;
    new_node->item = item;
    head->head = new_node;
    head->length++;
    return true;
}

bool push_back(ll_head *head, int item)
{    
    if (head->length == 0) {
        push_front(head, item);
        return true;
    }

    ll_node *new_node = malloc(sizeof(ll_node));
    if (new_node == NULL) {
        return false;
    }
    new_node->item = item;
    new_node->next = NULL;
    ll_node *pointer = head->head;
    for (size_t i = 0; pointer->next != NULL; i++) {
        pointer = pointer->next;
    }
    pointer->next = new_node;
    head->length++;
    return true;
}

bool pop_front(ll_head *head)
{
    if (head->length == 0) {
        return false;
    }
    ll_node *to_go = head->head;
    head->head = to_go->next;
    head->length--;
    free(to_go);
    return true;
}

bool pop_back(ll_head *head)
{
    if (head->length == 0) {
        return false;
    }
    ll_node *pointer = head->head;
    for (size_t i = 0; i < head->length - 2; i++) {
        pointer = pointer->next;
    }
    free(pointer->next);
    pointer->next = NULL;
    head->length=0;
    return true;
}

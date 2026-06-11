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

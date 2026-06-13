#include <stdio.h>
#include <stdlib.h>
#include "../include/ds/csweets.h"

#define CAPACITY(array) ((array)->size / sizeof(int))

// todo: failure message function

bool create_int_array(size_t number_elements, int_array *an_array)
{
    if (number_elements < 1) {
        number_elements = 4;
    }
    size_t size = number_elements * sizeof(int); 
    int_array new_array;
    new_array.array = malloc(size);
    if (new_array.array == NULL) {
        printf("Out of memory, exiting . . .\n");
        exit(EXIT_FAILURE);
    }
    new_array.length = 0;
    new_array.size = size;

    return new_array;
}

bool delete_int_array(int_array *an_array)
{
if (an_array->array) {
        free(an_array->array);
        an_array->array = NULL;
        an_array->size = 0;
  an_array->length = 0;
        return true;
    }
    return false;
}

bool is_space(int_array *an_array)
{
    if (CAPACITY(an_array) <= an_array->length) 
        return false;                             
    return true;
}

bool index_exists(int_array *an_array, size_t index)
{
    if (an_array->length <= index)
        return false;
    return true;
}

bool expand_array(int_array *an_array)   {
    size_t new_size = (an_array->size) * 2;
    int *tmp = realloc(an_array->array, new_size);
    if (tmp == NULL) {
        return false;
    }                        
    an_array->array = tmp;
    an_array->size = new_size;
    return true;
}

bool make_room(int_array *an_array) 
{                             
    if (is_space(an_array) == false) {
        if (expand_array(an_array)) {
            return true;
        }
        return false;
    }
    return true;
}

bool shrink_to_fit(int_array *an_array)
{
    if (CAPACITY(an_array) == an_array->length || an_array->length == 0)
        return true;
    if (CAPACITY(an_array) > an_array->length) {
        size_t length_in_bytes = sizeof(int) * an_array->length;
        int *tmp = realloc(an_array->array, length_in_bytes);
        if (tmp != NULL) {
                an_array->array = tmp;
                an_array->size = length_in_bytes;
                return true;
            }
    }

    return false;
}

bool append(int_array *an_array, int an_integer){
    if (make_room(an_array)) {
        an_array->array[an_array->length] = an_integer;
        an_array->length++;
        return true;
    }
    return false;
} 

bool insert(int_array *an_array, size_t index, int item)
{
    if (index_exists(an_array, index)) {
        if (make_room(an_array)) {
            size_t length_after = an_array->length - index;
            size_t final_index = an_array->length;

            for (size_t i = final_index; i > index; i--) {
                an_array->array[i] = an_array->array[i - 1];
            }
            an_array->array[index] = item;
            an_array->length++;
            return true;
        }
    }
    return false;
}

bool delete_item(int_array *an_array, size_t index)
{
    if (index_exists(an_array, index)) {
       for (size_t i = index; i + 1 < an_array->length; i++) {
            an_array->array[i] = an_array->array[i+1];
        }
        an_array->length--;
        return true;
    }
    return false;
}   

bool search(int_array *an_array, int item, size_t *index)
{
    for (size_t i = 0; i < an_array->length; i++)
        if (an_array->array[i] == item) {
            if (index != NULL)
                *index = i;
            return true;
        }
    return false;
}


bool get(int_array *an_array, size_t index, int *element)
{
    if (index_exists(an_array, index)) {
        if (element != NULL)
            *element = an_array->array[index];
        return true;
    }
    return false;
}

bool max(int_array *an_array, int *max_element)
{
    if (max_element != NULL) {
        if (an_array->length > 0) {
            *max_element = an_array->array[0];
            for (size_t i = 0; i < an_array->length; i++) {
                if (an_array->array[i] > *max_element) {
                    *max_element = an_array->array[i];
                }
            }
            return true;
        }
    }
    return false;
}

bool min(int_array *an_array, int *min_element) {
    if (min_element != NULL) {
        if (an_array->length > 0) {
            *min_element = an_array->array[0];
            for (size_t i = 0; i < an_array->length; i++) {
                if (an_array->array[i] < *min_element) {
                    *min_element = an_array->array[i];
                }
            }
            return true;
        }
    }
    return false;
}

void print_array(int_array *an_array)
{
    for (size_t i = 0; i < an_array->length; i++)
    { 
        printf("Memory address: %p\tIndex: %zu\tValue:% d\n",
                &an_array->array[i], i, an_array->array[i]);
    }
}

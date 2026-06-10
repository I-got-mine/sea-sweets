/**************************************************************   
 *                   Groggy's Sea Sweets                      *
 * Inelegant Integer-only Iterative Data Structure Operations *
 *                       6/9/26                               *
 *************************************************************/

#include <stdlib.h>
#include <stdbool.h>

typedef struct int_array {
    int *array;
    size_t size;          // <--size in bytes, length in 
    size_t length;        //                     elements
} int_array;

/**                                             **
 *           INTEGER ARRAY OPERATIONS!!!!       *
 **                                             */         
int_array create_int_array(size_t number_elements);
bool delete_int_array(int_array *an_array);
bool expand_array(int_array *an_array);

bool append(int_array *an_array, int an_integer);
bool insert(int_array *an_array, size_t index, int item);
bool delete_item(int_array *an_array, size_t index);

/**
 * TODO: i think i want these out of the header
 *       and only in the program space
 */
bool is_space(int_array *an_array);
bool index_exists(int_array *an_array, size_t index);
/******************************************************/

bool search(int_array *an_array, int item, size_t *index);
bool get(int_array *an_array, size_t index, int *element);

// TODO:
bool max(int_array *an_array, int *max_element);
bool min(int_array *an_array, int *min_element);

void display(int_array *an_array);

// shift and rotate elements
void shift(int_array *an_array, bool direction, size_t shift);
void rot(int_array *an_array, char direction, size_t shift);

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

/**
 * Create and destroy an array of integers
 */
int_array create_int_array(size_t number_elements);
bool delete_int_array(int_array *an_array);
bool expand_array(int_array *an_array);

/**
 * Array modifications return true if successful
 * TODO: these should all be bools
 */
void append(int_array *an_array, int an_integer);
void insert(int_array *an_array, size_t index, int item);
void delete_item(int_array *an_array, size_t index);

/**
 * TODO: i think i want these out of the header
 *       and only in the program space
 */
bool is_space(int_array *an_array);
bool index_exists(int_array *an_array, size_t index);

/**
 * Data stuff, takes an array, necessary info, and a 
 * pointer to store the answer. Returns false if array
 * is empty in case min/max, and if the element or index
 * do not exist in the case of search/geti
 */
bool search(int_array *an_array, int item, size_t *index);
bool get(int_array *an_array, size_t index, int *element);
bool max(int_array *an_array, int *max_element);
bool min(int_array *an_array, int *min_element);

void display(int_array *an_array);

// shift and rotate elements
void shift(int_array *an_array, bool direction, size_t shift);
void rot(int_array *an_array, char direction, size_t shift);

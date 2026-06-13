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

typedef struct ll_node {
    int item;
    struct ll_node *next;
} ll_node;

typedef struct ll_head {
    ll_node *head;
    size_t length;
} ll_head;

typedef struct dll_node {
    int item;
    struct dll_node *previous;
    struct dll_node *next;
} dll_node;

typedef struct dll_head {
    dll_node *header;
    dll_node *trailer;
    size_t length;
} dll_head;

/**                                             **
 *           INTEGER ARRAY OPERATIONS!!!!        *
 **                                              */         
bool create_int_array(size_t number_elements, int_array *an_array);
bool delete_int_array(int_array *an_array);
bool expand_array(int_array *an_array);

bool append(int_array *an_array, int an_integer);
bool insert(int_array *an_array, size_t index, int item);
bool delete_item(int_array *an_array, size_t index);
bool shrink_to_fit(int_array *an_array);

/**
 * TODO: i think i want these out of the header
 *       and only in the program space
 */
bool is_space(int_array *an_array);
bool index_exists(int_array *an_array, size_t index);
/******************************************************/

bool search(int_array *an_array, int item, size_t *index);
bool get(int_array *an_array, size_t index, int *element);

bool max(int_array *an_array, int *max_element);
bool min(int_array *an_array, int *min_element);
void print_array(int_array *an_array);

/*  TODO:
* void clear(int_array *an_array);
* void set_at(int_array *an_array, int value, size_t index);
*/

/**                                                  **
 *          SINGLE LINKED LIST OPERATIONS             *
 **                                                  **/

bool create_list(ll_head *head);
bool destroy_list(ll_head *head); // <-TODO

bool push_front(ll_head *head, int item);
bool push_back(ll_head *head, int item);
bool insert_at(ll_head *list, int item, size_t index);

bool pop_front(ll_head *head, int *value);
bool pop_back(ll_head *head, int *value);
bool remove_at(ll_head *head, size_t index);

bool get_at(ll_head *head, size_t index, int *got_item);

void print(ll_head *head);

/*      TODO:  (don't forget get_length just has to read head)
* bool find_item(ll_head *head, int item, int *item_index);
* bool get_length(ll_head *head);
*/


/**                                                      **
 *         DOUBLE LINKED LIST OPERATIONS                  *
 **                                                      **/

bool create_dll(dll_head *head);
bool destroy_dll(dll_head *head);

bool push_front_dll(dll_head *head, int item);
bool push_back_dll(dll_head *head, int item);
bool insert_at_dll(dll_head *head, size_t index, int item);

bool pop_front_dll(dll_head *head, int *item);
bool pop_back_dll(dll_head *head, int *item);
bool remove_at_dll(dll_head *head, size_t index);
bool get_at_dll(dll_head *head, size_t index, int *item);
bool find_item_dll(dll_head *head, int item);
bool get_length_dll(dll_head *head);

void print_forward(dll_head *head);


/*    TODO:
*bool print_backward(dll_head *head);
*bool remove_at_dll(dll_head *head, size_t index);
*bool get_at_dll(dll_head *head, size_t index, int *item);
*bool find_item_dll(dll_head *head, int item);
*bool get_length_dll(dll_head *head);
*/


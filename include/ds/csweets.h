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

/**                                             **
 *           INTEGER ARRAY OPERATIONS!!!!        *
 **                                              */         
int_array create_int_array(size_t number_elements);
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

/*  TODO:
* void display(int_array *an_array);
* void clear(int_array *an_array);
* void set_at(int_array *an_array, int value, size_t index);
*/

/**                                                  **
 *              LINKED LIST OPERATIONS                *
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
bool find_item(ll_head *head, int item, int *item_index);

bool get_length(ll_head *head);

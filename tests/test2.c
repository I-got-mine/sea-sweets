#include <stdio.h>
#include "../include/ds/csweets.h"

#define CLEAR_SCREEN() printf("\033[2J\033[H")

void print_main_menu();
void array_menu();
void sll_menu();
void dll_menu();
void add_sub_menu();
void array_world();
void create_array(int_array *array, bool *is_array);
void array_insert(int_array *array);
void array_delete(int_array *array);

int main(void)
{
    int input, input2;

    CLEAR_SCREEN();
    print_main_menu();
    scanf("%d", &input);
    while (getchar() != '\n');
    switch(input) {
        case 1: CLEAR_SCREEN(); 
                array_world(); 
                break;
        case 2: CLEAR_SCREEN(); 
                sll_menu();
                break;
        case 3: CLEAR_SCREEN(); 
                dll_menu();
                break;
        case 4: CLEAR_SCREEN();
                exit(EXIT_SUCCESS);
        default: CLEAR_SCREEN();
    }
    scanf(" %d", &input2);
    while (getchar() != '\n');
    printf("%d %d\n", input, input2);

    return 0;
}

void print_main_menu()
{
    printf("Welcome to let's see if this shit works, please make a selection:\n");
    printf("1: Dynamic Array\n2: Singly Linked List\n3: Doubly linked list\n4: Quit");
}

void array_menu()
{
    CLEAR_SCREEN();
    printf("Dynamic Array\n");
    printf("1: Create array\t2: Add element\t3: Remove element\n");
}

 void sll_menu()
 {
     printf("Singly Linked List\n");
     printf("1:Create list\t2: Add element\t3: Remove element\n");

 }
  
  void dll_menu()
  {
      printf("Doubly Linked List\n");
      printf("1: Create list\t2: Add element\t3: Remove element\n");
  }


  void add_sub_menu()
  {
      printf("Where?\n");
      printf("1: Up front\tt2: In the back\t 3: Lemme tell you\n");
  }

void array_world()
{
    int_array array;
    int menu_choice;
    bool is_array = false;
    bool *array_status = &is_array;
    while (true) {
        array_menu();
        scanf("%d", &menu_choice);
        while (getchar() != '\n');
        switch (menu_choice) {
            case 1: create_array(&array, array_status);
                    CLEAR_SCREEN();
                    break;
            case 2: array_insert(&array); 
                    CLEAR_SCREEN();
                    break;
            case 3: array_delete(&array);
                    CLEAR_SCREEN();
                    break;
        }
        printf("Here's your array, hows it look?\n");
        print_array(&array);
        printf("\n");
        system("read -p 'press [ENTER]'");
    }
}

void create_array(int_array *array, bool *is_array)
{
    if (*is_array == false) {
        size_t input;
        printf("How many elements you wanna start with? ");
        scanf("%zu", &input);
        while (getchar() != '\n');
        if (create_int_array(input, array)) {
            *is_array = true;
            printf("You got it, %zu elements\n", input);
            system("read -p 'press [ENTER]'");
            return;
        };
        CLEAR_SCREEN();
        system("read -p 'You fucked up . . . press[ENTER] '");
        exit(EXIT_FAILURE);
    }
    printf("One at a time . . .");
    system("read -p 'press[ENTER]'");
    return;
}

void array_insert(int_array *array)
{
    int new_element;
    size_t  index;
    printf("Gimme an integer: ");
    scanf("%d", &new_element);
    while (getchar() != '\n');
    printf("At what index? ");
    scanf("%zu", &index);
    if (insert(array, index, new_element)) {
        printf("%d should be at index %zu\n", new_element, index);
        system("read -p 'press [ENTER]'");
        return;
    }
    CLEAR_SCREEN();
    system("read -p 'you fucked up . . . press [ENTER] '");
    return;
}

void array_delete(int_array *array)
{
    size_t index;
    printf("Which one?");
    scanf("%zu", &index);
    while (getchar() != '\n');
    if (delete_item(array, index)) {
        printf("Should be gone . . .");
        system("read -p 'press [ENTER]'");
        return;
    }
    CLEAR_SCREEN();
    system("read -p 'You fucked up . . . press[ENTER] '");
    exit(EXIT_FAILURE);
}

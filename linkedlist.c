/*
    *********************************************************
                    Linked List Implementation
    ---How following code works ------
    -- A Linked list is made up of 1 or N number of nodes forming a chain
    where each node points to next node 







   *****************************************************


*/


















#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node  *next;
};

struct linked_list {
    int size; 
    struct node *head;
    struct node *tail;
};
typedef struct linked_list list;


//void add(list *tail, int value);
//void create_list(list *head, list *tail,  int value);
void instantiate_list(list *list_ptr);
void add(list *list_ptr, int value);

void print_list(list *head);
void cleanup(list *list_ptr);

int main(){
    
    list even_list;
    list *even_list_ptr = &even_list;
    instantiate_list(even_list_ptr);
    add(even_list_ptr, 22);
    add(even_list_ptr, 2);
    print_list(even_list_ptr);
    cleanup(even_list_ptr);
    





    return 0;
}

void instantiate_list(list *list_ptr){
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
    list_ptr->size = 0;
}


void add(list *list_ptr, int value){
    // create a node and let head and tail point to it
    // checks if the list if empty
    struct node *new_node;
    if(list_ptr->size == 0) {
        // add element
        list_ptr->head  =  (struct node*)malloc(sizeof(struct node));
        list_ptr->head->data = value;
        list_ptr->tail = list_ptr->head;
        return;
    }

    /*
        Checks if there is 1 node 
     */
    if((list_ptr->head == list_ptr->tail) && (list_ptr->size > 0)){
        // code here
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = value;
        list_ptr->tail->next = new_node;
        list_ptr->tail = new_node;

    }
   list_ptr->size += 1; // update the size of list.
    // allocate some space and let head and tail points  to it    
}
/*
void add(list *tail,  int value) {
    list *new_node; 
    if(tail != NULL){
        new_node = (list *)malloc(sizeof(list));
        //set values and set pointer to NULL
        new_node->data = value;
        new_node->next_ptr = NULL;
        
        // make it point to new node
        tail->next_ptr = new_node;
        tail = new_node;
        return;
    }
    // if list is empty
    // new_node = (list *)malloc(sizeof(list));
}
*/
/*
//instantiate a new list, it assumes the list is empty
void create_list(list *head, list *tail,  int value) {
    head = (list *)malloc(sizeof(list));
    head->data = value;
    head->next_ptr = NULL;

    tail = head; // now let tail too point to the same node
   printf("tail: %p, head %p\n", tail, head); 
    printf("Exited create_list\n");
    
}
*/
void print_list(list *list_ptr) {
    struct node * trav = list_ptr->head;
    while(trav != NULL) {
        
        printf("value: %d, address: %p\n", trav->data, trav);
        trav = trav->next;
    }
    printf("Exited print_list\n");
}

void cleanup(list *list_ptr){
    struct node *tmp;
    while(list_ptr->head != NULL) {
        tmp = list_ptr->head;
        list_ptr->head = list_ptr->head->next;
        free(tmp);
        tmp = NULL;

    }
 printf("Exited cleanup\n");
}

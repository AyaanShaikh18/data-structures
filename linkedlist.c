#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct linked_list {
	int data;
	struct linked_list *next_ptr;
};
typedef struct linked_list list;


void add(list *tail, int value);
void create_list(list *head, list *tail,  int value);
void print_list(list *head);
void cleanup(list *head);

int main(){

    list * head = NULL;
    list *tail = NULL;
    create_list(head,tail, 10);
    print_list(head);
    cleanup(head);


    return 0;
}

void add(list *tail,  int value) {
    /* new element node pointer*/
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
// instantiate a new list, it assumes the list is empty
void create_list(list *head, list *tail,  int value) {
    head = (list *)malloc(sizeof(list));
    head->data = value;
    head->next_ptr = NULL;

    tail = head; // now let tail too point to the same node
   printf("tail: %p, head %p\n", tail, head); 
    printf("Exited create_list\n");
    
}

void print_list(list *head) {
    list * trav = head;
    while(trav != NULL) {
        
        printf("value: %d, address: %p\n", trav->data, trav);
        trav = trav->next_ptr;
    }
    printf("Exited print_list\n");
}

void cleanup(list *head){
    list *tmp;
    while(head != NULL) {
        tmp = head;
        head = head->next_ptr;
        free(tmp);
        tmp = NULL;

    }
    printf("Exited cleanup\n");
}




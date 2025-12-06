#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node *next;
    struct Node *prev;
}Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current_position;
    int length;
    int cur_pos;
    
} LinkedList;



void init_linkedlist(LinkedList *list)
{
    //printf("Implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL; 
    list->current_position = NULL;
    list->length = -1;
    list->cur_pos = -1;
    
}


void clear(LinkedList *list)
{
    //printf("Implement clear\n");
    // traverse the list and free each node
    // set head and tail to null
    if(list->head == NULL){
        printf("List is already cleared.\n");
        return;
    }
    Node *temp = list->head;
    while(temp != NULL){
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->length = -1;
    list->cur_pos = -1;
    printf("List cleared.\n");
}


int get_size(LinkedList *list)
{
    //printf("Implement get_size\n");
    
    return (list->length);
}


void append(LinkedList *list, int value)
{
    //printf("Implement append\n");
    // create a new node and set its value
    // consider the case when the list is empty and when it isnt
    if(list->head == NULL){
        Node *new_node = (Node *)malloc(sizeof(Node));
        if(new_node == NULL){
            printf("memory allocation failed in append.\n");
            return;
        }
        new_node->data = value;
        new_node->prev = NULL;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
        list->current_position = new_node;
        (list->length) = 1;
        (list->cur_pos) = 0;
    }
    else{
        Node *new_node = (Node *)malloc(sizeof(Node));
        if(new_node == NULL){
            printf("memory allocation failed in append.\n");
            return;
        }
        new_node->data = value;
        new_node->prev = list->tail;
        new_node->next = NULL;
        list->tail->next = new_node;
        list->tail = new_node;
        (list->length)++;
    }
}


void insert(LinkedList *list, int value)
{
    //printf("Implement insert\n");
    // create a new node and set its value
    // place it at the current position (check order of operations)
    // consider the case when the list is empty and when it isnt
    if(list->head == NULL){
        Node *new_node = (Node *)malloc(sizeof(Node));
        if(new_node == NULL){
            printf("memory allocation failed in insert.\n");
            return;
        }
        new_node->data = value;
        new_node->prev = NULL;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
        list->current_position = new_node;
        list->cur_pos = 0;
        (list->length) = 1;
    }
    else if(list->cur_pos == 0){
        Node *new_node = (Node *)malloc(sizeof(Node));
        if(new_node == NULL){
            printf("memory allocation failed in insert.\n");
            return;
        }
        new_node->data = value;
        new_node->next = list->current_position;
        new_node->prev = NULL;
        list->current_position->prev = new_node;
        list->head = new_node;
        list->current_position = new_node;
        (list->length)++;
    }
    else{
        Node *new_node = (Node *)malloc(sizeof(Node));
        if(new_node == NULL){
            printf("memory allocation failed in insert.\n");
            return;
        }
        new_node->data = value;
        new_node->prev = list->current_position->prev;
        new_node->next = list->current_position;
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        list->current_position = new_node;
        (list->length)++;
    }
}


int remove_at_current(LinkedList *list)
{
    //printf("Implement remove_at_current\n");
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1;
    }
    Node *temp = list->current_position;
    int data = temp->data;
    if(list->length == 1){
        free(temp);
        list->head = NULL;
        list->tail = NULL;
        list->current_position = NULL;
        list->length = -1;
        list->cur_pos = -1;   
    }
    else if(list->length != 1 && list->head != NULL){
        if(temp->prev == NULL){
            list->head = temp->next;
            list->current_position = temp->next;
            list->current_position->prev = NULL;
            free(temp);
            (list->length)--;
            list->cur_pos = 0;
        }
        else if(temp->next == NULL){
            list->tail = temp->prev;
            list->current_position = temp->prev;
            list->current_position->next = NULL;
            free(temp);
            (list->length)--;
            list->cur_pos = (list->length - 1);
        }
        else{
            list->current_position = temp->next;
            list->current_position->prev = temp->prev;
            temp->prev->next = list->current_position;
            free(temp);
            (list->length)--;
        }
    }
    // consider the case when current code is at the begining or at the end
    return data;
}


int find(LinkedList *list, int value)
{
    //printf("Implement find\n");
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1;
    }
    Node *temp1, *temp2;
    temp1 = list->head;
    temp2 = list->tail;
    int i = 0;
    int j = list->length - 1;
    //int pos = -1;
    int pos_i = 0;
    int pos_j = j;
    int is_i = 0;
    int is_j = 0;
    while(i <= j){
        
        if(temp1->data == value){
            is_i = 1;
            pos_i = i;
            break;
        }
        else if(temp2->data == value){
            is_j = 1;
            pos_j = j;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
        i++;
        j--;
    }
    if(is_i){
        return pos_i;
    }
    if(is_j){
        return pos_j;
    }
    return -1;
    
}


void move_to_start(LinkedList *list)
{
    //printf("Implement move_to_start\n");
    if(list->head != NULL){
        list->current_position = list->head;
        list->cur_pos = 0;
        printf("moved current position to 0\n");
    }
    else{
        printf("List is empty.\n");
    }
}


void move_to_end(LinkedList *list)
{
   // printf("Implement move_to_end\n");
    if(list->tail != NULL){
        list->current_position = list->tail;
        list->cur_pos = (list->length - 1);
        printf("moved current position to %d\n", list->length - 1);     
    }
    else{
        printf("List is empty.\n");
    }
}


void prev(LinkedList *list)
{
    //printf("Implement prev\n");
    if(list->current_position != NULL && list->current_position->prev != NULL){
        list->current_position = list->current_position->prev;
        (list->cur_pos)--;
        printf("moved current position from %d to %d\n",list->cur_pos + 1,list->cur_pos);
    }
    else{
        printf("Failed to move to previous.\n");
    }
}


void next(LinkedList *list)
{
    //printf("Implement next\n");
    if(list->current_position != NULL && list->current_position->next != NULL){
        list->current_position = list->current_position->next;
        (list->cur_pos)++;
        printf("moved current position from %d to %d\n",list->cur_pos - 1,list->cur_pos);
    }
    else{
        printf("Failed to move to next.\n");
    }
}


void move_to_position(LinkedList *list, int position)
{
    
    //printf("Implement move_to_position\n");
    
    int pos = 0;
    int len = list->length;
    if(list->head == NULL){
        printf("List is empty.\n");
        return;
    }
    if(position < 0 || position >= len ){
        // Invalid Position
        printf("Invalid position'\n");
        return;
    }
    int pos1 = list->cur_pos;
    // traverse the list and stop at the given position
    if(position < len/2){

        if((list->cur_pos - position) <= position){
            while(list->cur_pos < position){
                list->current_position = list->current_position->next;
                (list->cur_pos)++;
            }
            while(list->cur_pos > position){
                list->current_position = list->current_position->prev;
                (list->cur_pos)--;
            }
        }
        else{
            Node *temp = list->head;
            pos = 0;
            while(pos < len/2){
                if(pos == position){
                    list->current_position = temp;
                    break;
                }
                pos++;
                temp = temp->next;
            }
            list->cur_pos = position;
        }
    }
    else{

        if((position-(list->cur_pos)) <= ((list->length)-position-1)){

            while(list->cur_pos < position){
                list->current_position = list->current_position->next;
                (list->cur_pos)++;
            }
            while(list->cur_pos > position){
                list->current_position = list->current_position->prev;
                (list->cur_pos)--;
            }
        }
        else{
            Node *temp = list->tail;
            pos = len-1;
            while(pos >= (len/2)){
                if(pos == position){
                    list->current_position = temp;
                    break;
                }
                pos--;
                temp = temp->prev;
            }
            list->cur_pos = position;
        }

    }
    printf("moved current position from %d to %d\n",pos1,list->cur_pos);
}


int get_current_position(LinkedList *list)
{
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1;
    }
    return (list->cur_pos);
}


int get_current_element(LinkedList *list)
{
    //printf("Implement get_current_element\n");
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1 ;
    }
    // return the value at the current position
    int data = list->current_position->data;
    return data;
}


void print_list(LinkedList *list)
{
    //printf("< list elements here >");
    Node *temp;
    temp = list->head;
    printf("< ");
    if(list->head != NULL){
        
        while(temp != NULL){
            if(temp == list->current_position){
                printf("|%d  ",temp->data);
            }
            else{
                printf("%d  ",temp->data);
            }
            temp = temp->next;
        }
        
    }
    if(list->head == NULL){
        printf("  ");
    }
    printf("\b>\n");
}



void free_list(LinkedList *list)
{
    //printf("Implement free_list\n");
    // free each node in the list
    if(list->head == NULL){
        printf("List is already freed\n");
        return;
    }
    if(list->head != NULL){
        Node *temp, *next;
        temp = list->head;
        next = temp->next;
        while(temp != NULL){
            free(temp);
            temp = next;
            if(temp != NULL){
                next = temp->next;
            }
        }
        list->head = NULL;
        list->tail = NULL;
        list->current_position = NULL;
        list->length = -1;
        list->cur_pos = -1;
    }
    printf("List freed.\n");
}

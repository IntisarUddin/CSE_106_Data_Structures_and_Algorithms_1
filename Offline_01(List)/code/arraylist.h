#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList
{
    int *array;
    // Add more fields here
    int length;
    int capacity;
    int cur_pos;
    
} ArrayList;


void init_arraylist(ArrayList *list, int capacity)
{
    //printf("implement init_arraylist\n");
    // dynamically allocate space for the array
    // initialize the length, capacity, and current position
    list->array = (int *)malloc(capacity * sizeof(int));
    if(list->array == NULL){
        printf("memory allocation failed in initialization.\n");
        return;
    }
    list->length = -1;
    list->capacity = capacity;
    list->cur_pos = -1;
}


void clear(ArrayList *list)
{
    //printf("Implement clear\n");
    // clear the list but do not free the array
    // modify the length, capacity, and current position
    if(list->length == -1){
        printf("List is already cleared.\n");
        return;
    }
    list->length = -1;
    list->cur_pos = -1;
    list->capacity = 1;
    printf("list cleared.\n");
}

int get_size(ArrayList *list)
{
    //printf("Implement get_size\n");
    return (list->length);
}


void resize(ArrayList *list, int new_capacity)
{
    //printf("Implement resize\n");
    // allocate space for new array with new_capacity
    // print log message
    printf("Resized array from %d to %d\n",list->capacity,new_capacity);
    int *new_array = (int *)malloc((sizeof(int)*new_capacity));
    if(new_array == NULL){
        printf("memory allocation failed in resize.\n");
        return;
    }
    for(int i = 0; i < list->length; i++){
        *(new_array + i) = *(list->array + i);
    }
    if(list->array != NULL){
        free(list->array);
    }
    
    list->array = new_array;
    list->capacity = new_capacity;
}


void append(ArrayList *list, int value)
{
    //printf("Implement append\n");
    // call resize if necessary
    // add value to the end of the list
    if(list->length == list->capacity){
        resize(list,(2*(list->capacity)));
    }
    if(list->length == -1){
        list->length = 0;
        list->cur_pos = 0;
        *(list->array + (list->length)) = value;
        (list->length)++;
    }
    else{
        *(list->array + (list->length)) = value;
        (list->length)++;
    }
}


void insert(ArrayList *list, int value)
{
    //printf("Implement insert\n");
    // call resize if necessary
    // shift the elements to the right to make space
    // add value at the current position
    if(list->length == list->capacity){
        resize(list,(2*(list->capacity)));
    }
    if(list->length == -1){
        list->length = 0;
        list->cur_pos = 0;
        *(list->array + (list->length)) = value;
        (list->length)++;
    }
    else{
        for(int i = list->length; i > list->cur_pos; i--){
            *(list->array + i) = *(list->array + i - 1);
        }
        *(list->array + (list->cur_pos)) = value;
        (list->length)++;
    }
}


int remove_at_current(ArrayList *list)
{
    //printf("Implement remove_at_current\n");
    // save the value of the current element in a variable
    // shift the elements to the left to fill the gap
    // change the length, and current position as necessary
    // call resize if necessary
    // return the saved value
    if(list->length == -1){
        printf("List is empty.\n");
        return -1;
    }
    if(list->length == 1){
        int temp = *(list->array);
        list->length = -1;
        list->cur_pos = -1;
        list->capacity = 1;
        return temp;
    }
    int temp = *(list->array + list->cur_pos);
    if(list->cur_pos == list->length - 1){
        (list->cur_pos)--;
        (list->length)--;
        if((list->length) <= ((list->capacity)/4)){
            resize(list,(list->capacity)/2);
        }
        return temp;
    }
    for(int i = list->cur_pos; i < list->length - 1; i++){
        *(list->array + i) = *(list->array + i + 1);
    }
    (list->length)--;
    if((list->length) <= ((list->capacity)/4)){
        resize(list,(list->capacity)/2);
    }
    return temp;
}

int find(ArrayList *list, int value)
{
    //printf("Implement find\n");
    // traverse the list and return the position of the value
    // return -1 if the value is not found
    if(list->length == -1){
        printf("List is empty.\n");
        return -1;
    }
    int i = 0;
    int j = list->length - 1;
    int pos_i = i;
    int pos_j = j;
    int is_i = 0;
    int is_j = 0;
    while(i <= j){
        if(*(list->array + i) == value){
            is_i = 1;
            pos_i = i;
            break;
        }
        else if(*(list->array + j) == value){
            is_j = 1;
            pos_j = j;
        }
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


void move_to_start(ArrayList *list)
{
    //printf("Implement move_to_start\n");
    // consider the cases when the list is empty
    if(list->length != -1){
        list->cur_pos = 0;
        printf("moved current position to 0\n");
    }
    else{
        printf("List is empty.\n");
    }
}


void move_to_end(ArrayList *list)
{
    //printf("Implement move_to_end\n");
    // consider the cases when the list is empty
    if(list->length != -1){
        list->cur_pos = list->length - 1;
        printf("moved current position to %d\n", list->length - 1);
    }
    else{
        printf("List is empty.\n");
    }
}


void prev(ArrayList *list)
{
    //printf("Implement prev\n");
    // no change if the current position is at the start
    if(list->cur_pos > 0){
        (list->cur_pos)--;
        printf("moved current position from %d to %d\n",list->cur_pos + 1,list->cur_pos);
    }
    else{
        printf("Failed to move to previous.\n");
    }
}


void next(ArrayList *list)
{
    //printf("Implement next\n");
    // no change if the current position is at the end
    if((list->length != -1) && list->cur_pos < list->length - 1 ){
        (list->cur_pos)++;
        printf("moved current position from %d to %d\n",list->cur_pos - 1,list->cur_pos);
    }
    else{
        printf("Failed to move to next.\n");
    }
}


void move_to_position(ArrayList *list, int position)
{
    //printf("Implement move_to_position\n");
    if(position < 0 || position >= list->length){
        //Invalid Position;
        printf("Invalid position\n");
        return;
    }
    if(list->length == -1){
        printf("List is empty.\n");
        return;
    }
    int pos1 = list->cur_pos;
    list->cur_pos = position;
    printf("moved current position from %d to %d\n",pos1,list->cur_pos);
}


int get_current_position(ArrayList *list)
{
    //printf("Implement get_current_position\n");
    if(list->length == -1 ){
        printf("List is empty.\n");
        return -1;
    }
    return (list->cur_pos);
}


int get_current_element(ArrayList *list)
{
    //printf("Implement get_current_element\n");
    int data = -1;
    if(list->cur_pos != -1){
        data = *(list->array + list->cur_pos);
    }
    else{
        printf("List is empty.\n");
    }
    return data;
}


void print_list(ArrayList *list)
{
    //printf("< list elements here >");
    printf("< ");
    for(int i = 0; i < list->length; i++){
        if(i == list->cur_pos){
            printf("|%d  ",*(list->array + i));
        }
        else{
            printf("%d  ",*(list->array + i));
        }
    }
    if(list->length ==  -1){
        printf("  ");
    }
    printf("\b>\n");
}


void free_list(ArrayList *list)
{
    //printf("Implement free_list\n");
    // free the array before terminating the program
    if(list->array != NULL){
        free(list->array);
    }
    else{
        printf("List is already freed.\n");
        return;
    }
    printf("List freed.\n");
}



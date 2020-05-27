#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void* list_create();
int list_count(void*);
void list_add(void*, void*);
void* list_get(void*, int);
void list_destroy(void*);
void list_remove(void*, void*);

typedef struct List
{
    int size;
    void** element;
} List;


void main()
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4,item5 = 5,item6 = 6, item7 = 7;
    
    void* list = list_create();
    
    list_add(list, &item1);
    list_add(list, &item2);
    
    int count = list_count(list);
    printf("\nLength: %d", count);

    int* item = list_get(list, 1);
    printf("\nItem: %d", *item);
        
    list_add(list, &item3);
    list_add(list, &item4);
    list_add(list, &item5);
    list_add(list, &item6);

    count = list_count(list);
    printf("\nLength: %d", count);
    
    int* item_2 = list_get(list, 3);
    printf("\nItem: %d", *item_2);

    printf("\nSucessful run!");
}

void* list_create()
{
    List* new = malloc(sizeof(List));
    
    new->size = 0;
    new->element = malloc(sizeof(void*));

    return new;
}

void list_add(void* list, void* item)
{
    List* lists = (List*)list;
    
    int* size = &lists->size;
    
    lists->element[*size] = item;
    lists->size++;

    lists->element = realloc(lists->element, (*size+1) * sizeof(void*));
     
    printf("\nAdded Successfully");
}

int list_count(void* list)
{   
    List* lists = (List*)list;

    int count = lists->size;
    
    return count;
}

void* list_get(void* list, int index)
{
    List* lists = (List*)list;

    void* item = lists->element[index];
    
    return item;  
}

void list_destroy(void* list)
{       
    free(list);
}

void list_remove(void* list, void* item)
{

}
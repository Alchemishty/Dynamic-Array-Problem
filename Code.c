#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void* list_create();
int list_count(void*);
void list_add(void*, void*);
void* list_get(void*, int);
void list_destroy(void*);
void list_remove(void*, void*);

void test();

typedef struct List
{
    int size;
    void** element;
} List;


void main()
{
    test();
}

void test()
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4,item5 = 5,item6 = 6, item7 = 7, item8 = 8;
    
    void* list = list_create();
    
    list_add(list, &item1); // Could have used a for loop for all list_add calls, I know lol
    list_add(list, &item2);   
    list_add(list, &item3);
    list_add(list, &item4);
    list_add(list, &item5);
    list_add(list, &item6);

    int count = list_count(list);
    printf("\nLength: %d\n", count);
    
    for (int i = 0; i < count; i++)
    {
        int* item = list_get(list, i);
        printf("%d ", *item);
    }

    list_remove(list, &item2);

    count = list_count(list);

    for (int i = 0; i < count; i++)
    {
        int* item = list_get(list, i);
        printf("%d ", *item);
    }

    list_remove(list, &item3);
    list_remove(list, &item5);

    count = list_count(list);

    for (int i = 0; i < count; i++)
    {
        int* item = list_get(list, i);
        printf("%d ", *item);
    }

    list_remove(list, &item8);
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
    List* lists = (List*)list;

    int count = list_count(list);

    bool itemFound;

    for (int i = 0; i < count; i++)
    {
        if (lists->element[i] == item)
        {
            itemFound = true;
            
            int steps = count - i - 1, position = i;
            
            for (int j = 0; j < steps; j++)
            {
                void* item = lists->element[position];
                
                lists->element[position] = lists->element[position+1];
                lists->element[position+1] = item;

                position++;
                
            }

            int* size = &lists->size;
            lists->size--;

            lists->element = realloc(lists->element, (*size) * sizeof(void*));

            printf("\nItem removed succesfully!");
            break;
        }
        
    }

    if (!itemFound)
    {
        printf("\nItem does not exist in this list");
    }
}
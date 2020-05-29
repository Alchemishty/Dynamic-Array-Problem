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
    void** elements;
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
    List* newList = malloc(sizeof(List));
    
    newList->size = 0;
    newList->elements = malloc(sizeof(void*));

    return newList;
}

void list_add(void* list, void* item)
{
    List* inventory = (List*)list;
    
    
    inventory->elements[inventory->size] = item;
    inventory->size++;

    inventory->elements = realloc(inventory->elements, (inventory->size + 1) * sizeof(void*));
}

int list_count(void* list)
{   
    List* inventory = (List*)list;

    int count = inventory->size;
    
    return count;
}

void* list_get(void* list, int index)
{
    List* inventory = (List*)list;

    void* item = inventory->elements[index];
    
    return item;  
}

void list_destroy(void* list)
{       
    free(list);
}

void list_remove(void* list, void* item)
{
    List* inventory = (List*)list;

    int count = list_count(list);

    bool itemFound;

    for (int i = 0; i < count; i++)
    {
        if (inventory->elements[i] == item)
        {
            itemFound = true;
            
            int steps = count - i - 1, position = i;
            
            for (int j = 0; j < steps; j++)
            {
                void* item = inventory->elements[position];
                
                inventory->elements[position] = inventory->elements[position+1];
                inventory->elements[position+1] = item;

                position++;
            }

            inventory->size--;

            inventory->elements = realloc(inventory->elements, (inventory->size) * sizeof(void*));

            break;
        }
    }

    if (!itemFound)
    {
        printf("\nItem does not exist in this list");
    }
}
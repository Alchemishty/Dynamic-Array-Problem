#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void* list_create();
int list_count(void*);
void list_add(void*, void*);
void* list_get(void*, int);
void list_destroy(void*);
void list_remove(void*, void*);

void main()
{
    int item1= 5, item2 = 6, item3  = 3, item4 = 8;
    void* list = list_create();
    list_add(list, &item1);
    list_add(list, &item2);
    list_add(list, &item3);
    int length = list_count(list);
    printf("Length of list is: %d\n", length);
    int* item = list_get(list, 2);
    printf("Item at position is: %d\n", *item);
    list_remove(list, &item3);
    length = list_count(list);
    printf("Length of list is: %d\n", length);
    system("Pause");
}
struct Element
{
  void* value;
  int position;
};

typedef struct Element Element;  

void* list_create()
{
  Element* new = malloc(sizeof(Element));
  new->position = -1;
  return new;
}

void list_add(void* list, void* item)
{
  Element* add = (Element*)list;
  int length = list_count(list);
  int factor = length + 2;
  add = realloc(add, factor*sizeof(Element));
  (add+length)->position = length + 1;
  (add+length)->value = item;
  (add+length+1)->position = -1;
}

int list_count(void* list)
{
  Element* element = (Element*)list;
  int position = 0, length = 0;
  for(int i = 0; ; i++)
    {
      position = (element+i)->position;
      if(position == -1)
      {
        break;
      }
      else length++;
    }
    return length;
  }

  void* list_get(void* list, int index)
  {
      Element* get = (Element*)list;
      int position = index - 1;
      void* item = (get+position)->value;
      return item;  
  }

  void list_destroy(void* list)
  {
      free(list);
  }

  void list_remove(void* list, void* item)
  {
    Element* remove = (Element*)list;
    int length = list_count(list);
    bool itemFound;
    for(int i = 0; i < length; i++)
    {
      if((remove+i)->value == item)
      {
        int position = (remove+i)->position;
        int steps = length - position + 1;
        for(int j = 0; j <= steps; j++)
        {
          void* item = (remove+position)->value; 
          (remove+position)->value = (remove+position+1)->value;
          (remove+position+1)->value = item;
          position++;
        }
        (remove+length-1)->position = -1;
        itemFound = true;
      }
    }
    if(itemFound)
    {
      list = realloc(list, length - 1);
    }
    else printf("\nItem does not exist in the list");
  }
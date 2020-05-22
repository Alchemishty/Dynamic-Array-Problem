#include<stdio.h>
#include<stdlib.h>

void* list_create();
int list_count(void*);
void list_add(void*, void*);
void main()
{
    int item1= 5, item2 = 6, item3  = 3;
    void* list = list_create();
    list_add(list, &item1);
    list_add(list, &item2);
    list_add(list, &item3);
    int length = list_count(list);
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
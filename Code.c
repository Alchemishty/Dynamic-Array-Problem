#include<stdio.h>
#include<stdlib.h>

void* list_create();
int list_count(void* );
void list_add(void* , void* );
void main()
{
    int a = 5, b = 6, c  = 3;
    void *x = &a, *y = &b, *z = &c;
    void* list = list_create();
    list_add(list, x);
    list_add(list, y);
    list_add(list, z);
    int length = list_count(list);
    printf("Length of list is: %d", length);
    
}
struct element
{
  void* value;
  int position;
};

typedef struct element element;  

void* list_create()
{
  element* ret = malloc(sizeof(element));
  ret->position = -1;
  return (void*)ret;
}

void list_add(void* list, void* item)
{
  element* impl = (element*)list;
  int len = list_count(list);
  int factor = len + 2;
  impl = realloc(impl, factor*sizeof(element));
  (impl+len)->position = len + 1;
  (impl+len)->value = item;
  (impl+len+1)->position = -1;
}

int list_count(void* list)
{
  element* x = (element*)list;
  int end = 0, len = 0;
  for(int i = 0; ; i++)
    {
      end = (x+i)->position;
      if(end == -1)
      {
        break;
      }
      else len++;
    }
    return len;
  }
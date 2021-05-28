#include <stdio.h>
#include <stdlib.h>

int comp_count = 0;

struct Person
{
  char name[40];
  int  age;
};

void swap( int *var1, int *var2 )
{
   int temp = *var1;
   *var1 = *var2;
   *var2 = temp;
}

void merge_sort( void *base, size_t num, size_t size, int (*compare)(const void*, const void*))
{
    const size_t num_aux = size * num;
    char aux[num_aux];
    merge_sort(base, 0, num-1, compare);
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
	int j = low;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void print_person(struct Person *p)
{
  printf("%s, %d years old\n", p->name, p->age);
}

void print_persons(struct Person ps[], size_t person_number)
{
  struct Person *p = ps;
  puts("Persons:");
  while(person_number--)
    print_person(p++);
}

int compare_persons(const void *p1v, const void *p2v)
{
  const struct Person *p1 = (const struct Person*) p1v, *p2 = (const struct Person*) p2v;
    comp_count++;
  if(p1->age < p2->age)
    return -1;
  else if(p1-> age > p2->age)
    return 1;
  else
    return 0;

}

void quicksort(void *base, int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
 
int main()
{
  struct Person ps[] = {
    {"Оля", 25},
    {"Катя", 35},
    {"Таня", 37},
    {"Наташа", 20},
    {"Аня", 19},
    {"Петя", 21},
    {"Дима", 40},
    {"Вася", 33},
    {"Олег", 22},
    {"Витя", 27}
  };
  
  print_persons(ps, 10);
  comp_count = 0;
  merge_sort(ps, 10, sizeof(struct Person), compare_persons);
  print_persons(ps, 10);
  printf("comp_count == %d\n", comp_count);
  comp_count = 0;

  struct Person query = {"", 35};
  puts("Person of 35 y.o.");
  print_person(bsearch(&query, ps, 10, sizeof(struct Person), compare_persons));

  struct Person ps1[] = {
    {"Оля", 25},
    {"Катя", 35},
    {"Таня", 37},
    {"Наташа", 20},
    {"Аня", 19},
    {"Петя", 21},
    {"Дима", 40},
    {"Вася", 33},
    {"Олег", 22},
    {"Витя", 27}
  };
  comp_count = 0;
  quicksort(ps1, 10, sizeof(struct Person));
  printf("comp_count == %d\n", comp_count);
  comp_count = 0;

  return 0;
}

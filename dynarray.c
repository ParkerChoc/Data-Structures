/*
 * This file is where you should implement your dynamic array.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name: Parker Choc
 * Email: chocp@oregonstate.edu
 */

#include <stdlib.h>
#include<stdio.h>
#include <assert.h>
#include "dynarray.h"

struct dynarray
{
  void** data;
  int size;
  int capacity;
};

struct dynarray* dynarray_create()
{
  struct dynarray* d = malloc(sizeof(struct dynarray));
  d->size = 0;
  d->capacity = 2;
  d->data = malloc(2*sizeof(void*));
  return d;
}

void dynarray_free(struct dynarray* da)
{
  free(da->data);
  free(da);
}

int dynarray_size(struct dynarray* da)
{
  return da->size;
}

int dynarray_capacity(struct dynarray* da)
{
  return da->capacity;
}

void dynarray_resize(struct dynarray* da)
{
  if(da->size == da->capacity)
  {
    da->data = realloc(da->data, da->capacity * 2 * sizeof(void*));
    da->capacity = da->capacity * 2;
  }
}

void dynarray_insert(struct dynarray* da, void* val)
{
  dynarray_resize(da);
  da->data[da->size] = val;
  da->size++;
}

void dynarray_print(struct dynarray* da)
{
  printf("Size: %d\n", da->size);
  printf("Capacity: %d\n", da->capacity);
  for (int i = 0; i < da->size; i++)
    printf("Data: %d\n", *((int *)da->data[i]));
}

void dynarray_remove(struct dynarray* da, int idx)
{
  int counter = idx;
  do
  {
    da->data[counter] = da->data[counter + 1];
    counter++;
  } 
  while (counter < da->size - 1);
  da->data[counter] = NULL;
  da->size--;
}

void* dynarray_get(struct dynarray* da, int idx)
{
  return da->data[idx];
}

void dynarray_set(struct dynarray* da, int idx, void* val)
{
  da->data[idx] = val;
}
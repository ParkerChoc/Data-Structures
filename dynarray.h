/*
 * This file contains the definition of the interface for the dynamic array
 * you'll implement.  You can find descriptions of the dynamic array functions,
 * including their parameters and their return values, in dynarray.c. You
 * should not modify anything in this file.
 */

#ifndef __DYNARRAY_H
#define __DYNARRAY_H

struct dynarray;
struct dynarray* dynarray_create();
void dynarray_free(struct dynarray* da);
int dynarray_size(struct dynarray* da);
int dynarray_capacity(struct dynarray* da);
void dynarray_insert(struct dynarray* da, void* val);
void dynarray_print(struct dynarray* da);
void dynarray_remove(struct dynarray* da, int idx);
void* dynarray_get(struct dynarray* da, int idx);
void dynarray_set(struct dynarray* da, int idx, void* val);

#endif
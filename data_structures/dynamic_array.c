#include <stdio.h>
#include <stdlib.h>

void init_dynamic_array(int **arr, size_t *used, size_t *size,
                        int initial_size);
void check_resize_dynamic_array(int **arr, size_t *used, size_t *size);
void check_bounds_dynamic_array(size_t *used, size_t index);
void append_dynamic_array(int **arr, size_t *used, size_t *size, int element);
void deduct_dynamic_array(int **arr, size_t *used);
void insert_dynamic_array(int **arr, size_t *used, size_t *size, int element,
                          size_t index);
void delete_dynamic_array(int **arr, size_t *used, size_t index);
void access_dynamic_array(int **arr, size_t *used, size_t index);
void linear_search_dynamic_array(int **arr, size_t *used, int element);
void print_dynamic_array(int **arr, size_t *used);

int main(void) {
  int *arr;
  size_t used;
  size_t size;

  init_dynamic_array(&arr, &used, &size, 2);
  append_dynamic_array(&arr, &used, &size, 100);
  append_dynamic_array(&arr, &used, &size, 200);
  append_dynamic_array(&arr, &used, &size, 300);
  append_dynamic_array(&arr, &used, &size, 400);
  append_dynamic_array(&arr, &used, &size, 500);
  insert_dynamic_array(&arr, &used, &size, 600, 1);
  access_dynamic_array(&arr, &used, 5);
  print_dynamic_array(&arr, &used);
  linear_search_dynamic_array(&arr, &used, 200);
  delete_dynamic_array(&arr, &used, 4);
  deduct_dynamic_array(&arr, &used);
  deduct_dynamic_array(&arr, &used);
  print_dynamic_array(&arr, &used);
  free(arr);
}

void init_dynamic_array(int **arr, size_t *used, size_t *size,
                        int initial_size) {
  *arr = calloc(initial_size, sizeof(int));
  *used = 0;
  *size = initial_size;
}

void check_resize_dynamic_array(int **arr, size_t *used, size_t *size) {
  if (*used + 1 >= *size) { // keep 1 extra space for insertion
    *size *= 2;
    *arr = realloc(*arr, *size * sizeof(int));
  }
}

void check_bounds_dynamic_array(size_t *used, size_t index) {
  if (index < 0 || index > *used - 1) { // indexing starts from 0
    printf("Out of bounds\n");
    exit(1);
  }
}

void append_dynamic_array(int **arr, size_t *used, size_t *size, int element) {
  check_resize_dynamic_array(arr, used, size);
  // *(*arr + (*used)++) = element; // pointer notation
  (*arr)[(*used)++] = element; // array notation
  // printf("%d %d\n", *used, *size); // DEBUG
}

void deduct_dynamic_array(int **arr, size_t *used) {
  printf("Deleted element %d at index %zu\n", (*arr)[*used - 1], *used - 1);
  (*used)--;
}

void insert_dynamic_array(int **arr, size_t *used, size_t *size, int element,
                          size_t index) {
  check_resize_dynamic_array(arr, used, size);
  check_bounds_dynamic_array(used, index);
  for (size_t i = *used + 1; i > index; i--) { // right shift by 1 element
    (*arr)[i] = (*arr)[i - 1];
  }
  (*arr)[index] = element;
  (*used)++;
}

void delete_dynamic_array(int **arr, size_t *used, size_t index) {
  check_bounds_dynamic_array(used, index);
  printf("Deleted element %d at index %zu\n", (*arr)[index], index);
  for (size_t i = index; i < *used - 1; i++) { // left shift by 1 element
    (*arr)[i] = (*arr)[i + 1];
  }
  (*used)--;
}

void access_dynamic_array(int **arr, size_t *used, size_t index) {
  check_bounds_dynamic_array(used, index);
  printf("Element at index %zu is %d\n", index, (*arr)[index]);
}

void linear_search_dynamic_array(int **arr, size_t *used, int element) {
  int found = -1;
  for (size_t i = 0; i < *used; i++) {
    if ((*arr)[i] == element) {
      printf("Element %d found at index %zu\n", element, i);
      found = 1;
    }
  }
  if (found == -1) {
    printf("Element %d was not found\n", element);
  }
}

void print_dynamic_array(int **arr, size_t *used) {
  for (size_t i = 0; i < *used; i++) {
    printf("%d ", (*arr)[i]);
  }
  printf("\n");
}

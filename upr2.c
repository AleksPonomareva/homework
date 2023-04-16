#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int **arr, int rows, int cols) {
printf("Array:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++)
printf("%d ", arr[i][j]);
printf("\n");
}
}

void search_element(int **arr, int rows, int cols, int target) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (arr[i][j] == target) {
printf("Element %d is found at row %d and column %d\n", target, i+1, j+1);
return;
}
}
}

printf("Element %d is not found in the array\n", target);
}

int main() { // запрашиваем число rows и cols 
int rows, cols;

printf("Enter the number of rows: ");
scanf("%d", &rows);

printf("Enter the number of columns: ");
scanf("%d", &cols);

int **arr = (int **) malloc(rows * sizeof(int *));   //Создается массив с помощью динамического выделения памяти с использованием функции malloc
for (int i = 0; i < rows; i++)
arr[i] = (int *) malloc(cols * sizeof(int));

srand(time(NULL));

printf("Enter the elements of the array:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
arr[i][j] = rand() % 100; // генерируем случайные числа от 0 до 99
printf("%d ", arr[i][j]);
}
printf("\n");
}

int target;

printf("Enter the element to search for: ");
scanf("%d", &target);

search_element(arr, rows, cols, target); //осуществляем поиск элемента target в массиве arr 

for (int i = 0; i < rows; i++)
free(arr[i]);
free(arr);

return 0;
}
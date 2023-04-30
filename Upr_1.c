// Ответы на вопросы:
// 1. Теоретически, лучшим алгоритмом сортировки является сортировка расческой (Comb sort),
// так как она имеет временную сложность O(n log n) и в худшем случае выполняется за O(n^2).
// Посмотрим на практике: я взяла 10 следующих слов: hello, happy, mother, father, sun, look, lost, 
// park, water, hook. Получились следующие результаты: Selection sort(число итераций - 45, время - 0.000003с)
// Bubble sort( число итераций - 45, время - 0.000002с), Comb sort (число итераций - 32, время 0.000001с)
// Затем я взяла еще 10 слов: num, number, kol, yt, iir, ytr, false, etw, tyu, erty. Получились следующие результаты:
// Selection sort(число итераций - 45, время - 0.000006с)
// Bubble sort( число итераций - 45, время - 0.000004с), Comb sort (число итераций - 32, время 0.000002с)
// 2. Нет, выполнение алгоритмов может занять разное количество времени (это видно в ответе номер 1) в зависимости от
// конкретных данных. Это связано с тем, что каждый алгоритм имеет свою временную сложность
// и особенности работы с данными, поэтому для некоторых данных один алгоритм может быть
// оптимальным, а для других данные другой алгоритм. Поэтому необходимо заранее знать какой
// алгоритм лучше использовать для конкретных данных.

#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 10

// Функция печати массива
void print_array(char array[SIZE][10]) {
for (int i = 0; i < SIZE; i++) {
for (int j = 0; j < 10; j++) {
printf("%c", array[i][j]);
}
printf("\n");
}
}

// Функция обмена двух строк в массиве
void swap(char array[SIZE][10], int i, int j) {
char temp[10];
strcpy(temp, array[i]);
strcpy(array[i], array[j]);
strcpy(array[j], temp);
}

// Функция сортировки выбором
int selection_sort(char array[SIZE][10]) {
int count = 0;
for (int i = 0; i < SIZE - 1; i++) {
int min_idx = i;
for (int j = i + 1; j < SIZE; j++) {
if (strcmp(array[j], array[min_idx]) < 0) {
min_idx = j;
}
count++;
}
swap(array, i, min_idx);
}
return count;
}

// Функция сортировки пузырьком
int bubble_sort(char array[SIZE][10]) {
int count = 0;
for (int i = 0; i < SIZE - 1; i++) {
for (int j = 0; j < SIZE - i - 1; j++) {
if (strcmp(array[j], array[j + 1]) > 0) {
swap(array, j, j + 1);
}
count++;
}
}
return count;
}

// Функция сортировки расческой
int comb_sort(char array[SIZE][10]) {
int count = 0;
int gap = SIZE;
float shrink = 1.3;
int swapped = 1;
while (gap > 1 || swapped) {
if (gap > 1) {
gap = (int)(gap / shrink);
}
swapped = 0;
for (int i = 0; i + gap < SIZE; i++) {
if (strcmp(array[i], array[i + gap]) > 0) {
swap(array, i, i + gap);
swapped = 1;
}
count++;
}
}
return count;
}

int main() {
char words[SIZE][10];
printf("Введите %d слов:\n", SIZE);
for (int i = 0; i < SIZE; i++) {
scanf("%s", words[i]);
}

int choice = 0;
printf("Какой алгоритм использовать для сортировки?\n");
printf("1. Сортировка выбором\n");
printf("2. Сортировка пузырьком\n");
printf("3. Сортировка расческой\n");
printf("4. Использовать все алгоритмы\n");
scanf("%d", &choice);

if (choice == 1) {
    clock_t start = clock();
    int count = selection_sort(words);
    clock_t end = clock();
    printf("Отсортированный массив:\n");
    print_array(words);
    printf("Число итераций: %d\n", count);
    printf("Время выполнения: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);
} else if (choice == 2) {
    clock_t start = clock();
    int count = bubble_sort(words);
    clock_t end = clock();
    printf("Отсортированный массив:\n");
    print_array(words);
    printf("Число итераций: %d\n", count);
    printf("Время выполнения: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);
} else if (choice == 3) {
    clock_t start = clock();
    int count = comb_sort(words);
    clock_t end = clock();
    printf("Отсортированный массив:\n");
    print_array(words);
    printf("Число итераций: %d\n", count);
    printf("Время выполнения: %f сек\n", (double)(end - start) / CLOCKS_PER_SEC);
} else if (choice == 4) {
    clock_t start1 = clock();
    int count1 = selection_sort(words);
    clock_t end1 = clock();
    printf("Отсортированный массив (Selection sort):\n");
    print_array(words);
    printf("Число итераций: %d\n", count1);
    printf("Время выполнения: %f сек\n\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    clock_t start2 = clock();
    int count2 = bubble_sort(words);
    clock_t end2 = clock();
    printf("Отсортированный массив (Bubble sort):\n");
    print_array(words);
    printf("Число итераций: %d\n", count2);
    printf("Время выполнения: %f сек\n\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    clock_t start3 = clock();
    int count3 = comb_sort(words);
    clock_t end3 = clock();
    printf("Отсортированный массив (Comb sort):\n");
    print_array(words);
    printf("Число итераций: %d\n", count3);
    printf("Время выполнения: %f сек\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
} else {
    printf("Недопустимый выбор.\n");
}

return 0;
}
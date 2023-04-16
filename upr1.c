#include <stdio.h>

int max_sequence(char arr[], int size, char c) {  
int count = 0, max = 0;

for (int i = 0; i < size; i++) {
if (arr[i] == c)
count++;
else {
if (count > max)
max = count;

count = 0;
}
}

if (count > max)
max = count;

return max;
}

int main() {                                                       //в данной функции опрееляем размер массива size, вызываем функцию max_sequence, и результат выводим на экран с помощью printf
char arr[10] = {'a', 'b', 'c', 'a', 'a', 'a', 'd', 'e', 'a', 'f'};         //в качестве примера возьмем массив arr размером 10
char c = 'a';
int size = sizeof(arr) / sizeof(arr[0]);

int max = max_sequence(arr, size, c);             // функция осуществляет поиск максимальной последовательности символа c в переданном массиве arr размером size

printf("Max sequence: %d\n", max);

return 0;
}
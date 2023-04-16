#include <stdio.h>

int main() {
int n;

printf("Введите степень бинома Ньютона: ");   //Запрашиваем у пользователя степень
scanf("%d", &n);

int pascal_triangle[n+1][n+1];   //массив имеет размер n+1 на n+1, так как нулевая строка и столбец также могут использоватьсядля вычисления коэв бинома Ньютона

for (int i = 0; i <= n; i++) {
for (int j = 0; j <= i; j++) {               //Цикл for вложенный в другой цикл for используется для заполнения массива pascal_triangle и вывода значений на экран.
if (i == j || j == 0)
pascal_triangle[i][j] = 1;
else
pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];
printf("%d ", pascal_triangle[i][j]);
}
printf("\n");
}

return 0;
}
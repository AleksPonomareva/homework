#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <stdbool.h>
#include <stdlib.h>	// Данная библиотека для многих функций Си нужна, но не здесь
#include <locale.h> // Библиотека для указания локации (региональной кодировки) для Visual Studio

int Bissectrice(double, double);
int Vertical(double, double);
int Horizontal(double, double);

// Конструкция с void main работает только на С. С++ такое уже не примет.
// При выполнении функции main() запускается новый Процесс (Process), к которой автоматически подключается Runtime Library.
// return 0; - является кодом выхода из этого Process. Поэтому необходим int main(){return0;}
int main() {
	int x=-5;
	int y=5;
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);
	printf("%d", (!Vertical(x, y) && !Horizontal(x, y) && Bissectrice(x, y)) || (Vertical(x, y) && Horizontal(x, y)));
	return 0;
}

int Bissectrice(double x, double y) {
	bool res = true;
	res = ((y <= -x));
	return res;
}

int Vertical(double x, double y) {
	bool res = true;
	res = (x > 4);
	return res;
}
int Horizontal(double x, double y) {
	bool res = true;
	res = (y > 3);
	return res;
}

// (0, 0) true
// (1, 7) false
// (-6, 7) True
// (68, 90) true
// (23, -80) false
// (2, 10) false
// (11, 57) true
// (6, 4) true
// (7, 9) True
// (-15, 1) true
// (0, 3) false





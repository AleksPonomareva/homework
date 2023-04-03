#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>


int main() {

    double x = 2;
    double y = 1;
    
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    
    if ((x >= 0) && (y >= 0) && (x <= 5) && (y <= 5) && ((pow((y-5),2) + pow((x-5),2)) >= 25)){
        printf("1");
    } 
    else{
        printf("0");
    }
    return 0;
}

// (0, 0) true
// (1, 1) true
// (0, 3) false
// (2, 10) false
// (6, 4) false
// (7, 9) false
// (11, 57) false
// (1, 7) false
// (-6, 7) false
// (2, 0) true
// (68, 90) false
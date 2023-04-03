#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* GetInput();
bool Testinput(char*);
int strToInt(char*);
void printInt(int);

int num;
char* a;
char* b;
int c;

int main(){
char* b = GetInput();
    if (Testinput(b) == true) {
        int c = strToInt(b);
        printInt(c);
        } 
    else {
    printf("Не получится, формат не int\n");
        }
    return 0;
}

char* GetInput(){
    char* a = malloc(sizeof(char) * 256);
    printf("Преобразуем:\n");
    scanf("%s", a);
    return a;
}

bool Testinput(char* a){
    int num;
    if (sscanf(a, "%d", &num) == 1) {
        return true;
        }       
    else {
    return false;
    }   
};
    
int strToInt(char* a){
    return atoi(a);
};

void printInt(int a){
    printf("%d\n", a);
}
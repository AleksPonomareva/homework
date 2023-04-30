#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100 // Максимальная длина слова

int main() {
    char word[MAX_LEN + 1]; // +1 для нуль-терминатора
    int vowels = 0, consonants = 0;

    printf("Введите слово (латиница без заглавных символов): ");
    scanf("%s", word);

    char *p = word; // Указатель на первый символ слова
    while (*p != '\0') {
        if (isalpha(*p)) { // Проверяем является ли символ буквой
            switch (tolower(*p)) { // Приводим символ к нижнему регистру для проверки гласная она или согласная
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
        p++; // Переходим к следующему символу в слове
    }

    printf("Количество гласных: %d\n", vowels);
    printf("Количество согласных: %d\n", consonants);

    return 0;
}
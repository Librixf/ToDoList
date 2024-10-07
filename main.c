#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

char stroka[MAX];

int vibor(int n, int s);
int zapis(int s);
char vivod(void);
char udalenie(void);

int main() {
    int n, s;
    extern char stroka[MAX];

    n = s = 0;
    udalenie();
    
    while (true)
    {
        vibor(n, s);
    }

    return 0;
}

int vibor(int n, int s) {
    printf("\nВведите одно из чисел:\n1. Запись новой заметки.\n2. Вывод записи.\n3. Стирание.\nЧисло: ");
    while ((n = getchar()) != '\n')
    {
        if (n == '1')
        {
            printf("Запись пошла!\n");
            scanf("%*[^\n]");
            scanf("%*c");
            zapis(s);
        } else if (n == '2')
        {
            vivod();
        } else if (n == '3')
        {
            udalenie();
        }
    }
    return 0;
}

int zapis(int s) {
    int i;
    extern char stroka[MAX];
    
    for (int i = 0; i <= MAX; i++)
    {
        stroka[i] = 0;
    }
    i = 0;

    while ((s = getchar()) != '\n')
    {
        stroka[i] = s;
        ++i;
    }
    stroka[i + 1] = '\0';
    printf("Запись завершена!\n");

    return 0;
}

char vivod(void) {
    int i = 0;
    extern char stroka[MAX];
    printf("Вывод: ");
    while (true)
    {
        if (stroka[i] == 0)
        {
            break;
        }

        printf("%c", stroka[i]);
        ++i;
    }
    
    printf("\nВывод зевершён!\n");
    return 0;
}

char udalenie(void) {
    extern char stroka[MAX];
    int i;

    for (i = 0; i <= MAX; i++)
    {
        stroka[i] = 0;
    }

    i = 0;

    printf("Очистка зевершена!\n");

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

char stroka[MAX];
int i;

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
    extern int i;
    extern char stroka[MAX];
    
    while ((s = getchar()) != '\n')
    {
        stroka[i] = s;
        ++i;
    }
    ++i;
    stroka[i] = '\0';
    printf("Запись завершена!\n");

    return 0;
}

char vivod(void) {
    int n,c;
    n = c = 0;
    extern char stroka[MAX];
    
    printf("Вывод: ");
    while (true)
    {
        if (stroka[n] == '\0')
        {
            scanf("%*[^\n]");
            scanf("%*c");
            printf("\nВывести следующую заметку? 1 или 0\nЧисло: ");
            c = getchar();
            
            if (c == '0')
            {
                return 0;
            } else if (c == '1')
            {
                printf("Вывод: ");
            }
        }

        printf("%c", stroka[n]);
        ++n;
    }
    
    printf("\nВывод зевершён!\n");
    return 0;
}

char udalenie(void) {
    extern char stroka[MAX];
    extern i;
    int n;

    for (n = 0; n <= MAX; n++)
    {
        stroka[n] = 0;
    }

    n = i = 0;

    printf("Очистка зевершена!\n");

    return 0;
}

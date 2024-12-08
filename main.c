#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

size_t i;

int selection(int n, char *line);
char output_line(char *line);
char deletion_line(char *line);

int main(void) {
    int n, s;
    char *str = NULL;

    str = (char *)malloc(MAX * sizeof(char));

    if(str == NULL) {
        printf("Неизвестная ошибка!");
        return EXIT_FAILURE;
    }

    n = s = 0;
    deletion_line(str);
    
    while (true)
    {
        selection(n, str);
    }

    free(str);
    return EXIT_SUCCESS;
}

int selection(int n, char *line) {
    extern size_t i;
    size_t max = MAX;

    printf("\nВведите одно из чисел:\n1. Запись новой заметки.\n2. Вывод записи.\n3. Стирание.\nЧисло: ");

    n = getchar();
    getchar();

    if (n == '1')
    {
    printf("Запись пошла!\n");

    i = getline(&line, &max, stdin);

    printf("\nЗаписанно: %s", line);  
          
    } else if (n == '2')
    {
        output_line(line);
    } else if (n == '3')
    {
        deletion_line(line);
    } else if (n == '4')
    {
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}

char output_line(char *line) {
    int n,c;
    n = c = 0;
    
    if (line[0] != '\0')
    {
        printf("\n%s", line);
    } else
    {
        printf("Ничего нет!");
    }
    
    printf("\nВывод зевершён!\n");
    return EXIT_SUCCESS;
}

char deletion_line(char *line) {
    extern size_t i;
    int n;

    for (n = 0; n <= i; n++)
    {
        line[n] = '\0';
    }

    n = i = 0;

    printf("Очистка зевершена!\n");

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000


int selection(char *line);
char output_line(char **mas, int c);
char deletion_line(char **mas, int c);
int add_to_mass(char *line, char **mas, int c);

int main(void) {
    int c = 0;
    char *str = NULL;

    str = (char *)malloc(MAX * sizeof(char));
    if(str == NULL) {
        printf("Неизвестная ошибка!");
        return EXIT_FAILURE;
    }

    c = selection(str);

    free(str);
    return EXIT_SUCCESS;
}

int selection(char *line) {
    int n;
    size_t i;
    size_t max = MAX;
    char *mas_chast[MAX];
    static int c = 0;
    
    while (true) {
        printf("Введите одно из чисел:\n1. Запись новой заметки.\n2. Вывод записи.\n3. Стирание.\nЧисло: ");

        n = getchar();
        getchar();

        if (n == '1')
        {
        printf("Запись пошла!\n");

        i = getline(&line, &max, stdin);
        c = add_to_mass(line, mas_chast, c);

        } else if (n == '2')
        {
            output_line(mas_chast, c);
        } else if (n == '3')
        {
            deletion_line(mas_chast, c);
        } else if (n == '4')
        {
            break;
        }
    }
    
    return EXIT_SUCCESS;
}

char output_line(char **mas, int c) {
    int n;
    
    printf("Заметки:\n");
    for (n = 0; n < c; n++)
    {
        printf("%s\n", mas[n]);
    }

    return EXIT_SUCCESS;
}

char deletion_line(char **mas, int c) {
    int n;
    for (n = 0; c > n; n++)
    {
        free(mas[n]);
        mas[n] = NULL;
    }

    printf("Очистка зевершена!\n");

    return EXIT_SUCCESS;
}

int add_to_mass(char *line, char **mas, int c) {
    
    size_t len = strlen(line);

    mas[c] = (char *)malloc((len + 1) * sizeof(char));
    if (mas[c] == NULL)
    {
        printf("Неизвестная ошибка!");
        return EXIT_FAILURE;
    }

    strncpy(mas[c], line, len);
    mas[c][len + 1] = '\0';
    return c + 1;
}
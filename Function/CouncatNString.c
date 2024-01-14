#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char* conCatString (int args_count, ...);

int main () {
    char* result = conCatString(4, "hi", " i am", " Mradul", " Lakhotiya");

    printf("%s", result);

    free(result);

    return 0;
}

char* conCatString (int args_count, ...) {
    va_list args;
    va_start(args, args_count);

    char* current_str;
    char* str = malloc(1);
    str[0] = '\0';

    size_t new_size;

    for (int i = 0; i < args_count; i++) {
        current_str = va_arg(args, char*);

        new_size = strlen(current_str) + strlen(str) + 1;

        str = realloc(str, new_size);

        strcat(str, current_str);
    }

    va_end(args);

    return str;
}
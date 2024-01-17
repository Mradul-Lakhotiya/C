#include <stdio.h>
#include <time.h>

int main() {
    time_t* ct;

    time(ct);

    printf("%s", ctime(ct));

    return 0;
}
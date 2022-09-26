#include <stdio.h>

int main() {
    char buf[16];

    printf("addr(buf): %p\n", buf);
    gets(buf);
    puts("good luck");

    return 0;
}

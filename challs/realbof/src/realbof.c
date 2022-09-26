#include <stdio.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    char buf[16];

    setup();

    printf("addr(buf): %p\n", buf);
    gets(buf);
    puts("good luck");

    return 0;
}

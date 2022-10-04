#include <stdio.h>

void setup() {
    // disregard this
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    char buf[16];

    setup();

    printf("address_of( char buf[16] ): %p\n", buf);
    gets(buf);
    puts("good luck");

    return 0;
}

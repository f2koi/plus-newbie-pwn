#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void setup() {
    // disregard this
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void win() {
    // call this function to get the flag!
    system("cat /home/plus/flag");
}

int vulnerable() {
    char name[0x20];
    printf("address_of( char name[0x20] ): %p\n", name);
    printf("pwn me: ");
    read(0, name, 0x28);
}

int main() {
    char dummy[0x10];
    setup();
    vulnerable();
}
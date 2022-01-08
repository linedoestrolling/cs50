#include <stdio.h>
#include <cs50.h>

int main(void) {
    string name = get_string("wat is your name my guud sir?");
    printf("Hello %s !\n", name);
}
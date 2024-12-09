#include <stdio.h>
#include <stdlib.h>

union aUnion {
    int a;
    double b;
    char c;
};

int main() {
    union aUnion thing;
    thing.a = 0;
    thing.b = 5.5;
    printf("%d", thing.a);
    printf("%f", thing.b);
    return 0;
}
#include <stdio.h>

void printInt(int x) {
    printf("%d", x);
}

int main() {
    int y;
    scanf("%d", &y);
    printInt(y);
    return 0;
}
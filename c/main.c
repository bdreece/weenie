#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, size_t n) {
    size_t i;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    size_t i, n = argc - 1;
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = atoi(argv[i + 1]);
    }

    bubble_sort(a, n);
    for (i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}

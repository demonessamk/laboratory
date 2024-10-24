#include <stdio.h>


void main() {
    FILE* file1, * file2;
    char now = '\0';
    char pred = '\0';
    int izm = 0;

    file1 = fopen("1.txt", "r");
    file2 = fopen("2.txt", "w");

    while ((now = fgetc(file1)) != EOF) {
        if (now == pred && !(now >= '0' && now <= '9') && now != '-' && now != '+') {
            izm = 1;
        }

        fputc(now, file2);
        pred = now;

        if (izm) {
            fputs("*", file2);
            fclose(file1);
            fclose(file2);
        }
    }
    printf("COMPLETED =)");
}
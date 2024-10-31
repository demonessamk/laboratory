#include <stdio.h>
#include <stdlib.h>

int main() {
    char* str = (char*)calloc(5, sizeof(char));
    char ch;
    int length = 0;
    int c = 5;

    while (1) {
        printf("vvedite simvol: ");
        ch = getchar();

        if (ch == '.') {
            break;
        }
        if (length == c) {
            c += 5;
            str = (char*)realloc(str, c * sizeof(char));
        }
        str[length] = ch; 
        length++;
        getchar(); 
    }
    str[length] = '\0'; 
    printf("vvedennaya stroka: %s\n", str);
    free(str); 
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void zapis(const char* filename, const char* str) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "%s", str);
    fclose(file);
}

char* read_from_file(const char* filename) {
    char* str = NULL;
    size_t size = 0;
    FILE* file = fopen(filename, "r");
    getline(&str, &size, file);
    fclose(file);

    return str;
}

int main() {
    char* str = NULL;
    char ch;
    int length = 0;
    while (1) {
        printf("vvedite simvol): ");
        ch = getchar();

        if (ch == '.') {
            break;
        }

        char* new_str = (char*)malloc((length + 1) * sizeof(char));
        if (str != NULL) {
            for (int i = 0; i < length; i++) {
                new_str[i] = str[i];
            }
            free(str);
        }

        new_str[length] = ch;
        str = new_str;
        length++;
        getchar(); 
    }

    str[length] = '\0'; 
    printf("vvedennaya stroka: %s\n", str);
    zapis("output.txt", str);
    char* file_str = read_from_file("output.txt");
    printf("stroka iz file: %s\n", file_str);

    free(str);      
    free(file_str); 
    return 0;
}

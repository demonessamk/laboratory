#include <stdio.h>
#include <stdlib.h>

    int main() {
        char* str = NULL;
        char ch;
        int length = 0;

        while (1) {
            printf("vvedite simvol");
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
        printf("vvedenaya stroka: %s\n", str);
        free(str); 
        return 0;
    }


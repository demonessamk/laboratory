#include <iostream>
#define strdup _strdup

int proverka(char c) {
	return(c >= '0' && c <= '9');
}
void dv(char str[]) {
	int i = 0, j = 0;
	int b = 0;
	while (str[i] != '\0') {
		if (i > 0 && !proverka(str[i]) && str[i] == str[i - 1] && str[i] != '+' && str[i] != '-') {
			b = 1;
			i++;
		}
		else {
			str[j++] = str[i++];
		}
	}
	str[j] = '\0';
	if (!b) {
		str[j++] = '*';
		str[j] = '\0';
	}
}
int main() {
	const char* stroka = "bhvfxfcgbjnkjmk";
	char* str = strdup(stroka);
	dv(str);
	printf("%s\n", str);
	return 0;
}
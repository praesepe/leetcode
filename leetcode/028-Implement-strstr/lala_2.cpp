#include <stdio.h>
#include <string.h>

int main() {
	const char* str = "ABCAB";
	int f[10] = {0};

	int j = 0;
	for (int i = 1; i < 9; i++) {
		while (str[j] != str[i] && j > 0) {
			j = f[j - 1];
		}

		if (str[j] == str[i]) {
			f[i] = j + 1;
			j++;
		}
	}


	for (int i = 0; i < 10; i++) {
		printf("%d\n", f[i]);
	}
	return 0;
}

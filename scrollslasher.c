#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE* input;

int width = 0;
int height = 0;
int charCounter = 0;
int lineCounter = 0;
int character = 0;

char* pre = "dc.b '";
char* post = "'";
char* separator = "dc.b -1";

int error(int type) {
	if (type == 0) {
		printf("Error: To few parameters, need 3\n");
	}
	else if (type == 1) {
		printf("Error: File not found\n");
	}
	else if (type == 2) {
		printf("Error: Malformed <width> and/or <height> parameters\n");
	}
	printf("Usage: scrollslasher <filename> <width> <height>\n");
	return 0;
}

int cleanup() {
	for (int x = charCounter; x < width; x++) {
		printf(" ");
	}
	printf("%s", post);
	printf("\n\n%s", separator);

	fclose(input);

	return 0;
}

int main(int argc, char* argv[]) {
	if (argc <= 3) {
		return error(0);
	}

	input = fopen(argv[1], "r");
	width = atoi(argv[2]);
	height = atoi(argv[3]);

	if (input == NULL) {
		return error(1);
	}

	if (width == 0 || height == 0) {
		return error(2);
	}

	while (character = fgetc(input)) {
		if (character == EOF) {
			return cleanup();
		}

		if (charCounter == 0) {
			printf("%s", pre);
		}

		printf("%c", toupper(character));
		charCounter++;

		if ((char)character == '\'') {
			printf("'");
		}

		if (charCounter == width) {
			printf("%s\n", post);
			charCounter = 0;
			lineCounter++;
		}

		if (lineCounter == height) {
			printf("\n%s\n\n", separator);
			lineCounter = 0;
		}

	}

}
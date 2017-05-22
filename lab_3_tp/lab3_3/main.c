#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showHelp() {
	printf("\n\n");
	printf("Folosire: ./criptare <enc/dec> <cheie> <text>");
	printf("\n\n");
}

void criptare(char *msg, int size, int key) {
	int i;

	for(i = 0; i < size; i++) {
		msg[i] = tolower(msg[i]);
		msg[i] += key;

		if(msg[i] < 0 || msg[i] > 'z') msg[i] -= ('z' - 'a');
	}
}

void decriptare(char *msg, int size, int key) {
	int i;

	for(i = 0; i < size; i++) {
		msg[i] -= key;

		if(msg[i] < 'a') msg[i] += ('z' - 'a');
	}
}

int main(int argc, char *argv[]) {
	if(argc > 3) {
		char mod[3];
		strcpy(mod, argv[1]);
		int key = atoi(argv[2]);
		int i;

		if(strcmp(mod, "enc") == 0) {
			for(i = 3; i < argc; i++) {
				char *m = malloc(strlen(argv[i]) * sizeof(char));
				strcpy(m, argv[i]);
				criptare(m, strlen(m), key);
				printf("%s ", m);
				free(m);
			}
		} else if(strcmp(mod, "dec") == 0) {
			for(i = 3; i < argc; i++) {
				char *m = malloc(strlen(argv[i]) * sizeof(char));
				strcpy(m, argv[i]);
				decriptare(m, strlen(m), key);
				printf("%s ", m);
				free(m);
			}
		} else {
			printf("\nMetoda gresita! Se accepta doar \"enc\" sau \"dec\"\n");
			exit(0);
		}
	} else {
		printf("\n\n");
		printf("Nu ati introdus destule argumente");
		showHelp();
	}

	printf("\n\n");

	return 0;
}

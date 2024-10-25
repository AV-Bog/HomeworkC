#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLENGTH 100

typedef struct entry {
	char name[MAXLENGTH];
	char number[MAXLENGTH];
} entry;

int readEntries(FILE* dataBase, entry colletion[]);
void printOption();
void addEntery(entry collection[], int *entryNumber);
void displayEntries(entry collection[], int entryNumber);
void searchByName(entry collection[], int entryNumber, char name[]);
void searchByNumber(entry collection[], int entryNumber, char number[]);
void saveEntries(entry collection[], int length, const char* fileName);

int main() {
	entry collection[100];
	FILE* dataBaseRead = fopen("dataBase.txt", "r");
	int entryNumber = readEntries(dataBaseRead, collection);
	fclose(dataBaseRead);
	int option = 0;

	do {
		printOption();
		scanf("%d", &option);
		
		switch (option) {
			case 0:
				continue;
			case 1:
				addEntery(collection, &entryNumber);
				break;
			case 2:
				displayEntries(collection, entryNumber);
				break;
			case 3:
				printf("Enter name:\t");
				char name[MAXLENGTH] = { '\0' };
				scanf("%s", name);
				searchByName(collection, entryNumber, name);
				break;
			case 4:
				printf("Enter number:\t");
				char number[MAXLENGTH];
				scanf("%s", number);
				searchByNumber(collection, entryNumber, number);
				break;
			case 5:
				saveEntries(collection, entryNumber, "dataBase.txt");
				break;
		}
	} while (option != 0);
	return 0;
}

int readEntries(FILE* dataBase, entry colletion[]) {
	int i = 0;
	char newName[MAXLENGTH] = { '\0' };
	char newNumber[MAXLENGTH] = { '\0' };

	while ((fscanf(dataBase, "%s", newName) != EOF) && (fscanf(dataBase, "%s", newNumber) != EOF)) {
		strcpy(colletion[i].name, newName);
		strcpy(colletion[i].number, newNumber);
		i++;
	}
	return i;
}

void printOption() {
	printf("\t*A phonebook*\n");
	printf("Options: \n");
	printf("0 - exit the phonebook\n");
	printf("1 - add a new entry\n");
	printf("2 - display all the entries\n");
	printf("3 - find the phone number by name\n");
	printf("4 - find the name by the phone number\n");
	printf("5 - save entries to the database\n");
	printf("\nEnter a corresponding digit to choose an option: \t");
}

void addEntery(entry collection[], int *entryNumber) {
	if (*entryNumber <= 99) {
		char newName[MAXLENGTH];
		char newNumber[MAXLENGTH];

		printf("enter the name: ");
		scanf("%s", &newName);
		printf("enter tne number: ");
		scanf("%s", &newNumber);

		strcpy(collection[*entryNumber].name, newName);
		strcpy(collection[*entryNumber].number, newNumber);

		(*entryNumber)++;
		printf("\n DONE \n");
	}
	else {
		printf("The limit is 100 entries!Can't write more!\n");
	}
}

void displayEntries(entry collection[], int entryNumber) {
	printf("All entries:\n");
	for (int i = 0; i < entryNumber; i++) {
		printf("%s %s\n", collection[i].name, collection[i].number);
	}
	printf("DONE\n");
}

void searchByName(entry collection[], int entryNumber, char name[]) {
	bool theRecordExists = false;
	for (int i = 0; i < entryNumber; i++) {
		if (strcmp(name, collection[i].name) == 0) {
			printf(collection[i].number);
			theRecordExists = true;
		}
	}
	if (theRecordExists == false) {
		printf("Unfortunately, the name number you entered is not in the phone book.");
	}
}

void searchByNumber(entry collection[], int entryNumber, char number[]) {
	bool theRecordExists = false; 
	for (int i = 0; i < entryNumber; i++) {
		if (strcmp(number, collection[i].number) == 0) {
			printf(collection[i].name);
			theRecordExists = true;
		}
	}
	if (theRecordExists == false) {
		printf("Unfortunately, the phone number you entered is not in the phone book.");
	}
}

void saveEntries(entry collection[], int length, const char* fileName) {
	FILE* dataBase = fopen(fileName, "w");
	for (int i = 0; i < length; i++) {
		fprintf(dataBase, "%s %s\n", collection[i].name, collection[i].number);
	}
	printf("Entries are saved!\n");
	fclose(dataBase);
}
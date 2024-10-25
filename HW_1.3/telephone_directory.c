#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#pragma once

#define strLength 100

typedef struct entry {
	char name[strLength];
	char number[strLength];
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
		int rez = scanf("%d", &option);
		
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
				printf("name?\t");
				char name[strLength] = { '\0' };
				int rez2 = scanf("%s", name);
				searchByName(collection, entryNumber, name);
				break;
			case 4:
				printf("number?\t");
				char number[strLength];
				int rez3 = scanf("%s", number);
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

	char newName[strLength] = { '\0' };
	char newNumber[strLength] = { '\0' };

	while ((fscanf(dataBase, "%s", newName) != EOF) && (fscanf(dataBase, "%s", newNumber) != EOF)) {
		strcpy(colletion[i].name, newName);
		strcpy(colletion[i].number, newNumber);
		i++;
	}

	return i;
}
//int readEntries(FILE* dataBase, entry collection[]) {
//	int i = 0;
//	char newName[strLength];
//	char newNumber[strLength];
//	while (fscanf_s(dataBase, "%s", newName, 5) != EOF && fscanf_s(dataBase, "%s", newNumber, 11) != EOF) {
//		int rez1 = strcpy_s(collection[i].name, newName, 100);
//		int rez = strcpy_s(collection[i].number, newNumber, 100);
//		i++;
//	}
//	return i;

void printOption() {
	printf("\n*A phonebook*\n");
	printf("Options: \n");
	printf("0 - exit the phonebook\n");
	printf("1 - add a new entry\n");
	printf("2 - display all the entries\n");
	printf("3 - find the phone number by name\n");
	printf("4 - find the name by the phone number\n");
	printf("5 - save entries to the database\n");
	printf("Enter a corresponding digit to choose an option: ");
}

void addEntery(entry collection[], int *entryNumber) {
	if (*entryNumber <= 99) {
		char newName[strLength];
		char newNumber[strLength];

		printf("enter the name: ");
		int rez1 = scanf("%s", &newName);
		printf("enter tne number: ");
		int rez2 = scanf("%s", &newNumber);

		int rez6 = strcpy(collection[*entryNumber].name, newName);
		int rez7 = strcpy(collection[*entryNumber].number, newNumber);

		(*entryNumber)++;

		printf("\n DONE \n");
	}
	else printf("The limit is 100 entries!Can't write more!\n");
}

void displayEntries(entry collection[], int entryNumber) {
	printf("all zapisi\n");

	for (int i = 0; i < entryNumber; i++) {
		printf("%s %s\n", collection[i].name, collection[i].number);
	}

	printf("DONE\n");
}

void searchByName(entry collection[], int entryNumber, char name[]) {
	bool flag = false; //фоаг - найден ли номер с таким именем
	for (int i = 0; i < entryNumber; i++) {
		if (strcmp(name, collection[i].name) == 0) {
			printf(collection[i].number);
			flag = true;
		}
	}
	if (flag == false) {
		printf("soryy!");
	}
}

void searchByNumber(entry collection[], int entryNumber, char number[]) {
	bool flag = false; //фоаг - найден ли номер с таким именем
	for (int i = 0; i < entryNumber; i++) {
		if (strcmp(number, collection[i].number) == 0) {
			printf(collection[i].name);
			flag = true;
		}
	}
	if (flag == false) {
		printf("soryy!");
	}
}

void saveEntries(entry collection[], int length, const char* fileName) {
	FILE* dataBase = fopen(fileName, "w");
	for (int i = 0; i < length; i++) {
		fprinf(dataBase, "%s %s\n", collection[i].name, collection[i].number);
	}
	printf("Entries are saved!\n");
	fclose(dataBase);
}
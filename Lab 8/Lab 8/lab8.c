#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ITEM 5
#define LENGTH 11

int validateString(char* str, int size);
void myflush();
void sortString(char string[ITEM][LENGTH], int* id, int size);
void getString(char* str, int size);

void main()
{
	printf("Please enter items names\n");

	int itemId[ITEM];
	char itemName[ITEM][LENGTH];

	int i = 0;
	for (i = 0; i < ITEM; i++) {
		itemId[i] = i;
	}

	for (i = 0; i < ITEM; i++) {
		printf("Item %d: ", i + 1);
		getString(itemName[i], LENGTH);
	}
	printf("\n");

	for (int i = 0; i < ITEM; i++) {
		printf("%d - %s\n", itemId[i], itemName[itemId[i]]);
	}

	sortString(itemName, itemId, ITEM);

	printf("\n");
	printf("Sorting...\n");
	printf("\n");

	for (int i = 0; i < ITEM; i++) {
		printf("%d - %s\n", itemId[i], itemName[itemId[i]]);
	}


	myflush();


}
int stringlength(char str[])
{
	int i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;

}

int validateString(char* str, int size)
{

	int ret = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		if (str[i] == 32)			ret = 1;
		else if ((str[i] >= 48) && (str[i] <= 57))
			ret = 1;
		else if ((str[i] >= 65) && (str[i] <= 90))
			ret = 1;
		else if ((str[i] >= 97) && (str[i] <= 122))
			ret = 1;
		else if (str[i] == '\0')
			return 1;
		else
			return 0;
	}
	return ret;
}

void getString(char* str, int size)
{
	scanf("%10[^\n]", str);
	myflush();

	while (validateString(str, size) == 0) {
		printf("Invailed, try again: ");
		scanf("%10[^\n]", str);
		myflush();
	}
}




void seedRandFunc()
{
	int curTime = (int)time(0);
	srand(curTime);
}

void myflush()
{
	while (getchar() != '\n');
}

void scanInt(int* iVal)
{
	while (scanf("%d", iVal) == 0) {
		printf("Invailid input ");
		myflush();
	}
	myflush();
}

void sortString(char string[ITEM][LENGTH], int* id, int size)
{
	char tmpStr[ITEM][LENGTH];
	(tmpStr, string, sizeof(tmpStr));

	int i = 0, j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {



			char ch1 = tmpStr[j][0];
			char ch2 = tmpStr[j + 1][0];

			if (ch1 >= 97)	ch1 -= 32;
			if (ch2 >= 97)	ch2 -= 32;


			int swap = 0;
			char swapChar[10] = { 0 };

			if (ch1 > ch2) {
				swap = id[j];
				id[j] = id[j + 1];
				id[j + 1] = swap;

				*swapChar = *tmpStr[j];
				*tmpStr[j] = *tmpStr[j + 1];
				*tmpStr[j + 1] = *swapChar;


			}
		}
	}

}


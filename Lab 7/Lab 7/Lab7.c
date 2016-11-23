#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define item 5

int findItem(int itemId[], int arSize, int id)
{

	int i = 0;
	for (i = 0; i < arSize; i++) {
		if (itemId[i] == id)
			return i;
	}
	return -1;
}

int addItem(int itemId[], int itemCnt[], int arSize, int addId)
{
	int i = 0;
	int totalcnt = 0;
	for (i = 0; i < arSize; i++) {
		totalcnt += itemCnt[i];
	}

	if (totalcnt >= 4) {
		printf("\nYou can't hold anymore types of items!\n");
		return 0;
	}


	int id = findItem(itemId, arSize, addId);

	if (id == -1) {
		for (i = 0; i<arSize; i++) {
			if (itemCnt[i] == 0) {
				itemId[i] = addId;
				itemCnt[i] = 1;
				printf("\nNew Item is added!\n");
				return 1;
			}
		}
	}
	else {
		itemCnt[id]++;
		printf("\nItem quantity is increased!\n");
	}
	return 1;
}

int useItem(int itemId[], int itemCnt[], int arSize, int useId)
{
	int id = findItem(itemId, arSize, useId);
	if (id == -1) {
		printf("There is no item.\n");
		return 0;
	}
	else {
		if (itemCnt[id]>0) {
			itemCnt[id]--;
			printf("Item is used.\n");
			return 1;
		}
		else {
			printf("You dont have that item.\n");
			return 0;
		}
	}
}

void printItem(int id)
{

	switch (id) {
	case 0:
		printf("0-Potion ");
		break;
	case 1:
		printf("1-HP Booster ");
		break;
	case 2:
		printf("2-Strength Booster ");
		break;
	case 3:
		printf("3-Defense Booster ");
		break;
	case 4:
		printf("4-Intelligence Booster ");
		break;
	}
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

void wait_for_enter()
{

	char ch = 0;
	while (1) {
		scanf("%c", &ch);

		if (ch == '\n')
			break;
	}
}


void main()
{
	int curTime = (int)time(0);
	srand(curTime);

	int itemId[item] = { 0 };
	int itemCnt[item] = { 0 };


	int selMenu = 0;
	int selItem = 0;
	int addCnt = 0;
	int i = 0;

	do {

		printf("\n1. Get New Item\n");
		printf("2. Show Inventory\n");
		printf("3. Use Item\n");
		printf("4. Quit\n");

		printf("\nSelect Option: ");
		scanInt(&selMenu);

		switch (selMenu) {
		case 1:
		{
				  int addId = rand() % item;
				  addItem(itemId, itemCnt, item, addId + 1);
		}
			break;
		case 2:
			printf("\n");
			addCnt = 0;
			for (i = 0; i<item; i++) {
				if (itemCnt[i] > 0) {
					printItem(itemId[i] - 1);
					printf("x %d\n", itemCnt[i]);
					addCnt++;
				}
			}

			if (addCnt == 0) {
				printf("There are no items in inventory\n");
			}


			break;
		case 3:

			printf("Select Item ");
			scanInt(&selItem);
			useItem(itemId, itemCnt, item, selItem + 1);
			break;
		}

	} while (selMenu != 4);

}
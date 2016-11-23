#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NUM_CHAR 20
#define ITEM_NAME 20

void flush()
{
	while (getchar() != '\n');
}
struct Player {
	int iLvl, iStr, iSpd, iDef, intel, iLuck, maxHp, curHP;
	char name[NUM_CHAR];
};

struct Item {
	char itemName[ITEM_NAME];
	int itemType, itemPower;
};

struct Item loadItem()
{
	struct Item data_item;
	printf("Please enter the following Item info:\n");
	printf("Name: ");
	scanf("%s", &data_item.itemName);
	flush();
	printf("Type:");
	scanf("%d", &data_item.itemType);
	flush();
	printf("Power:");
	scanf("%d", &data_item.itemPower);
	flush();


	return data_item;

}

struct Player loadPlayer()
{

	struct Player data_object;

	printf("Please enter the following player info:\n");
	printf("Name: ");
	scanf("%s", &data_object.name);
	flush();
	printf("Level:");
	scanf("%d", &data_object.iLvl);
	flush();
	printf("Strength:");
	scanf("%d", &data_object.iStr);
	flush();
	printf("Speed:");
	scanf("%d", &data_object.iSpd);
	flush();
	printf("Defense:");
	scanf("%d", &data_object.iDef);
	flush();
	printf("Intelligence:");
	scanf("%d", &data_object.intel);
	flush();
	printf("Luck:");
	scanf("%d", &data_object.iLuck);
	flush();
	printf("Max HP:");
	scanf("%d", &data_object.maxHp);
	flush();

	return data_object;

}

void printData(struct Player p1, struct Item* itemList, int listSize)
{
	int i = 0;

	printf("Collected input:\n\n");
	printf("Name	Lvl	Str	Spd	Def	Int	Lck	MHP\n");
	printf("%s	%d	%d	%d	%d	%d	%d	%d\n\n", p1.name, p1.iLvl, p1.iStr, p1.iSpd, p1.iDef, p1.intel, p1.iLuck, p1.maxHp);
	for (i = 0; i < listSize; i++) {
		printf("Name:	Type:	Power:\n");
		printf("%s	%d	%d\n", itemList[i].itemName, itemList[i].itemType, itemList[i].itemPower);

	}
}

int main()
 {
	struct Player p2 = loadPlayer();

	struct Item loadItem();
	struct Item loadItem();

	struct Item itemList3[2];

	itemList3[2] = loadItem(), loadItem();

	
	printData(p2, &itemList3, 2);



	getchar();
	getchar();
}
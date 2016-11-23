#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myString {
	char str[11];
};

struct Player {
	int lvl, str, spd, def, intl, lck, mhp, hp;
	struct myString name;
};

struct Item {
	struct myString name;
	int type;
	int power;
};

struct Item loadItem();
struct Player loadPlayer();
void printData(struct Player p1, struct Item* itemList, int listSize);
int validateString(char* str, int size);
void myflush();
void sortString(struct myString* str, int* id, int size);
int saveGame(struct Player player, int exp, int nextLvl,
float days, struct Item* inventory, int* quantities, int inventorySize);
int loadSaveGame(struct Player* player, int* exp, int* nextLvl, float* days,
struct Item* inventory, int* quantities, int inventorySize);

void main()
{
	struct Player p1;
	strcpy(p1.name.str, "Tester");
	p1.str = 10;
	p1.def = 20;
	p1.spd = 30;
	p1.intl = 40;
	p1.lvl = 5;
	p1.mhp = 50;
	p1.hp = 15;
	p1.lck = 33;

	float days = 12;
	int nextLvl = 15;
	int exp = 24;

	struct Item it[2];
	strcpy(it[0].name.str, "item1");
	strcpy(it[1].name.str, "item2");

	it[0].type = 3;
	it[1].type = 2;

	it[0].power = 40;
	it[1].power = 20;

	int qnt[2] = { 12, 34 };

	saveGame(p1, exp, nextLvl, days, it, qnt, 2);

	struct Player p2 = { 0 };
	struct Item i2[2] = { 0 };
	int q2[2] = { 0 };

	exp = days = nextLvl = 0;

	while (!loadSaveGame(&p2, &exp, &nextLvl, &days, i2, q2, 2));

	printf("\n%s %d %d %d %d %d %d %d %d\n%s %d %d\n%s %d %d\
		   		   \n%d %d\n%d %d %.1f", p2.name.str, p2.str, p2.def, p2.intl, p2.spd,
				   p2.lck, p2.lvl, p2.hp, p2.mhp, i2[0].name.str, i2[0].type,
				   i2[0].power, i2[1].name.str, i2[1].type, i2[1].power, q2[0],
				   q2[1], exp, nextLvl, days);

	getchar();
	getchar();
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
		if (str[i] == 32)
			ret = 1;			
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

void myflush()
{
	while (getchar() != '\n');
}


void sortString(struct myString* str, int* id, int size)
{

	int i = 0, j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {

			char ch1 = str[id[j]].str[0];
			char ch2 = str[id[j + 1]].str[0];

			if (ch1 >= 97)	ch1 -= 32;
			if (ch2 >= 97)	ch2 -= 32;


			int swap = 0;
			char swapChar[10] = { 0 };

			if (ch1 > ch2) {
				swap = id[j];
				id[j] = id[j + 1];
				id[j + 1] = swap;
			}
		}
	}
}





struct Player loadPlayer()
{

	struct Player player;

	printf("Please enter the following player info:\n");
	printf("Name: ");
	scanf("%10[^\n]", player.name.str);
	myflush();

	printf("Level: ");
	scanf("%d", &player.lvl);
	myflush();


	printf("Strength: ");
	scanf("%d", &player.str);
	myflush();

	printf("Speed: ");
	scanf("%d", &player.spd);
	myflush();


	printf("Defense: ");
	scanf("%d", &player.def);
	myflush();

	printf("Intelligence: ");
	scanf("%d", &player.intl);
	myflush();

	printf("Luck: ");
	scanf("%d", &player.lck);
	myflush();

	printf("Max HP: ");
	scanf("%d", &player.mhp);
	myflush();

	player.hp = 0;

	return player;
}

struct Item loadItem()
{
	struct Item item;

	printf("\n");
	printf("Please enter the following item info:\n");
	printf("Name: ");
	scanf("%10[^\n]", item.name.str);
	myflush();

	printf("Type: ");
	scanf("%d", &item.type);
	myflush();

	printf("Power: ");
	scanf("%d", &item.power);

	return item;
};


void printData(struct Player p1, struct Item* itemList, int listSize)
{
	int i = 0;
	printf("\n");
	printf("Name	Lvl	Str	Spd	Def	Int	Lck	MHP\n");
	printf("%s	%d	%d	%d	%d	%d	%d	%d\n",
		p1.name.str, p1.lvl, p1.str, p1.spd,
		p1.def, p1.intl, p1.lck, p1.mhp);

	printf("\n");

	printf("Name	Type	Power\n");
	for (i = 0; i < listSize; i++) {
		printf("%s	%d	%d\n", itemList[i].name.str, itemList[i].type, itemList[i].power);
	}
}




int saveGame(struct Player player, int exp, int nextLvl, float days, struct Item* inventory,
	int* quantities, int inventorySize)
{
	int i = 0;
	char filename[20] = { 0 };
	printf("Enter filename to write: ");
	scanf("%s", filename);

	FILE* fp = NULL;
	fp = fopen(filename, "w");
	if (fp != NULL) {

		fprintf(fp, "%s,%d,%d,%d,%d,%d,%d,%d,%d,",
			player.name.str, player.str, player.def, player.intl, player.spd,
			player.lck, player.lvl, player.hp, player.mhp);

		for (i = 0; i < inventorySize; i++)
			fprintf(fp, "%s,%d,%d,", inventory[i].name.str, inventory[i].type, inventory[i].power);

		for (i = 0; i < inventorySize; i++)
			fprintf(fp, "%d,", quantities[i]);


		fprintf(fp, "%d,%d,%.1f", exp, nextLvl, days);

		fclose(fp);
		return 1;
	}
	else {
		printf("Error in filename\n");
		return 0;
	}


}


int loadSaveGame(struct Player* player, int* exp, int* nextLvl, float* days, struct Item* inventory, int* quantities, int inventorySize)
{
	int i = 0;
	char filename[20] = { 0 };
	printf("Enter filename to read: ");
	scanf("%s", filename);

	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d,",
			player->name.str, &player->str, &player->def, &player->intl, &player->spd,
			&player->lck, &player->lvl, &player->hp, &player->mhp);


		for (i = 0; i < inventorySize; i++)
			fscanf(fp, "%[^,],%d,%d,", inventory[i].name.str, &inventory[i].type, &inventory[i].power);

		for (i = 0; i < inventorySize; i++)
			fscanf(fp, "%d,", &quantities[i]);


		fscanf(fp, "%d,%d,%f", exp, nextLvl, days);

		fclose(fp);
		return 1;
	}
	else {
		printf("Invalid save file!\n");
	}

	return 0;
}

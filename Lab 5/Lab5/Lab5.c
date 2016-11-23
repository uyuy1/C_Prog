#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fight(int *fcurrenthp)
{
	*fcurrenthp = 0;
	printf("He's too strong!\n\n");
	printf("Game Over!\n");
	return 0;
}

int train(float *tdaysremain, int *thpremain, int *tplayerexp)
{
	*tplayerexp += 10;
	*tdaysremain -= .5;
	*thpremain -= 2;
	printf("You did some training!\n\n");
	return 0;

}


int refill(int *currenthp, float *daysremain, int *maxHP)
{
	*maxHP = 10;
	*currenthp = *maxHP; // refil to maximum
	*daysremain -= 1; // decreases the number of days remaining by one

	printf("You rested up at the inn\n\n");
	return 0;

}
int main()
{
	int select = 0;
	int maxHP = 10;
	float daysremain = 8.0f;
	int HP = 10;
	int exp = 0;
	printf("Days remaining:%.2lf HP:%d EXP: %d\n\n", daysremain, maxHP, exp);
	do
	{
		printf("1 - Rest at Inn\n");
		printf("2 - Train\n");
		printf("3 - Fight the Demon Lord\n");
		printf("4 - Quit Game\n");
		printf("Select: ");
		scanf("%d", &select);
		fflush(stdin);
		if (select == 1){//Select to rest
			refill(&HP, &daysremain, &maxHP);
			printf("Days remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		if (select == 2){//Select to train
			train(&daysremain, &maxHP, &exp);
			printf("Days Remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		if (select == 3){//Select to Fight//
			fight(&maxHP);
			printf("Days Remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
	} while (select != 4);
}
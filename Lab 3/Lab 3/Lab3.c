// This is the third code
// By Sanghun Kim
// codeQuest.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float attack_power(float _attack, float _defense)
{
	return (_attack / _defense)*5.0f;
}

float magic_power(float _attack, float _defense)
{
	return (_attack / _defense)*5.0f;
}

int input_attack()
{
	int iInputMove = 0;
	do {
		printf("1 - Attack\n");
		printf("2 - Magic\n\n");
		printf("Select your move: ");	scanf("%d", &iInputMove);
		fflush(stdin);
		if ((iInputMove < 1) || (iInputMove >2)) {  // Exeption: when user does not select 1 or 2, show error message
			printf("\nYou selected wrong number! Please select 1 or 2\n\n");
		}
	} while ((iInputMove < 1) || (iInputMove >2));

	return iInputMove;
}

int main() // Here is start point
{
	// palyer stat variables //
	float fPlyerStrength = 10;
	float fPlerDefence = 20;
	float fPlyerIntelli = 40;
	int iPlayerHP = 10;

	// enemy stat variables //
	float fEnemyStrength = 30;
	float fEnemyDefence = 40;
	float fEnemyIntelli = 25;
	int iEnemyHP = 10;
	int iInputMove = 0;	// input variables //

	printf("Battle Start!\n\n");
	do {
		// Player attack enemy================================//
		printf("Your HP: %d Enemy HP: %d\n\n", iPlayerHP, iEnemyHP);
		iInputMove = input_attack();

		if (iInputMove == 1) {		// If the user select "1"
			printf("\nYou attacked the enemy!\n");
			iEnemyHP = (int)((float)iEnemyHP - attack_power(fPlyerStrength, fEnemyDefence));
		}
		else if (iInputMove == 2) {	// if the user select "2" 
			printf("\nYou shocked the enemy!\n");
			iEnemyHP = (int)((float)iEnemyHP - magic_power(fPlyerIntelli, fEnemyIntelli));
		}

		// Enemy attack player=================================//
		if (iEnemyHP <= 0) {		// if enemy up is less than "0"
			printf("You won!\n");
		}
		else {	// enemy attack player
			printf("The enemy attacked you!\n\n");
			iPlayerHP = (int)((float)iPlayerHP - attack_power(fEnemyStrength, fPlerDefence));
			if (iPlayerHP <= 0) {
				printf("You died!\n");
			}
		}
	} while ((iPlayerHP > 0) && (iEnemyHP > 0));

	fflush(stdin);
	getchar();
	return 0;
}
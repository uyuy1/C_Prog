#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _WINDOWS
#define item 5

float attack_power(float _attack, float _defense);
float magic_power(float _attack, float _defense);
int input_attack();
void myfflush();
void clear_screen();
int new_game();
int load_game();
void exit_game();
void wait_for_enter();
int main_menu();
int fight(int *fcurrenthp);
int train(float *tdaysremain, int *thpremain, int *tplayerexp);
int refill(int *currenthp, float *daysremain, int *maxHP);
void battleSequence(float* days, int* curHP, int* exp, int maxHP, int str, int def, int intel, int luck);
int seed();
float RandomFloat(float a, float b);
void garbage();




int main(void)
{
	printf("+-----------------------+\n");
	printf("|                       |\n");
	printf("|      CODE QUEST       |\n");
	printf("|                       |\n");
	printf("+-----------------------+\n");

	int iSelectNum = 0;
	do {

		getchar();
		wait_for_enter();
		clear_screen();

		iSelectNum = main_menu();
		switch (iSelectNum)
		{
		case 1:
			new_game();
			break;
		case 2:
			load_game();
			break;
		case 3:
			exit_game();
			break;
		default:
			break;
		}
	} while (iSelectNum != 3);

	wait_for_enter();
	return 0;
}

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

void myfflush()
{
#ifdef _WINDOWS
	fflush(stdin);
#else
	__fpurge(stdin);
#endif


}

void clear_screen()
{
	int i = 0;
	for (i = 0; i < 40; i++) {
		printf("\n");
	}
	printf("Clear Screen\n");
}

int new_game()
{
	// Input variable //
	float fSpeed = 0;
	float fDefense = 0;
	float fStrength = 0;
	float fIntelligence = 0;

	// Output variable //
	int iStrength = 0, iSpeed = 0, iDefense = 0, iIntelligence = 0, iLuck = 0;

	// Input=======================================================//
	printf("Please enter your desired stats for our charcter:\n\n");
	printf("Enter strength:");     scanf("%f", &fStrength);
	printf("Enter speed:");     scanf("%f", &fSpeed);
	printf("Enter defense:");     scanf("%f", &fDefense);
	printf("Enter intelligence: ");     scanf("%f", &fIntelligence);

	// Calculate properties========================================//
	float fSum = fStrength + fSpeed + fDefense + fIntelligence;

	// ratio //
	fStrength /= fSum;
	fSpeed /= fSum;
	fDefense /= fSum;
	fIntelligence /= fSum;

	// final stats //
	iStrength = (int)(fStrength * 100.0f);
	iSpeed = (int)(fSpeed * 100.0f);
	iDefense = (int)(fDefense * 100.0f);
	iIntelligence = (int)(fIntelligence * 100);
	iLuck = (int)fSum % 30;

	// Output======================================================//
	printf("\nYour player's final states are: \n\n");
	printf("strength:       %d \n", iStrength);
	printf("Speed:          %d \n", iSpeed);
	printf("Defence:        %d \n", iDefense);
	printf("Intelligence:   %d \n", iIntelligence);
	printf("Luck:           %d \n", iLuck);

	int select = 0;
	int maxHP = 10;
	float daysremain = 7.9f;
	int HP = 10;
	int exp = 0;

	int selMenu = 0;
	printf("Days remaining:%.2lf HP:%d EXP: %d\n\n", daysremain, maxHP, exp);
	do
	{
		printf("1 - Rest at Inn\n");
		printf("2 - Train\n");
		printf("3 - Fight the Demon Lord\n");
		printf("4 - Battle Monster\n");
		printf("5 - Quit Game\n");
		printf("Select: ");
		scanf("%d", &select);
		fflush(stdin);
		if (select == 1) {//Select to rest
			refill(&HP, &daysremain, &maxHP);
			printf("Days remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		if (select == 2) {//Select to train
			train(&daysremain, &maxHP, &exp);
			printf("Days Remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		if (select == 3) {//Select to Fight//
			fight(&maxHP);
			printf("Days Remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		if (select == 4) {//Select to Fight//
			battleSequence(&daysremain, &HP, &exp, maxHP, iStrength, iDefense, iIntelligence, iLuck);
			printf("Days Remaining:%.2lf HP:%d EXP:%d\n\n", daysremain, maxHP, exp);
		}
		
	} while (select != 5);

	return 0;
}

int load_game()
{
	printf("Not implemented!");
	return 0;
}

void exit_game()
{
	myfflush();
	printf("Good bye!");
}

void wait_for_enter()
{
	char ch = 0;
	while (1) {
		scanf("%c", &ch);
		if (ch == 10)
			break;
	}
}

int main_menu()
{
	int iSelectNum = 0;
	printf("--Main Menu--\n\n");

	printf("1- New Game\n");
	printf("2- Load Game\n");
	printf("3- Exit\n");

	printf("\nSelect: ");
	scanf("%d", &iSelectNum);
	myfflush();

	while (iSelectNum < 1 && iSelectNum>3) {
		printf("Invalid input, try again ");
		scanf("%d", &iSelectNum);
		myfflush();
	}

	return iSelectNum;
}

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

void battleSequence(float* days, int* curHP, int* exp, int maxHP, int str, int def, int intel, int luck)
{
	
	int Elvl = 0;
	float Estr = 1.0f, Espd = 1.0f, Eintel = 1.0f;
	float Edef = 1.0f, EiratioHP1 = 0.5f, EiratioHP2 = 2.0f;
	float iratio = 0.5f, iratio2 = 0.15f;
	int select = 1;
	Elvl = rand() % 20 + 1;
	Estr = RandomFloat(iratio, iratio2)*Elvl*Elvl;
	Espd = RandomFloat(iratio, iratio2)*Elvl*Elvl;
	Edef = RandomFloat(iratio, iratio2)*Elvl*Elvl;
	Eintel = RandomFloat(iratio, iratio2)*Elvl*Elvl;


	// palyer stat variables //
	int iPlayerHP = 10;
	int EHP = 10;

	int iInputMove = 0;	
	int iInputeMove2 = 0;// input variables //

	printf("Battle Start!\n\n");
	do {
		// Player attack enemy================================//
		printf("Your HP: %d Enemy HP: %d\n\n", iPlayerHP, EHP);
		iInputMove = input_attack();

		if (iInputMove == 1) {		// If the user select "1"
			printf("\nYou attacked the enemy!\n");
			EHP = (int)((float)EHP - attack_power(str, def));
		}
		else if (iInputMove == 2) {	// if the user select "2" 
			printf("\nYou shocked the enemy!\n");
			EHP = (int)((float)EHP - magic_power(intel, Eintel));
		}

		seed();

		iInputeMove2 = rand() % 2 + 1;

		// ENEMY attack YOU================================//
		printf("Your HP: %d Enemy HP: %d\n\n", iPlayerHP, EHP);

		if (iInputeMove2 == 1) {		// If the user select "1"
			printf("Enemy attacked you!\n");
			iPlayerHP = (int)((float)iPlayerHP - attack_power(Estr, Edef));
		}
		else if (iInputeMove2 == 2) {	// if the user select "2" 
			printf("Enemy shocked you!\n");
			iPlayerHP = (int)((float)iPlayerHP - magic_power(Eintel, intel));
		}

		// Enemy attack player=================================//
		if (EHP <= 0) {		// if enemy up is less than "0"
			printf("You won!\n");
		}

		if (iPlayerHP <= 0) {
			printf("You Died!\n");
			fight(&iPlayerHP);
		}

	} while ((iPlayerHP > 0) && (EHP > 0));

	

	fflush(stdin);
	getchar();
	getchar();

}

int seed()
{
	srand((unsigned int)time(NULL));
	return 0;
}

float RandomFloat(float a, float b)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;

}

void garbage()
{
	while (getchar() != '\n');
}
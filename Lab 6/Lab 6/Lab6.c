#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

int main()
{
	
	int lvl = 0;
	float str = 1.0f, spd = 1.0f, intel = 1.0f, HP = 0.0f;
	float def = 1.0f, iratioHP1 = 0.5f, iratioHP2 = 2.0f;
	float iratio = 0.5f, iratio2 = 0.15f;
	int select = 1;
		lvl = rand() % 20 + 1;
		str = RandomFloat(iratio, iratio2)*lvl*lvl;
		spd = RandomFloat(iratio, iratio2)*lvl*lvl;
		def = RandomFloat(iratio, iratio2)*lvl*lvl;
		intel = RandomFloat(iratio, iratio2)*lvl*lvl;
		HP = RandomFloat(iratioHP1, iratioHP2)*lvl*lvl;
		seed();
		printf("Enemy Generator\n\n");
		printf("Level       -%d\n", (int)lvl);
		printf("HP          -%d\n", (int)HP);
		printf("Strength    -%d\n", (int)str);
		printf("Speed       -%d\n", (int)spd);
		printf("Defence     -%d\n", (int)def);
		printf("Intelligence-%d\n\n", (int)intel);
		do{
			printf("Generate Another? ");
			scanf("%d", &select);
			garbage();
			if (select <= 0 || select > 2){
				printf("Invalid Input!\n");
			}
		} while ((select <= 1) || (select > 2));
	} while (select !=2);

	

}
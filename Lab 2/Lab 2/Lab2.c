// This is the second code
// By Sanghun Kim
// codeQuest.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() // Here is start point
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
	printf("Enter strength:         ");     scanf("%f", &fStrength);
	printf("Enter speed:            ");     scanf("%f", &fSpeed);
	printf("Enter defense:          ");     scanf("%f", &fDefense);
	printf("Enter intelligence:     ");     scanf("%f", &fIntelligence);

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

	fflush(stdin);
	getchar();

	return 0;
}

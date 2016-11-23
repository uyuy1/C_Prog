
/*Riko Angeles - raangeles - IPC144 - 027123157*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int numofdays = 0;
	int i;
	char scp;
	double hightemp = 0, lowtemp = 0, avetemp = 0, totalavetemp = 0;

	printf("Weather Analyzer\n\n");
	printf("==================\n\n");
	while (numofdays <= 0) {
		printf("Please enter a positive number of days: ");
		scanf("%d", &numofdays);
		fflush(stdin);							//invokes undefined behaviour//
	}
	for (i = 0; i < numofdays; i++)				//iteration for number of days//
	{
		printf("Enter today's high: ");
		scanf(" %lf", &hightemp);
		fflush(stdin);
		printf("Enter today's low: ");
		scanf(" %lf", &lowtemp);
		fflush(stdin);

		avetemp = (hightemp + lowtemp) / 2;	//Solution for solving average temp//

		printf("Enter today's condition (s: sunny, c: cloudy, p: precipitation): ");
		scanf(" %c", &scp);
		fflush(stdin);
		printf("Today's average temperature is: %.2lf\n", avetemp);

		if (scp == 's') {					//Conditions code for Sunny, Cloudy, Precipitation//
			printf("@@@@@@@@@@@@@@@@@@@@\n");
		}
		else if (scp == 'c') {
			printf("~~~~~~~~~~~~~~~~~~~~\n");
		}
		else if (scp == 'p'&&avetemp <= 0) {
			printf("********************\n");
		}
		else if (scp == 'p'&&avetemp > 0) {
			printf(";;;;;;;;;;;;;;;;;;;;\n");
		}

		totalavetemp += avetemp;
	}
	//Solution for getting the total temperature of the average temperature based on number of days//
	printf("Average for all %d day(s) is: %.2f degrees", numofdays, totalavetemp / numofdays);
	getchar();
	getchar();
}

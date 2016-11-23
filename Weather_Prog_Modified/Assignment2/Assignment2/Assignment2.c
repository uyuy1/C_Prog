/*Riko Angeles - raangeles - IPC144 - 027123157*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 

int getInteger(int min, int max);
void getDailyData(float* high, float* low, char * condition);
void draw(char c, int num);
float average(float first, float second);
void displayResult(int days, float allDaysAverage);
char symbolToDraw(char condition, float averageTemperature);
void clrinput();

int main(void){
	int numDays;
	int i;
	float sum = 0;
	float dailyHigh;
	float dailyLow;
	char conditions;
	float dailyAvg = 0;

	printf("Weather Analyzer 2.0\n");
	printf("====================\n");
	printf("How many days of data?");
	numDays = getInteger(1, 14);
	for (i = 0; i < numDays; i++){
		getDailyData(&dailyHigh, &dailyLow, &conditions);
		dailyAvg = average(dailyHigh, dailyLow);
		printf("Today's average temperature is: %.2f\n", dailyAvg);
		sum += dailyAvg;
		draw(symbolToDraw(conditions, dailyAvg), 20);
	}
	displayResult(numDays, (sum / numDays));
	getchar();
	return 0;
}

int getInteger(int min, int max)	//Number of days,displays an error if enter invalid input//
{
		 int ave;
	do{
		scanf("%d", &ave);
		clrinput();
		if (ave < min){
			printf("Error! Try again!");
		}
		if (ave > max){
			printf("Error! Try again!");
		}
	} while (ave > max || ave < min);
	
	return ave;
}

void getDailyData(float* high, float* low, char * condition) //Prompts input user. accepts 2 floats and condition//
{

	do{
		*high = 0;
		*low = 1;
		*condition = 0;
		printf("\nEnter today's high, low, and condition \n(c=cloudy, s=sunny, p=precipitation)separated by commas :");
		scanf("%f,%f,%c", high,low,condition);
		clrinput();
		if ((*high < *low) || (*condition != 'c' && *condition != 'p' && *condition != 's')){
			printf("Error! Try again!\n");
		}
		
	} while ((*high < *low) || (*condition != 'c' && *condition != 'p' && *condition != 's'));
}

void draw(char c, int num)			//Draws a row of characters//
{
	for (int i = 0; i < num; i++){
		printf("%c",c);
	}
}

float average(float first, float second)	//Returns the average value//
{
	return (first + second) / 2;
}

void displayResult(int days, float allDaysAverage) //Displays the average temperature for a period of days//
{
	if (days == 1){
		printf("\nYour one day ");
	}
	if (days == 2){
		printf("\nYour two day ");
	}
	if (days == 3){
		printf("\nYour three day ");
	}
	if (days == 4){
		printf("\nYour four day ");
	}
	if (days == 5){
		printf("\nYour five day ");
	}
	if (days == 6){
		printf("\nYour six day ");
	}
	if (days == 7){
		printf("\nYour seven day ");
	}
	if (days == 8){
		printf("\nYour eight day ");
	}
	if (days == 9){
		printf("\nYour nine day ");
	}
	if (days > 9){
		printf("Your %d day ", days);
	}
	printf("average is %.2f",allDaysAverage);
}

char symbolToDraw(char condition, float averageTemperature) //Conditions code for Sunny, Cloudy, Precipitation//
{
	char iret = 'a';							
	if (condition == 's'){					
		iret = '@';
	}
	else if (condition == 'c'){
		iret = '~';
	}
	else if (condition == 'p' && averageTemperature <= 0){
		iret = '*';
	}
	else if (condition == 'p' && averageTemperature > 0){
		iret = ';';
	}
	return iret;
}

void clrinput()
{
	while (getchar() != '\n');      // Clearing input from scanf.
}
	
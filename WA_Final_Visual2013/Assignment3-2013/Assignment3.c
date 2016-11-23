/*Riko Angeles - raangeles - IPC144 - 027123157*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData {
	int day;
	int month;
	int year;
	float high;
	float low;
	float precipitation;
	char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic {
	float minTemperature;
	float maxTemperature;
	float averageTemperature;
	float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz, struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[], int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw(char c, int num);
void clrinput();


int main(void) {
	FILE* fp = fopen("historicaldata.csv", "r");
	if (!fp) {
		printf("you need to put historicaldata.csv into this directory\n");
		exit(0);
	}
	struct DailyData  allData[3000];
	struct DailyData yearData[366];
	int numTotalRecords;

	numTotalRecords = readDailyData(fp, allData);
	int year;
	int reportType;
	int i;
	struct MonthlyStatistic monthly[12];
	printf("Please enter the year for the report: ");
	scanf("%d", &year);
	clrinput();
	printf("Please enter the type of report you wish to generate:\n");
	printf("1) summary\n");
	printf("2) detailed\n");
	scanf("%d", &reportType);
	clrinput();
	int numDays = getRelevantRecords(year, allData, numTotalRecords, yearData);
 	sortYearData(yearData, numDays);

	for (i = 0; i<12; i++) {
		getStats(i + 1, yearData, numDays, &monthly[i]);
	}

	printf("Weather summary for %d\n", year);
	printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
	printf("|-----------|-------|-------|-------|---------|\n");
	for (i = 0; i<12; i++) {
		printMonthlyStatistic(i + 1, &monthly[i]);
	}
	printf("\n\n");
	printf("Precipitation Graph\n\n");
	for (i = 0; i<12; i++) {
		graphLine(i + 1, &monthly[i]);
	}
	if (reportType == 2) {
		printf("\n\n");
		printf("Detailed report:\n");
		printVerbose(yearData, numDays);
	}
	getchar();
	getchar();
	return 0;
}

int readDailyData(FILE* fp, struct DailyData allData[])
{
	int i = 0;
	while (fscanf(fp, "%d,%d,%d,%f,%f,%f,%c\n",
		&allData[i].year, &allData[i].month, &allData[i].day,
		&allData[i].high, &allData[i].low, &allData[i].precipitation,
		&allData[i].condition) == 7) {
		i++;
	}
	return i;
}

int  getRelevantRecords(int yearWanted, const struct DailyData allData[],
	int sz, struct DailyData yearData[])
/*This function returns the number of days of the month*/
{

	int i;
	int iret = 0;
	for (i = 0; i < sz; i++) {

		if (allData[i].year == yearWanted) {
			yearData[iret] = allData[i];
			iret++;
		}
	}

	return iret;
}

void sortYearData(struct DailyData yearData[], int sz)
/*Sorting the month and day of the year*/
{
	struct DailyData iSort;

	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1; j++) {
			if ((yearData[j].month > yearData[j + 1].month) || (yearData[j].month == yearData[j + 1].month)
				&& (yearData[j].day > yearData[j + 1].day)) {
				iSort = yearData[j];				/* <-Sorting by swapping numbers of month and the day*/
				yearData[j] = yearData[j + 1];
				yearData[j + 1] = iSort;
			}
		}
	}
}

void getStats(int month, const struct DailyData yearData[],
	int sz, struct MonthlyStatistic* monthly)
/* Getting the information from the struct*/
{

	int i = 0;
	int iret = 0;
	float totalAve = 0;
	monthly->maxTemperature = -100;
	monthly->minTemperature = 100;
	monthly->totalPrecipitation = 0;
	monthly->averageTemperature = 0;
	for (i = 0; i < sz; i++) {
		if (yearData[i].month == month) {
			iret++;

			if (monthly->minTemperature > yearData[i].low) {	/*<- conditions for getting the stats of the weather data*/
				monthly->minTemperature = yearData[i].low;
			}
			if (monthly->maxTemperature < yearData[i].high) {
				monthly->maxTemperature = yearData[i].high;
			}
			monthly->totalPrecipitation += yearData[i].precipitation;
			totalAve += average(yearData[i].high, yearData[i].low);
		}
	}
	monthly->averageTemperature = totalAve / iret;
}

void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly)
/*This function will print out one single row of the summary table.*/
{
	char* numMonths[12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };

	printf("| %9s | %-5.1f | %-5.1f | %-5.1f | %-7.1f |\n",
		numMonths[month - 1],
		monthly->maxTemperature,
		monthly->minTemperature,
		monthly->averageTemperature,
		monthly->totalPrecipitation);

}

void graphLine(int month, const struct MonthlyStatistic* monthly)
/*Prints out one single row of the precipitation bar graph*/
{
	char* numMonths[12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };
	int total;
	int i;
	printf("\n%9s | ", numMonths[month - 1]);

	total = monthly->totalPrecipitation / 10 + 0.5;

	for (i = 0; i < total; i++)
		printf("*");
}

void printVerbose(const struct DailyData allData[], int sz)
/*Prints the details of the weather data for each of the records in yearData*/
{
	char* numMonths[12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November", "December" };

	int i;

	for (i = 0; i < sz; i++) {

		float ave = average(allData[i].high, allData[i].low);

		printf("\n%9s %2d %d:%6.1f ", numMonths[allData[i].month - 1], allData[i].day, allData[i].year, ave);

		draw(symbolToDraw(allData[i].condition, ave), 20);
	}
}

char symbolToDraw(char condition, float avgTemp)
/*Conditions code for Sunny, Cloudy, Precipitation*/
{
	char iret = 'a';
	if (condition == 's') {
		iret = '@';
	}
	else if (condition == 'c') {
		iret = '~';
	}
	else if (condition == 'p' && avgTemp <= 0) {
		iret = '*';
	}
	else if (condition == 'p' && avgTemp > 0) {
		iret = ';';
	}
	return iret;
}

float average(float first, float second)
/*Returns the average value*/
{
	return (first + second) / 2;
}

void draw(char c, int num)
{
	for (int i = 0; i < num; i++) {
		printf("%c", c);
	}
}

void clrinput()
/*Clearing input from scanf.*/
{
	while (getchar() != '\n');

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _WINDOWS

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
	for (i = 0; i < 40; i++){
		printf("\n");
	}
		printf("Clear Screen\n");
}

int new_game()
{
	printf("Not implemented!");
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
	while (1){
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

	while (iSelectNum < 1 && iSelectNum>3){
		printf("Invalid input, try again ");		
		scanf("%d", &iSelectNum);
		myfflush();
	}

	return iSelectNum;
}

int main() // Here is start point
{
	int iSelectNum = 0;
	do{

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

		getchar();
	wait_for_enter();
	return 0;
}

#define PUZZLE_LENGTH 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{

	char puzzle[PUZZLE_LENGTH][PUZZLE_LENGTH] = {
	{'\\', '0', '/'},
	{'.', '|', '.'},
	{'/', '.', '\\'}
	};
	char puzzle2[PUZZLE_LENGTH][PUZZLE_LENGTH];
	for (int i = 0; i < PUZZLE_LENGTH; i++)
	{
		for (int j = 0; j < PUZZLE_LENGTH; j++)
		{
			puzzle2[i][j] = puzzle[i][j];
		}
	}
	
	printf("\n");
	
	printf("Use the WASD keys to rearrange the puzzle!\n");
	printf("W => up\n");
	printf("A => left\n");
	printf("S => down\n");
	printf("D => right\n");
	printf("Type in enter to confirm your selection\n");
	printf("The '?' is a free space\n");
	printf("\n");
	
	
	int cursX = 1;
	int cursY = 0;
	for (int k = 0; k < 15; k++)
	{
		int choice = rand() % 4;
		
		switch (choice)
		{
			case 0:
				if (cursY != PUZZLE_LENGTH - 1)
				{
					char temp = puzzle2[cursY + 1][cursX];
					puzzle2[cursY + 1][cursX] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursY++;
				
				}
				break;
			case 1:
				if (cursX != PUZZLE_LENGTH - 1)
				{
					char temp = puzzle2[cursY][cursX + 1];
					puzzle2[cursY][cursX + 1] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursX++;
				
				}
				break;
			case 2:
				if (cursY != 0)
				{
					char temp = puzzle2[cursY - 1][cursX];
					puzzle2[cursY - 1][cursX] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursY--;
					
				}
				break;
			case 3:
				if (cursX != 0)
				{
					char temp = puzzle2[cursY][cursX - 1];
					puzzle2[cursY][cursX - 1] = puzzle2[cursY][cursX];
					puzzle2[cursY][cursX] = temp;
					cursX--;
					
				}
				break;
			default:
				break;
		
		
		}
	
	
	}
	
	printf("TARGET\n");
	printf("\n");
	
	
	for (int i = 0; i < PUZZLE_LENGTH; i++)
	{
		for (int j = 0; j < PUZZLE_LENGTH; j++)
		{
			printf("%c", puzzle[i][j]);
				
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	for (int i = 0; i < PUZZLE_LENGTH; i++)
	{
		for (int j = 0; j < PUZZLE_LENGTH; j++)
		{
			printf("%c", puzzle2[i][j]);
				
		}
		printf("\n");
	}
	
	
	int done = 0; 
	
	
	while (!done)
	{
	
	
		int flag1 = 1;	
		
		char buf[1];
		read(1, &buf, sizeof(buf));
		int input_char = buf[0];
		
		if (input_char == 119)
		{
		
			printf("Upward move\n");
			
			
			if (cursY != PUZZLE_LENGTH - 1)
			{
				char temp = puzzle2[cursY + 1][cursX];
				puzzle2[cursY + 1][cursX] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursY++;
				
			}
		
		}
		if (input_char == 97)
		{
			printf("Left move\n");	
			if (cursX != PUZZLE_LENGTH - 1)
			{
				char temp = puzzle2[cursY][cursX + 1];
				puzzle2[cursY][cursX + 1] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursX++;
				
			}
		}
		
		if (input_char == 115)
		{
			printf("Down move\n");
			if (cursY != 0)
			{
				char temp = puzzle2[cursY - 1][cursX];
				puzzle2[cursY - 1][cursX] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursY--;
				
			}
		
		}
		
		if(input_char == 100)
		{
			printf("Right move\n");
			if (cursX != 0)
			{
				char temp = puzzle2[cursY][cursX - 1];
				puzzle2[cursY][cursX - 1] = puzzle2[cursY][cursX];
				puzzle2[cursY][cursX] = temp;
				cursX--;
				
			}
		
		}
		
		printf("\n");
		printf("\n");
		
		if (input_char != 10)
		{
			printf("Use the WASD keys to rearrange the puzzle!\n");
			printf("W => up\n");
			printf("A => left\n");
			printf("S => down\n");
			printf("D => right\n");
			printf("Type in enter to confirm your selection\n");
			printf("The '?' is a free space\n");
			printf("\n");
		
			printf("TARGET\n");
			printf("\n");
			for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
			{
				for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
				{
				printf("%c", puzzle[i2][j2]);
				}
				printf("\n");
			}
			printf("\n");
			printf("\n");
			
			for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
			{
				for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
				{
				printf("%c", puzzle2[i2][j2]);
				}
				printf("\n");
			}
			
			
			
			
			
		}
				
	
		
		
		for (int i = 0; i < PUZZLE_LENGTH; i++)
		{
			for (int j = 0; j < PUZZLE_LENGTH; j++)
			{
				if (puzzle2[i][j] != puzzle[i][j])
				{
					if (!(puzzle2[i][j] == '?' && puzzle[i][j] == '0'))
					{
						flag1 = 0;
					}
				}
			}
				
		}
		if (flag1)
			done = 1;
	
		
	}
		
	printf("The puzzle has been solved!\n");
	return 0;
}


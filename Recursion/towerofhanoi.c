/*Tower of Hanoi is a purely mathematics-based puzzle game that consists of three rods with a number of disks of varying diameters arranged in ascending order of diameter from the top, thus forming a conical shape consisting of disks. The aim of the game is to move the stack of disks from the first rod to the last rod using an auxiliary rod by following certain rules. The rules of the game are as follows:

One disk can be moved only once at a time.
Upper disk can be moved from one of the stacks and placed on top of another empty rod.
Disk of the largest diameter can't be placed on a disk of the smaller diameter.*/

#include <stdio.h>

// Tower of Hanoi program in C using Recursion
void toH(int n, char rodA, char rodC, char rodB)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c",rodA ,rodC );
		return;
	}
	toH(n-1, rodA, rodB, rodC);
	printf("\n Move disk %d from rod %c to rod %c", n, rodA, rodC);
	toH(n-1, rodB, rodC,rodA);
}

int main()
{
	int no_of_disks ;
	printf("Enter number of disks: ");
	scanf("%d", &no_of_disks);
	toH(no_of_disks, 'A','C','B'); 
	return 0;
}

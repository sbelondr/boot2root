#include <stdio.h>

//void read_six_numbers(char *param_1,int param_2)
//{
//  int iVar1;

//  iVar1 = sscanf(param_1,"%d %d %d %d %d %d",param_2,param_2 + 4,param_2 + 8,param_2 + 0xc,
//                 param_2 + 0x10,param_2 + 0x14);
//  if (iVar1 < 6) {
    //explode_bomb();
//  }
//  return;
//}

void phase_2()

{
	int iVar1;
	int aiStack32 [7];

	aiStack32[0] = 1;
	aiStack32[1] = 1;
	aiStack32[2] = 2;
	aiStack32[3] = 3;
	aiStack32[4] = 4;
	aiStack32[5] = 5;
	aiStack32[6] = 6;

	if (aiStack32[1] != 1) {
		printf("Error\n");
	}
	printf("[1]\n");
	iVar1 = 1;
	int prev = 1;
	do {
		int n = 1;
		while (n != (iVar1+1) * prev)
		{
			++n;
		}
		prev = n;
		printf("[%d]\n", n);
		//if (aiStack32[iVar1 + 1] != (iVar1 + 1) * aiStack32[iVar1]) {
		//	printf("Error\n");
		//}
		iVar1 = iVar1 + 1;
	} while (iVar1 < 6);
	return;
}

int	main(void)
{
	phase_2();
	return (0);
}

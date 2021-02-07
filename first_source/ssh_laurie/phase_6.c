#include <stdio.h>

int	explode_bomb(void)
{
	dprintf(2, "Error\n");
	return (-1);
}

// in gdb -> info variables node1..6
// p	node1 -> 253
//		node2 -> 725
//		node3 -> 301
//		node4 -> 997
//		node5 -> 212
//		node6 -> 432

void phase_6(void)
{
	int *piVar1;
	int iVar2;
	int *piVar3;
	int iVar4;
	int *local_34[6];
	int local_38[6];
	int local_1c[6];

	local_38[0] = 253;
	local_38[1] = 725;
	local_38[2] = 301;
	local_38[3] = 997;
	local_38[4] = 212;
	local_38[5] = 432;
	local_1c[0] = 5;
	local_1c[1] = 1;
	local_1c[2] = 3;
	local_1c[3] = 6;
	local_1c[4] = 2;
	local_1c[5] = 4;
//	read_six_numbers(param_1,local_1c);
	iVar4 = 0;
	// check doublon
	do {
		if (5 < local_1c[iVar4] - 1U) {
			explode_bomb();
		}
		iVar2 = iVar4 + 1;
		if (iVar2 < 6) {
			do {
				if (local_1c[iVar4] == local_1c[iVar2]) {
					explode_bomb();
				}
				iVar2 = iVar2 + 1;
			} while (iVar2 < 6);
		}
		iVar4 = iVar4 + 1;
	} while (iVar4 < 6);
	iVar4 = 0;
	do {
		iVar2 = 1;
		piVar3 = (int *)local_38;
		if (1 < local_1c[iVar4]) {
			do {
				piVar3 = (int*)piVar3 + 2;
				iVar2 = iVar2 + 1;
			} while (iVar2 < local_1c[iVar4]);
		}
		local_34[iVar4] = piVar3;
		iVar4 = iVar4 + 1;
	} while (iVar4 < 6);
	printf("ok\n");
	iVar4 = 1;
	int i = 0;
	while (i < 6)
	{
		printf("%d\n", piVar3[i]);
		i++;
	}
	piVar3 = local_34[0];
	do {
		piVar1 = local_34[iVar4];
		piVar3[2] = (int)piVar1;
		iVar4 = iVar4 + 1;
		piVar3 = piVar1;
	} while (iVar4 < 6);
	piVar1[2] = 0;
	iVar4 = 0;
	do {
		if (*local_34[0] < *(int *)((local_34 + 0) + 2)) {
			explode_bomb();
		}
		local_34[0] = (int *)((local_34 + 0) + 2);
		iVar4 = iVar4 + 1;
	} while (iVar4 < 5);
	return;
}


int	main(void)
{
	phase_6();
	return (0);
}

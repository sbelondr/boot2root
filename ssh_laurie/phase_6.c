#include <stdio.h>

int	explode_bomb(void)
{
	dprintf(2, "Error\n");
	return (-1);
}

void phase_6(char *param_1)
{
	int *piVar1;
	int iVar2;
	int *piVar3;
	int iVar4;
	undefined1 *local_38;
	int *local_34[6];
	int local_1c[6];

	local_1c[0] = 1;
	local_1c[1] = 1;
	local_1c[2] = 1;
	local_1c[3] = 1;
	local_1c[4] = 1;
	local_1c[5] = 1;
	local_38 = node1;
//	read_six_numbers(param_1,local_1c);
	iVar4 = 0;
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
				piVar3 = (int *)piVar3[2];
				iVar2 = iVar2 + 1;
			} while (iVar2 < local_1c[iVar4]);
		}
		local_34[iVar4] = piVar3;
		iVar4 = iVar4 + 1;
	} while (iVar4 < 6);
	iVar4 = 1;
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
		if (*local_34[0] < *(int *)local_34[0][2]) {
			explode_bomb();
		}
		local_34[0] = (int *)local_34[0][2];
		iVar4 = iVar4 + 1;
	} while (iVar4 < 5);
	return;
}

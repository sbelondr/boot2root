#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int	explode_bomb()
{
	return -1;
}

int func4(int param_1)

{
	int iVar1;
	int iVar2;

	if (param_1 < 2) {
		iVar2 = 1;
	}
	else {
		iVar1 = func4(param_1 + -1);
		iVar2 = func4(param_1 + -2);
		iVar2 = iVar2 + iVar1;
	}
	return iVar2;
}

int	 phase_4(char *param_1)

{
	int iVar1;
	int local_8;

	iVar1 = sscanf(param_1,"%d",&local_8);
	if ((iVar1 != 1) || (local_8 < 1)) {
		return explode_bomb();
	}
	iVar1 = func4(local_8);
	if (iVar1 != 0x37) {
		return explode_bomb();
	}
	return (local_8);
}


int	main(void)
{
	int	i = -1;

	while (++i < 1000)
	{
		char	c[1024];
		bzero(c, 1024);
		sprintf(c, "%d", i);
		if (phase_4(c) != -1)
		{
			printf("%s\n", c);
			return (0);
		}
		dprintf(2, "Am here\n");
	}
	return (0);
}

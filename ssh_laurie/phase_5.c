#include <stdio.h>
#include <string.h>

int	explode_bomb(void)
{
	dprintf(2, "Error\n");
	return (-1);
}

int phase_5(char *param_1)

{
  int iVar1;
  char local_c[6];
  
  iVar1 = strlen(param_1);
  if (iVar1 != 6) {
	  printf("%d\n", iVar1);
    return explode_bomb();
  }
  iVar1 = 0;
  char *array123 = "isrveawhobpnutfg\260\001";
  do {
// local_c[iVar1] = (&array.123)[(char)(*(byte *)(iVar1 + param_1) & 0xf)];
// array.123 -> 0x804b220 -> 0x804b220:	"isrveawhobpnutfg\260\001"
	printf("%d\n", (int)param_1[iVar1] & 0xf);
	printf("%d\n", (int)param_1[iVar1]);
    local_c[iVar1] = array123[(int)(param_1[iVar1] & 0xf)];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = strcmp(local_c,"giants");
  if (iVar1 != 0) {
	  printf("[%s]\n", local_c);
    return explode_bomb();
  }
  return (0);
}

int	rv_phase_5(void)
{
	int i = 0;

	char *giants = "giants";
	while (i < 6)
	{
		char *array123 = "isrveawhobpnutfg\260\001";
		int	j = 'a';
		while (array123[j & 0xf] != giants[i])
			++j;
		printf("%c\n", j);
		++i;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		phase_5(av[1]);
	else
		rv_phase_5();
	return (0);
}

#include <stdint.h>
#include <stdio.h>

void phase_3(char *param_1)

{
	int iVar1;
	char cVar2;
	unsigned int local_10;
	char local_9;
	int local_8;

	iVar1 = sscanf(param_1,"%d %c %d",&local_10,&local_9,&local_8);
	printf("%d %c %d\n", local_10, local_9, local_8);
	if (iVar1 < 3) {
		printf("Error\n");
	}
	switch(local_10) {
		case 0:
			cVar2 = 'q';
			if (local_8 != 0x309) {
		printf("Error\n");
			}
			break;
		case 1:
			cVar2 = 'b';
			if (local_8 != 0xd6) {
		printf("Error\n");
			}
			break;
		case 2:
			cVar2 = 'b';
			if (local_8 != 0x2f3) {
		printf("Error\n");
			}
			break;
		case 3:
			cVar2 = 'k';
			if (local_8 != 0xfb) {
		printf("Error\n");
			}
			break;
		case 4:
			cVar2 = 'o';
			if (local_8 != 0xa0) {
		printf("Error\n");
			}
			break;
		case 5:
			cVar2 = 't';
			if (local_8 != 0x1ca) {
		printf("Error\n");
			}
			break;
		case 6:
			cVar2 = 'v';
			if (local_8 != 0x30c) {
		printf("Error\n");
			}
			break;
		case 7:
			cVar2 = 'b';
			if (local_8 != 0x20c) {
		printf("Error\n");
			}
			break;
		default:
			cVar2 = 'x';
		printf("Error\n");
	}
	if (cVar2 != local_9) {
		printf("Error\n");
	}
	return;
}

int	main(int ac, char **av)
{
	if (ac == 2)
		phase_3("1 b 214");
	return (0);
}

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	flag[127];

	if (argc == 3)
	{
		for (int i=0; i<127; i++)
			flag[i] = 0;
		for (char *s=argv[1]; *s; s++)
		{
			if (flag[(int)*s] == 0)
			{
				write(1, s, 1);
				flag[(int)*s] = 1;
			}
		}
		for (char *s=argv[2]; *s; s++)
		{
			if (flag[(int)*s] == 0)
			{
				write(1, s, 1);
				flag[(int)*s] = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

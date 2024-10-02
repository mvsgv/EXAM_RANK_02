#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int j;
    unsigned char seen[256] = {0};
    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j])
                {
                    if (!seen[(unsigned char)av[1][i]])
                    {
                        write(1, &av[1][i], 1);
                        seen[(unsigned char)av[1][i]] = 1;
                    }
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

#include <stdio.h>
#include <unistd.h>

int is_repeat(char **av, char c, int pos)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (av[1][i] != c)
		i++;
	if (i != pos)
		return (1);
	return (0);
}

void inter (char **av)
{
	int i;
	int j;
	
	i = 0;
	while (av[1][i])
	{
		j = 0;
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
			{
				if (!is_repeat(av, av[1][i], i))
				{
					write(1,&av[1][i],1);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av);
		write (1,"\n", 1);
	}	
	else
		write (1,"\n", 1);
	return (0);	
}

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	map[255];
	int		i;
	int		j;

	i = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			j = -1;
			while (argv[2][++j])
			{
				if (map[argv[1][i]] != 1 && (argv[1][i] == argv[2][j]))
				{
					write(1, &argv[1][i], 1);
					map[argv[1][i]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
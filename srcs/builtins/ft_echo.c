#include "../../includes/general.h"

int	n_args(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

int	ft_echo(char **args)
{
	int	i;
	int	n_opt;

	i = 1;
	n_opt = 0;
	if (n_args(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n_opt = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, "", 1);
			i++;
		}
	}
	if (n_opt == 0)
		write(1, "\n", 1);
	return (0);
}
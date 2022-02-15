#include "../../includes/minishell.h"

int		input_redir(t_list *in_lst, char *heredoc_file)
{
	int			fd;
	t_redirect	*redir_data;

	fd = STDIN_FILENO;
	while (fd != -1 && in_lst)
	{
		close(fd);
		redir_data = in_lst->content;
		in_lst = in_lst->next;
		if (!in_lst && redir_data->type == here_doc)
			fd = set_redir(redir_data->type, heredoc_file, STDIN_FILENO);
		else if (redir_data->type == redir_in)
			fd = set_redir(redir_data->type, redir_data->args, STDIN_FILENO);
	}
}

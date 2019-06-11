#include "ft_ls.h"

void	print_paths_lst(t_list *paths_lst)
{
	while (paths_lst != NULL)
	{
		ft_putstr(((t_entry*)paths_lst->content)->name);
		ft_putstr("\n");
		paths_lst = paths_lst->next;
	}
}
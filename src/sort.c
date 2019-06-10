#include "ft_ls.h"

int	alpha_sort(t_list* a, t_list* b)
{
	return (ft_strcmp(((t_entry*)a->content)->name, 
				((t_entry*)b->content)->name));
}

int last_modif_time_sort(t_list* a, t_list*b)
{
	return ((int) ((t_entry*)b->content)->stat_buf->st_mtime - 
			((t_entry*)a->content)->stat_buf->st_mtime);
}

t_list	*del_dot_entries(t_list *paths_lst)
{
	ft_putstr(((t_entry*)paths_lst->content)->name);
	if (paths_lst == NULL)
		return NULL;
	if (((t_entry*)paths_lst->content)->name[0] == '.')
		return del_dot_entries(paths_lst->next);
	paths_lst->next = del_dot_entries(paths_lst->next);
	return paths_lst;
}


void free_t_entry(t_entry *entry)
{
	ft_memdel((void**) &(entry->name));
	ft_memdel((void**) &(entry->stat_buf));
}

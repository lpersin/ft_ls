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

int is_dot_entry(t_list *node)
{
	return (((t_entry*)node->content)->name[0] == '.');
}

void sort_entries(t_list **entries_lst, t_options* const options, char user_path)
{
	if (options->a == 0 && !user_path)
		*entries_lst = ft_lst_del_occurences(*entries_lst, is_dot_entry, free_entry);
	if (options->t == 1)
		ft_fct_sortlst(entries_lst, last_modif_time_sort);
	else
		ft_fct_sortlst(entries_lst, alpha_sort);
	if (options->r == 1)
		ft_lstrev(entries_lst);
}

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

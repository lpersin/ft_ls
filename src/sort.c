#include "ft_ls.h"

int	alpha_sort(t_list* a, t_list* b)
{
	return (ft_strcmp(((t_dir*)a->content)->name, ((t_dir*)b->content)->name));
}

int last_modif_time_sort(t_list* a, t_list*b)
{
	return ((int) ((t_dir*)b->content)->stat_buf->st_mtime - ((t_dir*)a->content)->stat_buf->st_mtime);
}

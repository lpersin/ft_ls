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

void free_entry(void *v_entry, size_t content_size)
{
	t_entry *entry = (t_entry*)v_entry;
	if (content_size)
	{
		ft_memdel((void**) &(entry->name));
		ft_memdel((void**) &(entry->stat_buf));
	}
}

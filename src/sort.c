#include "ft_ls.h"

int	alpha_sort(t_list* a, t_list* b)
{
	return (ft_strcmp(((t_file*)a->content)->name, ((t_file*)b->content)->name));
}

int last_modif_time_sort(t_list* a, t_list*b)
{
	return ((int) ((t_file*)b->content)->stat_buf->st_mtime - ((t_file*)a->content)->stat_buf->st_mtime);
}

t_list	*del_dot_files(t_list *curr_node)
{
	t_list *tmp_nxt_node;

	if (curr_node == NULL)
		return NULL;
	if (((t_file*)(curr_node->content))->name[0] == '.')
	{
		tmp_nxt_node = curr_node->next;
		free_t_file(curr_node);
		free(curr_node);
		return tmp_nxt_node;
	}
	curr_node->next = del_dot_files(curr_node->next);
	return curr_node;
}


void free_t_file(t_list *node)
{
	free(((t_file*)node->content)->name);
	free(((t_file*)node->content)->stat_buf);
}

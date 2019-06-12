#include "ft_ls.h"

void free_entry(void *v_entry, size_t content_size)
{
	t_entry *entry = (t_entry*)v_entry;
	if (content_size)
	{
		ft_memdel((void**) &(entry->name));
		ft_memdel((void**) &(entry->stat_buf));
	}
}

void free_entries_lst(t_list **entries_lst)
{
	t_list *tmp_node;

	while(*entries_lst != NULL)
	{
		tmp_node = (*entries_lst)->next;
		free_entry((void*) (*entries_lst)->content, (*entries_lst)->content_size);
		free((*entries_lst)->content);
		(*entries_lst)->content = NULL;
		free(*entries_lst);
		*entries_lst = tmp_node;
	}
}
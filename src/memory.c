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
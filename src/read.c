#include "ft_ls.h"

void	read_dir(char *path, t_list **paths_lst, t_options* const options)
{
	DIR *dir_p;
	struct dirent* dp;

	if((dir_p = opendir(path)) == NULL)
		show_error(path);
	while ((dp = readdir(dir_p)) != NULL)
		load_entry(dp->d_name, paths_lst, options);
}

t_entry	*get_t_entry(char *path, t_options* const options)
{
	t_entry	*entry;

	entry = NULL;
	if (path != NULL)
	{
		if ((entry = (t_entry*)malloc(sizeof(t_entry))) == NULL)
			show_error(path);
		if ((entry->name = ft_strdup(path)) == NULL)
			show_error(path);
		if (options->l == 1)
		{
			if((entry->stat_buf = (struct stat*)malloc(sizeof(struct stat))) == NULL)
				show_error(path);
			stat(path, entry->stat_buf);
		}
		else
			entry->stat_buf = NULL;
		
	}
	return entry;
}

void load_entry(char *path, t_list** paths_lst, t_options* const options)
{
	t_list*		node;
	t_entry*	entry;

	entry = get_t_entry(path, options);
	if ((node = ft_lstnew(entry, sizeof(t_entry))) == NULL)
		show_error(path);
	if (*paths_lst == NULL)
		*paths_lst = node;
	else
		ft_lstadd(paths_lst, node);
}
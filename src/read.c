#include "ft_ls.h"

void	read_dir(char *path, t_list **paths_lst, t_options* const options)
{
	DIR *dir_p;
	struct dirent* dp;

	if((dir_p = opendir(path)) == NULL)
		show_error(path);
	while ((dp = readdir(dir_p)) != NULL)
	{
		//load_path(dp->d_name, ft_strlen(dp->d_name), paths_lst);  //error management here if load_path fails											//replace ft_strlen by dp->d_namlen on Mac
		load_entry(dp->d_name, paths_lst, options);
	}
}

void	print_paths_lst(t_list *paths_lst)
{
	while (paths_lst != NULL)
	{
		ft_putstr(((t_entry*)paths_lst->content)->name);
		ft_putstr("\n");
		paths_lst = paths_lst->next;
	}	
}

t_entry	*get_t_entry(char *path, t_options* const options)
{
	t_entry	*entry;

	entry = NULL;
	if (path != NULL)
	{
		if((entry = (t_entry*)malloc(sizeof(t_entry))) == NULL)
			show_error(path);
		if((entry->name = ft_strdup(path)) == NULL)
			show_error(path);
		if (options->l == 1)
			stat(path, entry->stat_buf);
	}
	return entry;
}

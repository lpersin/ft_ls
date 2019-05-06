#include "ft_ls.h"

void	read_dir(char *path, t_list **paths_lst)
{
	DIR *dir_p;
	struct dirent* dp;

	dir_p = opendir(path);
	while ((dp = readdir(dir_p)) != NULL)
	{
		load_path(dp->d_name, ft_strlen(dp->d_name), paths_lst);  //error management here if load_path fails											//replace ft_strlen by dp->d_namlen on Mac
	}
}

void	print_paths_lst(t_list *paths_lst)
{
	while (paths_lst != NULL)
	{
		ft_node_to_str(paths_lst);
		ft_putstr("\n");
		paths_lst = paths_lst->next;
	}	
}

t_file	*get_t_file(char * path)
{
	t_file	*del_dot_files;

	if (paths_lst == NULL)
		path = ".";
	else

}

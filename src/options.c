#include "ft_ls.h"

int get_args(int ac, char **av, t_options* const options, t_list** paths_lst)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			options->loaded = 1;
		else if (!options->loaded && av[i][0] == '-' && av[i][1] != '\0'){
			load_options(av[i] + 1, options);}
		else
		{
			options->loaded = 1;
			//load_path(av[i], ft_strlen(av[i]), paths_lst);
			load_entry(av[i], paths_lst, options);
		}
		i++;
	}
	return 0;
}

int load_options(char *str, t_options* const options)
{
	if (options == NULL)
		return 1;
	while (*str)
	{
		if (*str == 'l')
			options->l = 1;
		else if (*str == 'R')
			options->R = 1;
		else if (*str == 'a')
			options->a = 1;
		else if (*str == 'r')
			options->r = 1;
		else if (*str == 't')
			options->t = 1;
		else
			return (usage_error(*str));
		str++;
	}
	return (0);
}

int load_path(char *path, int path_len, t_list** paths_lst)
{
	t_list* node;

	if ((node = ft_lstnew(path, path_len + 1)) == NULL)
		return (1); //use strerror here
	if (*paths_lst == NULL)
		*paths_lst = node;
	else
		ft_lstadd(paths_lst, node);
	return (0);
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

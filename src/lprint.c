#include "ft_ls.h"

size_t get_max_links_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while(node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_nlink);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

size_t get_max_bytes_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while(node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_size);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

size_t get_total_blks_allocated(t_list *node)
{
	int res;

	res = 0;
	while(node != NULL)
	{
		res += ((t_entry*)node->content)->stat->st_blocks;
		node = node->next;
	}
	return res;
}

int	l_min_str_size(t_list *node)
{
	int res;
	t_entry*	entry;

	entry = (t_entry*)node->content;
	res = 9 + 2 + ft_count_digits(get_max_links_count(node)) + 1 
				+ ft_strlen(getpwuid(entry->stat->st_uid)->pw_name) + 2 
				+ ft_strlen(getgrgid(entry->stat->st_gid)->gr_name) + 2
				+ ft_count_digits(get_max_bytes_count(node)) + 1 + 12 + 1;
	return res;
}

int get_longest_username(t_list *node)
{
	int			res;
	int			candidate;
	t_entry*	entry;

	res = 0;
	while(node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getpwuid(entry->stat->st_uid)->pw_name);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

int	get_longest_groupname(t_list *node)
{
	int			res;
	int			candidate;
	t_entry*	entry;

	res = 0;
	while(node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getgrgid(entry->stat->st_gid)->gr_name);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

void write_to_buf(char **buf, char* str, int pre_offset, int post_offset)
{
	int i;

	i = 0;
	*buf += pre_offset;
	while(*str)
	{
		**buf = *str;
		*buf += 1;
		str++;
		i++;
	}
	while(post_offset > i)
	{
		**buf = ' ';
		*buf += 1;
		i++;
	}
}

void lprint_symlimk_handler(t_list* node, char *s)
{
	char 	*str;
	ssize_t	offset;
	t_entry	*entry;

	str = NULL;
	if(s)
	{
		str = (char*)malloc(sizeof(char) * PATH_MAX);
		entry = (t_entry*)node->content;
		if((offset = readlink(entry->full_path, str, PATH_MAX)) == -1)
			return;
		str[offset] = '\0';
		ft_putstr(" -> ");
		ft_putstr(str);
		free(str);
	}
}

void l_print(t_list *node, int single)
{
	t_entry *entry;
	char*	str;
	int		str_len;
	int		min_len;
	t_list	*head;
	char*	orig_str;

	head = node;
	if(node != NULL)
		min_len = l_min_str_size(node);
	while(node != NULL)
	{
		entry = ((t_entry*)node->content);
		str_len = min_len + 2;
		str = ft_strnew(str_len);
		orig_str = str;
		ft_strfill(str, ' ', str_len);
		get_type(entry->stat->st_mode, &str);
		get_mode(entry->stat->st_mode, &str);
		str += ft_count_digits(get_max_links_count(head)) + 1;
		ft_write_nbr_r2l(entry->stat->st_nlink, str);
		write_to_buf(&str, getpwuid(entry->stat->st_uid)->pw_name, 2, get_longest_username(head));
		write_to_buf(&str, getgrgid(entry->stat->st_gid)->gr_name, 2, get_longest_groupname(head));
		str += ft_count_digits(get_max_bytes_count(head)) + 1;
		ft_write_nbr_r2l(entry->stat->st_size, str);
		str += 2;
		format_time(ctime(&(entry->stat->st_mtime)), str);
		str += 13;
		*str = '\0';
		ft_putstr(orig_str);
		ft_putstr(entry->name);
		if(S_ISLNK(entry->stat->st_mode))
			lprint_symlimk_handler(node, str);
		if(node->next != NULL || single)
		 	ft_putstr("\n");
		free(orig_str);
		if(single)
			break;
		node = node->next;
	}
}
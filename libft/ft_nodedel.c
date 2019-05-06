#include "libft.h"

t_list	*ft_nodedel(t_list *curr_node, int (*target)(t_list*), void (*del)(void*, size_t))
{
	t_list *tmp_nxt_node;

	if (curr_node == NULL)
		return NULL;
	if ((*target)(curr_node))
	{
		tmp_nxt_node = curr_node->next;
		(*del)(curr_node->content, curr_node->content_size);
		free(curr_node);
		return tmp_nxt_node;
	}
	curr_node->next = ft_nodedel(curr_node->next, target, del);
	return curr_node;
}

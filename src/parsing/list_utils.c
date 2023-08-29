#include "../../includes/cub.h"

t_map	*new_map(char **map)
{
	t_map	*new;

	if (!map || !map[0])
		return (NULL);
	new = ft_calloc(1, sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = map;
	new->width = ft_strlen(map[0]);
	new->height = ft_arrlen(map);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_map(t_map **map, t_map *new)
{
	t_map	*tmp;

	if (!map || !new)
		return ;
	if (!*map)
	{
		*map = new;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	delete_node(t_map **map, t_map *node)
{
	if (!map || !*map || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *map)
		*map = node->next;
	ft_arrfree(node->map);
	free(node);
}

void	delete_list(t_map **map)
{
	t_map	*tmp;

	if (!map || !*map)
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		delete_node(map, *map);
		*map = tmp;
	}
}

int	map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

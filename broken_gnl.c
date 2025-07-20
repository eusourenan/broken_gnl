# include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int i = 0;

	// Validação de NULL
	if (!s)
		return NULL;

	while (s[i] != c && s[i] != 0) // Parar quando encontrar o '\0'
		i++;
	if (s[i] == c)
		return (&s[i]);
	return NULL;
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	// validação de NULL
	if (!dest || !src || !n)
		return dest;

	if (dest < src)
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	len = 0;

	// Validação de NULL
	if (!s)
		return 0;

	while (s[len] != 0)
	{
		len++;
	}
	return (len);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	// validação de NULL
	if (!dest || !src || !n)
		return dest;

	while (n--)
	{
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return dest;
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);

	if (!tmp)
		return 0;

	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	char		*ret = NULL;
	char		*tmp = NULL;

	tmp = ft_strchr(b, '\n');

	while (!tmp)
	{
		int	read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);

		b[read_ret] = 0;
		if (!str_append_str(&ret, b))
			return (NULL);

		tmp = ft_strchr(b, '\n'); // Valido se encontrei um \n
	}

	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return NULL;
	}
	return ret;
}
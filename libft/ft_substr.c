#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (l <= start)
	{
		p = (char *)malloc(1);
		p[0] = 0;
		return (p);
	}
	p = (char *)malloc(len + 1);
	if (!p)
		return (p);
	i = -1;
	while (++i < len)
		p[i] = s[start + i];
	p[i] = 0;
	return (p);
}

void ft_memcpy(void *destination, void *source, unsigned int size)
{
	int i;
	char *dst;
	char *src;

	dst = (char*)destination;
	src = (char*)source;
	i = 0;
	while (i < size)
		dst[i] = src[i++];
}

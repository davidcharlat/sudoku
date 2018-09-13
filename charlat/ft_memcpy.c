void ft_memcpy(void *destination, void *source, unsigned int size)
{
	while (--size >= 0)
		((char *)destination)[size] = ((char *)source)[size];
}

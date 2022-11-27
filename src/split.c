static int	check_spcs(char *arg)
{
	while (*arg)
	{
		if (*arg == 32)
			return (1);
		arg++;
	}
	return (0);
}

void    arrayjoin(char ***arr, char *join, size_t *i)
{
    char    **split;
    size_t  j;

    j = 0;
    split = ft_split(join, ' ');
    while (split[j] != NULL)
        *arr[*i++] = split[j++];
	free(split[j]);
	free(split);
}

char    **formater(int argc, char *argv[])
{
    char    **res;
    char    **tmp;
    int     i;
    int     j;

    i = -1;
    j = -1;
    while (i++ < (argc - 1))
    {
        if(check_spcs(argv[i + 1]))
            arrayjoin(&tmp, argv[i + 1], i);
        else
            tmp[i] = argv[i + 1]; 
    }
    res = malloc(i * sizeof(char *));
    while (j++ < i)
        res[j] = tmp[j];
    return (free(argv[0]), free(argv), res);
}

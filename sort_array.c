static int	partition(int *array, int lo, int hi)
{
	int	pivot;
	int	tmp;

	tmp = 0;
	pivot = array[(lo + hi) / 2];
	while (1)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo >= hi)
			return (hi);
		tmp = array[lo];
		array[lo] = array[hi];
		array[hi] = tmp;
		lo++;
		hi--;
	}
}

void	sort_arr(int *array, int lo, int hi)
{
	int	p;

	p = 0;
	if (lo < hi)
	{
		p = partition(array, lo, hi);
		sort_arr(array, lo, p);
		sort_arr(array, p + 1, hi);
	}
}

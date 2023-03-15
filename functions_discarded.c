
//2023/03/15
/* bool	is_enclosed(t_fdf *fdf)
{
	long	i;

	i = -1;
	printf("row_len: %ld\ncolumn: %ld\n", fdf->row_len, fdf->column);
	while (++i < fdf->row_len)
	{
		if (fdf->n[0][i].value != 0)//check the first row->OK
			return (false);
		if (fdf->n[fdf->column - 1][i].value != 0)//check the last row->OK
			return (false);
		printf("first row[%ld]: %ld\nlast row[%ld]: %ld\n",i ,fdf->n[0][i].value, i, fdf->n[fdf->column][i].value);
	}
	i = -1;
	while (++i < fdf->column)
	{
		if (fdf->n[i][0].value != 0)//check the first column->OK
			return (false);
		if (fdf->n[i][fdf->row_len - 1].value != 0)//check the last column->OK
			return (false);
		printf("first clm[%ld]: %ld\nlast clm[%ld]: %ld\n",i, fdf->n[i][0].value, i, fdf->n[i][fdf->row_len].value);
	}
	return (true);
} */



#include <math.h>
#include <stdio.h>
#include <string.h>

int	atox(char	*str)
{
	int	ret;
	int	i;
	int	j;
	int	len;
	char	*base_l;
	char	*base_u;

	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";

	i = 0;
	j = 0;
	ret = 0;
	len = strlen(str) - 1;
	while (str[i])
	{
		while (j < 16)
		{
			if (str[i] == base_l[j] || str[i] == base_u[j])
			{
				ret = ret + j * pow(16, len);
				len--;
			}
			j++;
		}
		i++;
	}
	return (ret);
}


int main(int ac, char **av) 
{
  
  //char *str;
  int ret;
  char  r;
  char  b;
  char  g;
  
  //str = "d0";
  ret = atox(av[1]);

  printf("ret: %d\n", ret);
/*   r = str >> 16;
  g = str >> 8 & 0xFF;
  b = str & 0xFF;


  printf("this is hex: %d\n", ret); */

  return 0;
}
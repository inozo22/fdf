#include <math.h>
#include <stdio.h>
#include <string.h>

int	atox(char	*str)
{
	int	ret;
	int	i;
	int	j;
	int	len;
	char	*base;

	base = "0123456789abcdef";

	i = 0;
	j = 0;
	ret = 0;
	len = strlen(str) - 1;
	while (str[i])
	{
		while (j < 16)
		{
			if (str[i] == base[j])
			{
				ret = ret + j * pow(16, len);
				len--;
			}
			j++;
		}
		i++;
	}
	return (ret);
/* 	int	ret;
	int	i;
	int	j;
	int	k;
	char	*base;

	ret = 0;
	base ="0123456789abcdef";
	i = strlen(str);
	printf("Line: %d\ni: %d\n", __LINE__, i);
	while (i > 0)
	{
		k = i - 1;
		j = 0;
		printf("Line: %d\nk: %d\n", __LINE__, k);
		while (++j <= 16)
		{
			if (str[i] == base[j])
			{
				printf("Line: %d\nstr[%d]: %c\n", __LINE__, i, str[i]);
				while (k >= 0)
				{
					ret = ret + j * (pow(16, k));
					k--;
				}
			}
		}
		i--; 
	}
	return (ret);*/
}


int main() 
{
  
  char *str;
  int ret;
  char  r;
  char  b;
  char  g;
  
  str = "d0";
  ret = atox(str);

  printf("ret: %d\n", ret);
/*   r = str >> 16;
  g = str >> 8 & 0xFF;
  b = str & 0xFF;


  printf("this is hex: %d\n", ret); */

  return 0;
}
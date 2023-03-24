#include <math.h>
#include <stdio.h>
#include <string.h>

int	atox(char	*str)
{
	int	ret;
	int	i;
	int	j;
	int	k;
	char	*base;

	ret = 0;
	base ="0123456789abcdef";
	i = strlen(str);
	while (i > 0)
	{
		k = i - 1;
		j = -1;
		while (++j < 16)
		{
			if (str[i] == base[j])
			{
				while (k >= 0)
				{
					ret = ret + j * (pow(16, k));
					k--;
				}
			}
		}
		i--;
	}
	return (ret);
}


int main() 
{
  
  char *str;
  int ret;
  char  r;
  char  b;
  char  g;
  
  str = "ff";
  ret = atox(str);
  r = str >> 16;
  g = str >> 8 & 0xFF;
  b = str & 0xFF;


  printf("this is hex: %d\n", ret);

  return 0;
}
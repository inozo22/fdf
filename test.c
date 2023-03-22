#include <math.h>
#include <stdio.h>
#include <string.h>



int	atox(char	*str)
{
	int	ret;
	int	i;
	int	j;
	int	k;
    int l;
	char	*base;

	ret = 0;
	j = -1;
	base ="0123456789abcdef";
	i = strlen(str);
	k = i + 1;
    l = 0;
	while (i > 0)
	{
        printf("I have str[i]:%c\nLine: %d\n", str[i], __LINE__);
		while (++j < 16)
        {
            printf("I have str[i]:%c\nLine: %d\n", str[i], __LINE__);
            if (base[j] == str[i])
            {
                printf("I have str[i]:%c\nLine: %d\n", str[i], __LINE__);
/*                 while (l < (k - i))
				{
					ret = ret + j * (pow(16, k));
					l++;
                    printf("Line: %d\nj: %d\nk: %d\nrethaaaaa: %d\n", __LINE__, j, k, ret);
				} */
                k = k - i;
				ret = ret + j * (pow(16, k));
				l++;
                printf("Line: %d\nj: %d\nk: %d\nrethaaaaa: %d\n", __LINE__, j, k, ret);
            }
            else
                ;

            /* 
            printf("Line: %d\nj: %d\nk: %d\nret: %d\n", __LINE__, j, k, ret);
			if (str[i] == base[j])
            {
                printf("Line: %d\nj: %d\nk: %d\nret: %d\n", __LINE__, j, k, ret);
				while (k >= 0)
				{
					ret = ret + j * (pow(16, k));
					k--;
                    printf("Line: %d\nj: %d\nk: %d\nret: %d\n", __LINE__, j, k, ret);
				}
            } */
        }
        j = -1;
		i--;
	}
    printf("Line: %d\n", __LINE__);
	return (ret);
}

int main() 
{
  
  char *str;
  int ret;
  
  str = "abcd";
  ret = atox(str);
  
  printf("this is hex: %x\n", ret);

  return 0;
}
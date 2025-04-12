#include "libft.h"

int main(int argc, char **argv)
{
  int i;
  i = 1;

  if (!(argc > 1))
    return (1);
  while (i < argc)
  {
    while (*argv[i])
    {
      if (!(ft_isdigit(*argv[i])))
        return (1);
      argv[i]++;
    }
    i++;
  }
  return (0);
}

#include "libft.h"

int main(int argc, char **argv)
{
  if (argc != 2)
    return (-1);
  return (ft_strlen(argv[1]));
}

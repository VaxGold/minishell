#include "../../parser.h"

void babel_expansions(char *str, t_env env)
{
	int    i;
  char   *temp;
  char   *expand;

  i = 0;
  expand = ft_strdup("");
  temp = ft_strdup("");
	while (str[i] != 0)
  {
    if (str[i] == '$' /*&& !quoted_exp(str, i)*/)
    {
      if (ft_strlen(expand) != 0)
        break;
      expand = ft_strdup("$");
    }
    i++;
  }
  if (check_expand(expand))
    temp = ft_strdup(expand);
  if (itemp_exp > 0)
  {
    //SUSTITUIR
    babel_expansions(str, env);
  }
  free(temp);
  free(expand);
  return;
}

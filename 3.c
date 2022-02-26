/**
 * 最大回文乘积
 */

#include <stdio.h>

int func(int x)
{
  int raw = x, t = 0;
  while (x)
  {
    t = t * 10 + x % 10;
    x /= 10;
  }
  return raw == t;
}

int main()
{
  int ans = 0;
  for (int i = 100; i < 1000; i++)
  {
    for (int j = i; j < 1000; j++)
    {
      int t = i * t;
      if (func(t))
      {
        if (ans < t)
        {
          ans = t;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
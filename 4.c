/**
 *  连续数字最大乘积 滑动窗口 又叫双指针法
 */
#include <stdio.h>

int main()
{
  char str[1005];
  scanf("%d", &str);
  int cnt = 0;
  long long ans = 0, now = 1;
  for (int i = 0; i < 1000; i++)
  {
    if (i < 13)
    {
      now *= str[i] - '0';
    }
    else
    {
      if (str[i] == '0')
      {
        cnt++;
      }
      else
      {
        now *= str[i] - '0';
      }
      if (str[i - 13] == '0')
      {
        cnt--;
      }
      else
      {
        now /= str[i - 13] - '0';
      }
    }
    if (cnt == 0 && ans < now)
    {
      ans = now;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
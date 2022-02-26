/**
 * 偶斐波那契数列
 * 斐波那契数列中的每一项都是前两项的和。由1和2开始生成的斐波那契数列的前项为
 * 1,2,3,5,8,13...
 */

#include <stdio.h>
int num[4000000];
int main()
{
  // 方法一
  // int ans = 2;
  // num[1] = 1;
  // num[2] = 2;
  // for (int i = 3; i; i++)
  // {
  //   num[i] = num[i - 1] + num[i - 2];
  //   if (num[i] >= 4000000)
  //   {
  //     break;
  //   }
  //   if (num[i] % 2 == 0)
  //   {
  //     ans += num[i];
  //   }
  // }

  // 方法二
  int a = 1, b = 2, ans = 0;
  while (b < 4000000)
  {
    if (b % 2 == 0)
    {
      ans += b;
    }
    b += a;
    a = b - a;
  }

  printf("%d\n", ans);
  return 0;
}
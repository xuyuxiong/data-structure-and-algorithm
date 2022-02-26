/**
 * 3或5的倍数
 * 在小于的自然数中，3或5的倍数有3，5，6和9，这些数之和是23。
 * 求小于的自然数中所有或的倍数之和。
 */

#include <stdio.h>

int main()
{
  // 方法一
  // int ans = 0;
  // for (int i = 0; i < 1000; i++)
  // {
  //   if (i % 3 == 0 || i % 5 == 0)
  //   {
  //     ans += i;
  //   }
  // }
  // printf("%d\n", ans);

  // 方法二
  int sum3 = (3 + 999) * 333 / 2;
  int sum5 = (5 + 995) * 199 / 2;
  int sum15 = (15 + 990) * 66 / 2;
  printf("%d\n", sum3 + sum5 - sum15);
  return 0;
}
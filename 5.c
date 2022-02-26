/**
 * 在这个20*20方阵中，四个呈一直线（竖直、水平或对角线）
 * 相邻的数的乘积最大是多少？
 */

#include <stdio.h>
int num[30][30];
int dirx[4] = {-1, 0, 1, 1};
int diry[4] = {1, 1, 1, 0};
int main()
{
  for (int i = 5; i < 25; i++)
  {
    for (int j = 5; j < 25; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }
  int ans = 0;
  for (int i = 5; i < 25; i++)
  {
    for (int j = 5; j < 25; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        int t = num[i][j];
        for (int l = 1; l <= 3; l++)
        {
          int x = i + dirx[k] * l;
          int y = j + diry[k] * l;
          t *= num[x][y];
        }
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
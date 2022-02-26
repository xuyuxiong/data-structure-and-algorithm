/**
 * 线性表又叫顺序表
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 顺序表的插入

// 依次向前移动 插入或者删除

// 实现 顺序表

typedef struct vector // 结构定义
{
  int *data;     // 存储整数
  int size, cap; // 数量 容量上限
} vector;

// 初始化
// 创建
vector *init_vector(int x)
{
  vector *p = (vector *)malloc(sizeof(vector)); // 申请内存空间
  p->data = (int *)malloc(x * sizeof(int));     //
  p->size = 0;
  p->cap = x;
  return p;
}

int insert_ele(vector *v, int ind, int val)
{
  // 判断插入的位置是否合理
  if (ind > v->size)
  {
    return -1; // 插入失败
  }
  // 扩容
  if (v->size == v->cap)
  {
    v->cap *= 2;
    // 改变容量
    v->data = (int *)realloc(v->data, v->cap * sizeof(int));
  }
  // 向后移动
  for (int i = v->size; i > ind; i--)
  {
    v->data[i] = v->data[i - 1];
  }
  v->data[ind] = val;
  v->size += 1;
  return 0;
}

int delete_ele(vector *v, int ind)
{
  if (ind >= v->size)
  {
    return -1;
  }
  for (int i = ind + 1; i < v->size; i++)
  {
    v->data[i - 1] = v->data[i];
  }
  v->size--;
  return 0;
}

void show_vector(vector *v)
{
  printf("v->cap = %d, v->size = %d\n", v->cap, v->size);
  for (int i = 0; i < v->size; i++)
  {
    printf("%d", v->data[i]);
  }
  printf("\n -----------\n");
}

// 销毁
void delete_vector(vector *p)
{
  // 先释放vector data
  free(p->data);

  // 释放vector空间
  free(p);
}

int main()
{
  int n, mmax;
  scanf("%d%d", &n, &mmax);
  vector *v = init_vector(mmax);
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d", &a);
    if (a == 0)
    {
      scanf("%d%d", &b, &c);
      insert_ele(v, b, c); // 在某个位置插入某个元素
    }
    else
    {
      scanf("%d", &b);
      delete_ele(v, b);
    }
    show_vector(v);
  }
  return 0;
}

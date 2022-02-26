#include <stdio.h>
#include <stdlib.h>
/**
 * 单链表 又叫链表 
 * 链表的每个元素的内存空间不连续 中间使用指针连接 
 * 由很多个节点组成
 */

// 定义节点结构
typedef struct node
{
  int data;
  struct node *next;
} node;

// 定义链表结构
typedef struct list
{
  struct node *head; // 虚拟头节点
  int size;
} list;

node *get_new_node(int x)
{
  node *p = (node *)malloc(sizeof(node));
  p->data = x;
  p->next = NULL;
  return p;
}

// 建立空链表
list *init_list()
{
  list *p = (list *)malloc(sizeof(list));
  p->head = get_new_node(0);
  p->size = 0;
  return p;
}

// 删除链表
void delete_list(list *p)
{
  // 不能直接删p
  // 清空链表
  node *q = p->head;
  while (q != NULL)
  {
    node *t = q->next;
    free(q);
    q = t;
  }
  // 最后释放
  free(p);
}

// 插入元素
int insert_ele(list *l, int ind, int val)
{
  if (ind > l->size)
  {
    return -1;
  }
  // 从前向后找
  node *p = l->head;
  for (int i = 0; i < ind; i++)
  {
    p = p->next;
  }
  node *q = get_new_node(val);
  q->next = p->next;
  p->next = q;
  l->size++;
  return 0;
}

int delete_ele(list *l, int ind)
{
  if (ind >= l->size)
  {
    return -1;
  }
  node *p = l->head;
  for (int i = 0; i < ind; i++)
  {
    p = p->next;
  }
  node *q = p->next;
  p->next = q->next;
  free(q);
  l->size--;
  return 0;
}

void show_list(list *l)
{
  printf("list size = %d\n", l->size);
  for (node *p = l->head->next; p != NULL; p = p->next)
  {
    printf("%d -> ", p->data);
  }
  printf("\n----------\n");
}

int main()
{
  int n;
  scanf("%d", &n);
  list *l = init_list();
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d", &a);
    if (a == 0)
    {
      scanf("%d%d", &b, &c);
      insert_ele(l, b, c);
    }
    else
    {
      // 删除
      scanf("%d", &b);
      delete_ele(l, b);
    }
    show_list(l);
  }
  delete_list(l);
  return 0;
}
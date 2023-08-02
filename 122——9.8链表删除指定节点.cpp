// 122——9.8链表删除指定节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
struct Test
{
	int data;
	struct Test* next;
};

void printLink(struct Test* head)
{
	struct  Test* point = head;
	while (point != NULL)
	{
		printf("%d ", point->data);
		point = point->next;
	}
	putchar('\n');
}
int getLinkTotalNumber(struct Test* head)
{
	int count = 0;
	struct  Test* point = head;
	while (point != NULL)
	{
		count++;
		point = point->next;
	}
	return count;
}
struct Test* deleteNode(struct Test* head, int data)
{
	struct  Test* point = head;
	if (point->data == data)
	{
		head = head->next;
		return head;
	}
	while (point->next != NULL)
	{
		printf("data=%d  point=%d\n\n", data, point->next->data);
		if (point->next->data == data)
		{
			struct Test* tmp= (struct Test*)malloc(sizeof(struct Test* ));

			point->next = point->next->next;
			free(tmp);//释放被删除的节点指向的内存
			printf("找到了data，删除成功\n");
			return head;
		}
		point = point->next;
	}
	printf("没有找到data插入失败\n");
	return head;
}
int main()
{
	int i;

	int find;
	struct Test t1 = { 1,NULL };
	struct Test t2 = { 2,NULL };
	struct Test t3 = { 3,NULL };
	struct Test t4 = { 4,NULL };
	struct Test t5 = { 5,NULL };
	struct Test t6 = { 6,NULL };


	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
	t5.next = &t6;
	t6.next = NULL;//不写这一行也可以，因为t6的next不存在，所以，pointer成为了悬空指针指向了空，所以没必要写这一行
	struct Test niu = { 100,NULL };

	printf("你想删除哪个数字 1 2 3 4 5 6\n\n");
	scanf_s("%d", &find);
	struct Test* head = deleteNode(&t1, find);

	printf("成功在链表里面删除了%d个数字\n",6- getLinkTotalNumber(head));

	printLink(head);


	return 0;
}
#include <stdio.h>

typedef int TElemType;

typedef enum
{	
	/* Link: 0.ָ�����Һ���ָ�� Thread:1 ��ʾָ��ǰ������������� */
	Link,
	Thread
}PointerTag;

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild,rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre;

void InThreading(BiThrTree p)
{
	if(p)
	{
		/* �ݹ��������������� */
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}

		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}

		pre = p;

		/* �ݹ������������� */
		InThreading(p->rchild);
	}
}

/*
* ����������ʵ��Դ��
*/
int main(int argc,char *argv[])
{
	
	

	return 0;
}

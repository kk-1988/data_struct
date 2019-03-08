#include <stdio.h>

typedef int TElemType;

typedef enum
{	
	/* Link: 0.指向左右孩子指针 Thread:1 表示指向前驱或后驱的线索 */
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
		/* 递归左子树的线索华 */
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

		/* 递归右子树线索化 */
		InThreading(p->rchild);
	}
}

/*
* 线索二叉树实现源码
*/
int main(int argc,char *argv[])
{
	
	

	return 0;
}

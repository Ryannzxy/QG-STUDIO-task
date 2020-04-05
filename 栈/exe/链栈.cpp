#include <stdio.h>
#include <stdlib.h> 
#include <C:\Users\17226\Desktop\QG训练营\第二次\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h>
#define max 100

int main()
{
	ElemType data;
	ElemType e;
	LinkStack s;
	int length;
	int a[8];
	int i;
	initLStack(&s);
	printf("请输入链栈的值\n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&data);
		pushLStack(&s,data);
	}
	popLStack(&s,&data);
	printf("pop弹出的元素为:%d\n",data);
	printf("将刚刚弹出的元素%d再次压入\n",data);
	pushLStack(&s,data);
	printf("isEmptyLStack判断栈是否为空:%d(1:yes  0:no)\n",isEmptyLStack(&s));
	getTopLStack(&s,&e);
	printf("getTopLStack当前栈顶元素%d\n",e);
	printf("当前栈的长度为:%d\n",LStackLength(&s,&length));
	printf("清空当前栈\n");
	clearLStack(&s);
	printf("判断栈是否为空%d(1:yes  0:no)\n",isEmptyLStack(&s));
	destroyLStack(&s);
	printf("该栈已被销毁\n");
	return 0;
}

Status initLStack(LinkStack *s)//初始化栈
{
	s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = NULL;
}

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if(s->top = NULL)
		return SUCCESS;
	else
		return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	if(s->top == NULL)
	{
		printf("该栈为空栈");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)//清空栈
{
	s->top ==NULL;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)//销毁栈
{
	if(s->top == 0)
	{
		printf("该栈是空栈");
		return ERROR; 
	}
	else
	{
		s->top == NULL;
	}
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length = s->top->data;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	LinkStackPtr p;
	if(s == NULL)
	{
		printf("该栈是空栈");
		return ERROR;
	}
	*data = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

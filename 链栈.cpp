#include <stdio.h>
#include <stdlib.h> 
#include <C:\Users\17226\Desktop\QGѵ��Ӫ\�ڶ���\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h>
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
	printf("��������ջ��ֵ\n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&data);
		pushLStack(&s,data);
	}
	popLStack(&s,&data);
	printf("pop������Ԫ��Ϊ:%d\n",data);
	printf("���ոյ�����Ԫ��%d�ٴ�ѹ��\n",data);
	pushLStack(&s,data);
	printf("isEmptyLStack�ж�ջ�Ƿ�Ϊ��:%d(1:yes  0:no)\n",isEmptyLStack(&s));
	getTopLStack(&s,&e);
	printf("getTopLStack��ǰջ��Ԫ��%d\n",e);
	printf("��ǰջ�ĳ���Ϊ:%d\n",LStackLength(&s,&length));
	printf("��յ�ǰջ\n");
	clearLStack(&s);
	printf("�ж�ջ�Ƿ�Ϊ��%d(1:yes  0:no)\n",isEmptyLStack(&s));
	destroyLStack(&s);
	printf("��ջ�ѱ�����\n");
	return 0;
}

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = NULL;
}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s->top = NULL)
		return SUCCESS;
	else
		return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(s->top == NULL)
	{
		printf("��ջΪ��ջ");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)//���ջ
{
	s->top ==NULL;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)//����ջ
{
	if(s->top == 0)
	{
		printf("��ջ�ǿ�ջ");
		return ERROR; 
	}
	else
	{
		s->top == NULL;
	}
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length = s->top->data;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	LinkStackPtr p;
	if(s == NULL)
	{
		printf("��ջ�ǿ�ջ");
		return ERROR;
	}
	*data = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

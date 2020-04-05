#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\17226\Desktop\QGѵ��Ӫ\�ڶ���\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h>
#define max 100

int main()
{
	ElemType data;
	ElemType e;
	int i;
	int sizes;
	int length;
	SqStack s;
	initStack(&s,sizes);
	printf("������˳��ջ��ֵ:\n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&data);
		pushStack(&s,data);
	}
	popStack(&s,&data);
	printf("pop������Ԫ��Ϊ:%d\n",data);
	printf("���ոյ�����Ԫ��%d�ٴ�ѹ��\n",data);
	pushStack(&s,data);
	printf("isEmptyStack�ж�ջ�Ƿ�Ϊ��:%d(1:yes  0:no)\n",isEmptyStack(&s));
	getTopStack(&s,&e);
	printf("getTopStack��ǰջ��Ԫ��%d\n",e);
	printf("��ǰջ�ĳ���Ϊ:%d\n",stackLength(&s,&length));
	printf("��յ�ǰջ");
	clearStack(&s);
	printf("�ж�ջ�Ƿ�Ϊ��%d(1:yes  0:no)\n",isEmptyStack(&s));
	destroyStack(&s);
	printf("��ջ�ѱ�����");
	return 0;
}

Status initStack(SqStack *s,int sizes)//��ʼ��ջ 
{
	if(s!=NULL)
	{
		s->top = -1;
		return SUCCESS;
	}
	else
	{
		int sizes = 0;
	    return ERROR; 
	} 
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ�� 
{
	if(s->top = -1)
		return SUCCESS;
	else
		return ERROR;
} 

Status getTopStack(SqStack *s,ElemType *e)//�õ�ջ��Ԫ�� 
{
	if(s->top = -1)
	{
	    return ERROR;
	}
	else
	{
		*e = s->top;
		return SUCCESS;
	}  
}

Status clearStack(SqStack *s)//���ջ
{
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	if(s->top = -1)
    {
    	printf("��ջ�ǿ�ջ");
    	return ERROR;
	}
	else 
	{
		s->top = -1;
	}
	free(s);
	return SUCCESS;			
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length = s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(s->top >=max)
	{
		printf("��ջ����");
		return ERROR; 
	}
	else
	{
		s->top = data;
		s->top++;
		return SUCCESS;
	}
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(s->top = -1)
	{
		printf("��ջ�ǿ�ջ");
		return ERROR;
	}
	else
	{
		*data = s->top;
		s->top--;
		return SUCCESS;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\17226\Desktop\QG训练营\第二次\栈以及栈的应用\栈\代码和头文件\head\SqStack.h>
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
	printf("请输入顺序栈的值:\n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&data);
		pushStack(&s,data);
	}
	popStack(&s,&data);
	printf("pop弹出的元素为:%d\n",data);
	printf("将刚刚弹出的元素%d再次压入\n",data);
	pushStack(&s,data);
	printf("isEmptyStack判断栈是否为空:%d(1:yes  0:no)\n",isEmptyStack(&s));
	getTopStack(&s,&e);
	printf("getTopStack当前栈顶元素%d\n",e);
	printf("当前栈的长度为:%d\n",stackLength(&s,&length));
	printf("清空当前栈");
	clearStack(&s);
	printf("判断栈是否为空%d(1:yes  0:no)\n",isEmptyStack(&s));
	destroyStack(&s);
	printf("该栈已被销毁");
	return 0;
}

Status initStack(SqStack *s,int sizes)//初始化栈 
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

Status isEmptyStack(SqStack *s)//判断栈是否为空 
{
	if(s->top = -1)
		return SUCCESS;
	else
		return ERROR;
} 

Status getTopStack(SqStack *s,ElemType *e)//得到栈顶元素 
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

Status clearStack(SqStack *s)//清空栈
{
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
	if(s->top = -1)
    {
    	printf("该栈是空栈");
    	return ERROR;
	}
	else 
	{
		s->top = -1;
	}
	free(s);
	return SUCCESS;			
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	*length = s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	if(s->top >=max)
	{
		printf("该栈已满");
		return ERROR; 
	}
	else
	{
		s->top = data;
		s->top++;
		return SUCCESS;
	}
}

Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(s->top = -1)
	{
		printf("该栈是空栈");
		return ERROR;
	}
	else
	{
		*data = s->top;
		s->top--;
		return SUCCESS;
	}
}

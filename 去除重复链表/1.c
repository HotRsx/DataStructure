#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * link;
}Linknode;
void dele(Linknode * T)//ɾ���ظ������㷨
{
    Linknode * p,* q,* r;
    p=T->link;
    while(p)    // p���ڱ�������
    {
         q=p;
         while(q->link) // q����p����Ľ�㣬����p��ֵ�Ƚ�
         {
             if(q->link->data==p->data)
             {
                 r=q->link; // r������Ҫɾ���Ľ��
                 q->link=r->link;   // ��Ҫɾ���Ľ���ǰ�������
                 free(r);
             }
             else
                 q=q->link;
         }
         p=p->link;
    }
}
int main()
{
	Linknode * p1,* p2,*first;
	p1=p2=(Linknode *)malloc(sizeof(Linknode));
	first=NULL;
	do{
		if(first==NULL)
			first=p1;
		else
			p2->link=p1;
		p2=p1;
		p1=(Linknode *)malloc(sizeof(Linknode));
		scanf("%d",&p1->data);
	    p1->link=NULL;
	}while(p1->data>0);
	dele(first);
	while(first->link!=NULL)
	{
		first=first->link;
		printf("%d\t",first->data);
	}
	return 0;
}
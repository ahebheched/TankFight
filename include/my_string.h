#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define rep(i,s,t) for(int i=s;i<=t;i++)//简化写法
#define N 100

//用链表储存字符数组
void read(struct Node* head, char a[]);//输入Node指针和字符数组，指针就可以代替数组
int size_(struct Node *head);//输入字符数组，返回大小
bool check(struct Node *head1,struct Node *head2);//输入两个指针，检查是否相等，相等为一，不等为零

struct Node{
    char s;//储存字符
    int len;
    struct Node *next;
};

void create(struct Node* head,char x)
{
    printf("0\n");
    struct Node *p=head;
    while(p->next!=NULL)p=p->next;
    p->next=(struct Node*)malloc(sizeof(struct Node));
    p=p->next;
    p->s=x;
    p->next=NULL;
}
//读入
void read(struct Node* head, char a[])
{
    int i,num=strlen(a);
    head->len=num;
    printf("%s\n",a);
    for(i=0;i<num;i++)
    {
        create(head,a[i]);
    }
}

void pri(struct Node *head)
{
    struct Node *p=head;
    while(p->next!=NULL)
    {p=p->next;
        printf("%c",p->s);

    }
}
//查询每个节点上的数值
char at_link_(struct Node *head,int index)
{
    struct Node *p=head;
    while(index--)//因为第index位之前有index个数字，所以要向后找寻index次
    {
        p=p->next;
    }
    return p->s;
}
//返回大小
int size_(struct Node *head)
{
    return head->len;
}

//返回字符串之间的关系，相等为一，不等为零
bool check(struct Node *head1,struct Node *head2)
{
    int s1=size_(head1),s2=size_(head2);
    struct Node *p1=head1,*p2=head2;
    if(s1!=s2)return 0;
    while(s1--)
    {
        if(p1->s==p2->s)continue;
        else return 0;
    }
    return 1;
}
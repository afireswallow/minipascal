#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"

/****************************************
  root�ڵ���ȫ�ֱ�����������Ҫʹ�õĵط�
�趨��Ϊextern struct node root��
*****************************************/
struct node root;/*����AST�ĸ��ڵ㡣�ýڵ㲻������
                   �ֵܽڵ㣬��root.next==NULL*/


/***************************************
  init_node���������nd�ڵ���г�ʼ��
****************************************/
int init_node(struct node *nd)
{
    if(NULL==nd)
        return NULL_NODE_POINTER;
    else if(nd!=NULL)
    {
        nd->type=e_null_node;
        nd->val.str=NULL;
        nd->son=NULL;
        nd->parent=NULL;
        nd->next=NULL;
    }
    return INIT_NODE_SUCCESS;
};


/************************************************
  ����ֵܽڵ�ʱ��ֻ�ܴ�parent->son����ʼ���
*************************************************/
int add_son_node(struct node *parent, struct node *son)
{
    if(NULL!=parent && NULL!=son)
    {
        if(parent->son==NULL)/*parent��û������ӽڵ�*/
        {
            parent->son=son;
        }
        else/*parent�Ѿ��������ӽڵ㣬��son��ӵ�������ĩβ*/
        {
            struct node *tmp_node=parent->son;
            
            while(NULL!=tmp_node->next)
            {
                tmp_node=tmp_node->next;
            }/*��ѭ������������һ���ֵܽڵ�*/
            
            tmp_node->next=son;/*���son���Ѿ�ʶ�������
                                 һ�����У���son��������
                                 �ֵܽڵ㡣�ʴ˴�����Ҫ��
                                 son->next����ΪNULL*/
            son->parent=parent;/*����son��parent��ӳ���ϵ*/
            tmp_node->next=son;
        }
        return ADD_SON_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
    
    return ADD_SON_NODE_SUCCESS;
}

/***********************************************
    ������Ϊbrother�ڵ���Ӻ����ֵܽڵ㣬����
�����ֵܵ�parent�������á�
************************************************/
int add_brother_node(struct node *last, struct node *new_brother)
{
    if(NULL!=last && NULL!=new_brother)
    {
        struct node *tmpparent=NULL;
        if(NULL==last->parent)
        {
            return ADD_BROTHER_TO_NODE_WITHOUT_PARENT;
        }
        else
        {
            last->next=new_brother;
            new_brother->parent=last->parent;
        }
        return ADD_BROTHER_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
}

/************************************************
 set_node_val_str�������ڵ�nd->val.str�����ַ���
*************************************************/
int set_node_val_str(struct node *nd, char *str)
{
    if(NULL==nd || NULL==str)
        return NULL_NODE_POINTER;
    else
    {
        if(NULL!=nd->val.str)
            free(nd->val.str);
        nd->val.str=(char *)malloc(strlen(str)+1);
        strcpy(nd->val.str,str);
        
        return SET_NODE_VAL_STR_SUCCESS;
    }
    
    return SET_NODE_VAL_STR_SUCCESS;
}

/************************************************
    ������ͨ��result�������ؽ������������ֵ
���ڱ�ʾ�ɹ����
*************************************************/
int get_son_node(struct node *parent, struct node **result)
{
    if(NULL!=parent && NULL!=result)
    {
        *result=parent->son;
        return GET_SON_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
}


int get_next_brother_node(struct node *cur_nd, struct node **result)
{
    if(NULL!=cur_nd && NULL!=result)
    {
        *result=cur_nd->next;
        return GET_NEXT_BROTHER_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
    
    return GET_NEXT_BROTHER_NODE_SUCCESS;
}

int new_node(struct node **result)
{
    if(NULL!=result)
    {
        *result=(struct node *)malloc(sizeof(struct node));
        if(init_node(*result)==INIT_NODE_SUCCESS)
            return NEW_NODE_SUCCESS;
        else
            return MEMORY_ALLOC_ERROR;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
    
    return NEW_NODE_SUCCESS;
}

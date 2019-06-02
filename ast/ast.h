
#ifndef _AST_H_
#define _AST_H_

#define NULL_NODE_POINTER     500
#define INIT_NODE_SUCCESS     501
#define ADD_SON_NODE_SUCCESS  502
#define SET_NODE_VAL_STR_SUCCESS  503
#define GET_SON_NODE_SUCCESS  504
#define ADD_BROTHER_NODE_SUCCESS  505
#define ADD_BROTHER_TO_NODE_WITHOUT_PARENT  506
#define GET_NEXT_BROTHER_NODE_SUCCESS  507
#define NEW_NODE_SUCCESS  508
#define MEMORY_ALLOC_ERROR  509

enum node_type
{
	e_null_node,
	e_program, e_sub_prog, e_var_def, e_type_int, e_type_real,
	e_varlist, e_compstat, e_if_then_stat, e_bool_exp,
	e_exp, e_if_then_else_stat, e_assign_stat, e_while_stat,
	e_math_op, e_relation_op, e_statement
};

struct node_val
{
	char *str;
};

struct node
{
	enum node_type type;
	struct node_val val;
	struct node *son;/*��¼���ڵ�ĵ�һ���ӽڵ㡣
	                   �����ӽڵ�ͨ���Ը��ֽڵ�
	                   ��next������ɨ������á�*/
	struct node *parent;
	struct node *next;/*��¼���ڵ����һ���ֵܽڵ㡣
	                   ���ڵ��parent�ڵ��son_list
	                   ָ�������ֵ����ĵ�һ��Ԫ�ء�*/
};

extern int init_node(struct node *nd);
extern int add_son_node(struct node *parent, struct node *son);
extern int add_brother_node(struct node *last, struct node *new_brother);
extern int set_node_val_str(struct node *nd, char *str);
extern int get_son_node(struct node *parent, struct node **result);
extern int get_next_brother_node(struct node *cur_nd, struct node **result);
extern int new_node(struct node **result);


#endif

/*链表：线性表，逻辑上是连续的，物理存储结构是一组任意的存储单元，通常有一个表头，表末尾指针域要置空，*/

/*链表结点*/
typedef struct node {
	ElemType data;
	struct node *next
}LNode,*LinkList;

/*创建链表*/
LinkList CreatLinkList(int n) {
	//建立长度为n的链表
	LinkList p, r, list = NULL;
	ElemType e;
	int i;
	for (i = 1;1 <= n;i++) {
		Get(e);
		p = （LinkList）malloc(sizeof(LNode));
		p->data = e;
		p->next = NULL;
		if (!list)
			list = p;
		else
			r->next = p;
		r = p;
	}
	return list;
}
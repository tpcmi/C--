/*�������Ա��߼����������ģ�����洢�ṹ��һ������Ĵ洢��Ԫ��ͨ����һ����ͷ����ĩβָ����Ҫ�ÿգ�*/

/*������*/
typedef struct node {
	ElemType data;
	struct node *next
}LNode,*LinkList;

/*��������*/
LinkList CreatLinkList(int n) {
	//��������Ϊn������
	LinkList p, r, list = NULL;
	ElemType e;
	int i;
	for (i = 1;1 <= n;i++) {
		Get(e);
		p = ��LinkList��malloc(sizeof(LNode));
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
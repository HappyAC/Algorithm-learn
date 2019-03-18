#include<iostream>

/*
 * Ԥ���峣�� 
 */
// �������״̬����

#define OK 1
#define ERROR 0
#define OVERFLOW -2 

// ����󳤶� 
#define MAXSIZE 100

using namespace std;

/*
 * ���Ա��˳��洢ʵ�� 
 */


// Ԫ�ؽṹ 
typedef struct ElemType {
	int data;
};

// �洢�ṹ
typedef struct {
	// ��Ա���� 
	ElemType *elem;
	int length;
	
	// ����
	int InitList(); 
	int GetElem(int i, ElemType &e); 
	int LocateELem (ElemType e);
	int Insert(int i, ElemType e);
	int Delete(int i);
	void Traverse();
} SqList;

// ˳���
int SqList::InitList() {
	elem = new ElemType[MAXSIZE]; // ����ռ�
	if (!elem) exit(OVERFLOW); // �洢����ʧ��
	length = 0;
	return OK; 
}

// ȡָ��λ��i����Ԫ�� 
int SqList::GetElem(int i, ElemType &e) {
	if (i < 1 || i > length) return ERROR;
	e = elem[i-1];
	return OK;
}

// ����Ԫ��e��λ�� 
int SqList::LocateELem(ElemType e) {
	for (int i = 0; i < length; i++) {
		if (elem[i].data == e.data) return i + 1;
	}
	
	return 0;
}

// ����Ԫ��e��ָ��λ��i�� 
int SqList::Insert(int i, ElemType e) {
	if (i < 1 || i > length + 1) return ERROR;
	if (length == MAXSIZE) return ERROR;
	
	for (int j = length - 1; j >= i - 1; j--) {
		elem[j + 1] = elem [j];
	}
	elem[i - 1] = e;
	length++;
	return OK;
}

// ɾ��ָ��λ��i��Ԫ��
int SqList::Delete(int i) {
	if (i < 1 || i > length) return ERROR;
	for (int j = i; j < length; j++) {
		elem[j - 1] = elem[j];
	}
	
	length--;
	return OK;
}
// ���� 
void SqList::Traverse() {
	for (int i = 0; i < length; i++) {
		if (i != 0) cout << " ";
		cout << elem[i].data;
	}
	cout << endl;
}




int main () {
	int
		 N
		,n
		,flag
		;
	ElemType target;
	ElemType *temp;
	SqList list;
	
	cin >> N;
	while (N--) {
		list.InitList();
		cin >> n;
		for (int i = 0; i < n; i ++) {
			temp = new ElemType;
			cin >> temp -> data;
			list.Insert(i + 1, *temp);
		}
		cin >> target.data;
		flag = 0;
		if (target.data <= list.elem[0].data) {
			list.Insert(1, target);
			list.Traverse();
			continue;
		}
		for (int i = 1; i < n; i++) {
			if (target.data >= list.elem[i - 1].data && target.data <= list.elem[i].data) {
				list.Insert(i + 1, target);
				flag = 1;
				break;
			}
		}
		if (!flag) list.Insert(list.length + 1, target);
		list.Traverse();
	}
	return 0; 
}













































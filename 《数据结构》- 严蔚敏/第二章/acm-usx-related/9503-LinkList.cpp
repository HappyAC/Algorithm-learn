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
	void Clear();
	void Traverse();
	void Reverse();
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

void SqList::Clear() {
	delete(elem);
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

// ����˳��� 
void SqList::Reverse() {
	ElemType tmp;
	for (int i = 0; i < length/2; i++) {
		tmp.data = elem[i].data;
		elem[i].data = elem[length - i - 1].data;
		elem[length - i - 1].data = tmp.data;
	}
}




int main () {
	int n;
	SqList List;
	ElemType tmp;
	while(cin >> n) {
		List.InitList();
		
		for (int i = 0; i < n; i++) {
			cin >> tmp.data;
			
			List.Insert(i + 1, tmp);
		}
		List.Reverse();
		List.Traverse();
	}
	
	return 0; 
}













































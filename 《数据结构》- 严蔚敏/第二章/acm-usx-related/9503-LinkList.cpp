#include<iostream>

/*
 * 预定义常量 
 */
// 函数结果状态代码

#define OK 1
#define ERROR 0
#define OVERFLOW -2 

// 表最大长度 
#define MAXSIZE 100

using namespace std;

/*
 * 线性表的顺序存储实现 
 */


// 元素结构 
typedef struct ElemType {
	int data;
};

// 存储结构
typedef struct {
	// 成员变量
	ElemType *elem;
	int length;
	
	// 方法
	int InitList(); 
	int GetElem(int i, ElemType &e); 
	int LocateELem (ElemType e);
	int Insert(int i, ElemType e);
	int Delete(int i);
	void Clear();
	void Traverse();
	void Reverse();
} SqList;

// 顺序表
int SqList::InitList() {
	elem = new ElemType[MAXSIZE]; // 分配空间
	if (!elem) exit(OVERFLOW); // 存储分配失败
	length = 0;
	return OK; 
}

// 取指定位置i处的元素 
int SqList::GetElem(int i, ElemType &e) {
	if (i < 1 || i > length) return ERROR;
	e = elem[i-1];
	return OK;
}

// 查找元素e的位置 
int SqList::LocateELem(ElemType e) {
	for (int i = 0; i < length; i++) {
		if (elem[i].data == e.data) return i + 1;
	}
	return 0;
}

// 插入元素e到指定位置i上 
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

// 删除指定位置i的元素
int SqList::Delete(int i) {
	if (i < 1 || i > length) return ERROR;
	for (int j = i; j < length; j++) {
		elem[j - 1] = elem[j];
	}
	
	length--;
	return OK;
}

// 遍历 
void SqList::Traverse() {
	for (int i = 0; i < length; i++) {
		if (i != 0) cout << " "; 
		cout << elem[i].data;
	}
	cout << endl;
}

// 逆序顺序表 
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













































#include<iostream>

using namespace std;

// Queue
typedef	struct queue{

	int q[100];
	int rear;
	int front;

	void initQueue(){
		front = 0;
		rear = 0;
		int i = 0;
		for (i = 0; i < 100; i++)
			q[i] = 0;


	}
	int enQueue(int a){

		if (front == 100){
			//printf("Full Queue\n");
			return -1;
		}

		q[front++] = a;

		return 0;
	}

	int deQueue(){

		int redata;
		//printf("%d , %d \n", rear, front);
		if (front == rear){
			printf("Empty Queue \n");
			return -1;
		}
		

		redata = q[rear++];

		return redata;
	}

	int isEmpty(){
		if (front == rear)
			return -1;
		else
			return 0;
	}

}Queue;

// Stack
typedef struct stack{

	int s[100];
	int top;

	void initStack()
	{
		top = 0; 
		for (int i = 0; i < 100; i++)
			s[i] = -1;
	}

	int push(int a){

		if (top == 100){
			printf("Stack Full \n");
			return -1;
		}

		s[top++] = a;

		return 0; 
	}

	int pop()
	{
		int retdata;

		if (top == 0){
			printf("Stack Empty \n");
			return -1;
		}

		retdata = s[--top];
		s[top] = -1;

		//printf("t- %d / ", top);
		return retdata; 
	}

	int isEmpty(){
		if (top == 0)
			return -1;
		else
			return 0;
	}

}Stack;

// SLL
struct Node{

	int data; 
	Node * next;
};

void addNode(int a, Node * head){

	Node * temp ;
	Node * newNode = (Node*)malloc(sizeof(Node));

	printf(" add %d \n ", a);
	newNode->data = a;
	newNode->next = NULL;

	temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

}

void delNode(int a, Node * head){
	
	if (head->next == NULL){
		printf("empty sll\n");
		return;
	}

	Node * delNode;
	Node * nowNode;

	delNode = head->next;
	nowNode = head;
	

	while (delNode->data != a){
		//printf("%d", delNode->data);
		delNode = delNode->next;
		nowNode = nowNode->next;
	}

	nowNode->next = delNode->next;
	delNode->next = NULL;
	free(delNode);

}

void showSLL(Node * head){

	Node * temp ;
	temp = head;

	while (temp->next != NULL){
		
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf("%d \n", temp->data);
}

int heap[100];
int idx;

void initHeap(){
	idx = -1;
	for (int i = 0; i < 100; i++)
		heap[i] = -1;
}
int getParentIdx(int i){
	if (i % 2 != 0)
		return (i / 2) - 1;
	else
		return i / 2;

}
int getLeftChild(int i){
	return i * 2 + 1;
}
int getRightChild(int i){
	return i * 2 + 2;
}
void insertHeap(int a){
	int i;
	int pidx;
	int temp; 
	heap[++idx] = a; 

	if (idx == 100)
		return;

	i = idx;
	while ((i != 0) && (heap[i]<heap[pidx = getParentIdx(i)] )){

		temp = heap[i];
		heap[i] = heap[pidx];
		heap[pidx] = temp;
		i = pidx;
	}

}

int popHeap(){
	int i=0; 
	int cIdx, rIdx, lIdx;
	int result = heap[0];
	int temp;

	heap[0] = heap[idx];
	heap[idx--] = -1;

	while (true){
		// 우선순위가 높은 놈 가져오기 
		rIdx = getRightChild(i);
		lIdx = getLeftChild(i);

		cIdx = (heap[lIdx] < heap[rIdx]) ? lIdx : rIdx;

		printf("%d / %d", i, cIdx);

		if (heap[cIdx]<1)
			break;

		if (heap[i]>heap[cIdx]){
			temp = heap[i];
			heap[i] = heap[cIdx];
			heap[cIdx] = temp;
			i = cIdx;
		}
		else{
			break;
		}

	}

	return result;
}

void sortHeap(int i){

	int pIdx = getParentIdx(idx);
	int temp;
	
	if (i == 0)
		return ;

	if (heap[pIdx] > heap[i]){
		temp = heap[i];
		heap[i] = heap[pIdx];
		heap[pIdx] = heap[i];

		i = pIdx;
	}

	sortHeap( i);

}

int tree[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
 -1};

int route [10][10] = { { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
					{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
					{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
					{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
					{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
					{ 0, 0, 0, 0, 0, 1, 1, 0, 1, 0 }, };


int main(){
	
	// BFS Tree // Queue
	Queue q;

	int i = 0;
	q.initQueue();

	// 넣고 
	q.enQueue(tree[i]);
	while (q.isEmpty() > -1){
		i = q.deQueue();
		// 꺼내고
		printf("%d -> ", i);
		// 자식 있는지 확인 있으면 넣기 
		// 왼쪽 자식 
		if (tree[i * 2 + 1] > 0)
			q.enQueue(tree[i * 2 + 1]);
		// 오른쪽 자식 
		if (tree[i * 2 + 2] > 0)
			q.enQueue(tree[i * 2 + 2]);

	}
	
	// DFS Tree
	
	Stack s; 

	int i = 0; 
	
	s.initStack();

	s.push(tree[i]);

	while (s.isEmpty()>-1){
		//꺼내기

		i = s.pop();

		printf("%d ->", i);
		//자식 있으면 넣기 
		// 오른쪽 자식 
		if (tree[i * 2 + 2] > 0)
			s.push(i * 2 + 2);
		// 왼쪽 자식 
		if (tree[i * 2 + 1] > 0)
			s.push(i * 2 + 1);
		
	}
	

	// BFS Graph
	
	int check[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int i = 0;

	Queue q;

	q.initQueue();

	q.enQueue(route[0][0]);

	while (q.isEmpty() > -1){
		i = q.deQueue();

		if (check[i] > 0)
			continue;

		printf("%d -> ", i);

		check[i] = 1;

		//자식 다 넣기
		for (int j = 0; j < 10; j++){
			if ((route[i][j] > 0) && (check[j]<0))
				q.enQueue(j);
		}
	}
	
	// DFS Graph
	
	int check[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int i = 0;

	Stack s;

	s.initStack();

	s.push(route[0][0]);

	while (s.isEmpty() > -1){
		i = s.pop();

		if (check[i] > 0)
			continue;

		printf("%d -> ", i);

		check[i] = 1;

		//자식 다 넣기
		for (int j = 0; j < 10; j++){
			if ((route[i][j] > 0) && (check[j] < 0) )
				s.push(j);
		}
	}
	

	// Heap 


	// SLL
	Node * head = (Node*)malloc(sizeof(Node));

	head->data = -1;
	head->next = NULL;

	for (int i = 0; i < 10; i++)
		addNode(i, head);

	showSLL(head);

	delNode(3, head);
	
	showSLL(head);
	
	
	//Stack
	
	Stack s;

	s.initStack();

	for (int i = 0; i < 12; i++)
		s.push(i);

	for (int i = 0; i < 12; i++)
		printf("%d\n", s.pop());

		
		
	//Queue
	Queue q;

	q.initQueue();

	for (int i = 0; i < 12; i++)
		q.enQueue(i);

	for (int i = 0; i < 12; i++)
		printf("%d\n", q.deQueue());

		
	
	int * a;
	int ** b;
	int size;

	cout << "배열의 크기를 입력하시오" << endl;
	cin >> size;

	a = (int*)malloc(sizeof(int*)*size);

	for (int i = 0; i < size; i++){
		a[i] = i;
	}

	for (int i = 0; i < size; i++){
		cout << a[i] << endl;
	}
	free(a);

	cout << "일차원 배열 끝" << endl;
	cout << "이차원 배열 시작" << endl;
	cout << "배열의 크기를 입력하시오" << endl;
	cin >> size;
	
	b = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++){
		b[i] = (int*)malloc(sizeof(int*)*size);
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			b[i][j] = i * 10 + j;
		}
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << b[i][j] + " " ;
		}
		cout << "" << endl;
	}
	free(b);
	
	return 0;
}
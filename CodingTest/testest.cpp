#include <iostream>

using namespace std;
class Person{

public :
	void Sleep(){
	cout << "Person : sleep" << endl;
	}
};

class Student : public Person
{
	int i; 

public : 
	Student(){
		i = 555;
	}
	void Study(){
		cout << "Student : study " << i << endl;
	}
};

class Point{
private : 
	int x, y;
public : 

	Point(int _x = 0 , int _y =0 ) :x(_x), y(_y)
	{

	}
	void showPosition()
	{
		cout << x << ", " << y << endl;
	}

/*	void operator+(Point &p){
		y = y + p.y;
		x = x + p.x;
	}
	*/
	/*
	Point operator+(Point &p){

		Point temp(x + p.x, y + p.y);
		return temp;
	}*/
	/*
	void operator++(){
		x++; 
		y++;
	}
	*/
	Point & operator++(){
		x++;
		y++;

		return *this;
	}
};

struct Body
{
	int weight;
	int height;
};
struct Node
{
	int data;
	Node * next;
};

void addToSLL(int a, Node * head){

	Node * temp = (Node *)malloc(sizeof(Node));
		Node * newNode = (Node *)malloc(sizeof(Node));
		temp = head;

		while (temp->next != NULL){
			temp = temp->next;
		}

		temp->next=newNode;
		newNode->data = a; 
		newNode->next = NULL;
	
}

void delToSLL(int a, Node * head){

	if (head->next == NULL)
		return ;

	
	Node * delNode;
	Node * nowNode;
	delNode = head->next;
	nowNode = head;

	while (delNode->data != a){		
			delNode = delNode->next;
			nowNode = nowNode->next;
	}
	nowNode->next = delNode->next;
	free(delNode);
	
}
class MyClass{
	int *i;
public: 
	MyClass(){
	i = new int[10];
	}
	~MyClass(){
		delete i;
	}
};

class abc
{

public :
	void abca(int a){
		cout << "1"<<endl;
	}
	void abca(int a, int b){
		cout << "2" << endl;
	}
	int abca(int a, int c, int b){

		cout << "3" << endl;
		return 0;
	}
	// 컴파일은 되지만 오버로딩이 안된다 오버로딩은 오직 함수명과 인풋값으로만
};
int main(){

	
	int *y; 
	y = new int[5];

	delete y;

	Body a;
	a.weight = 60;
	a.height = 170;

	Body * b;
	b = new struct Body[5];
	Body * c;
	c = new struct Body;

	b[0].height;

	c->height;

	Node * head;
	head = (Node *)malloc(sizeof(Node));

	head->data = 0;
	head->next = NULL;

	for (int i = 0; i < 10; i++){
		addToSLL(i+1 , head);
	}

	Node * temp;
	temp = (Node *)malloc(sizeof(Node));
	/*
	temp = head;
	while (temp->next != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << temp->data << endl;
	*/

	delToSLL(7, head);

	cout << "-----------" << endl;
	temp = head->next;
	while (temp->next != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << temp->data << endl;

	delToSLL(3, head);

	cout << "-----------" << endl;
	temp = head->next;
	while (temp->next != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << temp->data << endl;

	addToSLL(16, head);

	cout << "-----------" << endl;
	temp = head->next;
	while (temp->next != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << temp->data << endl;

	//cout << a.weight << endl;
	//cout << a.height << endl;
	/*
	Person o;

	Person *p1 = &o;
	Student *s1 = (Student * ) &o;

	//p1->Sleep();
//	s1->Study();


	Point pp; 
	Point qq(20, 30);
	//Point r = pp + qq;
	//r.showPosition();

	(qq++)++;


	int v1, v2;

	cout << "첫 번째 숫자를 입력하세요 : ";
	cin >> v1;
	cout << "두 번째 숫자를 입력하세요 : ";
	cin >> v2;

	cout << " 합은 " << v1 + v2 << endl;

	*/
	return 0; 
}
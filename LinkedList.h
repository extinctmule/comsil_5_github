#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <string>
using namespace std;

// LinkedList Node
template <class T>
class Node
{
public:
	// 데이터를 저장할 변수
	int data;
	// 노드구조체 이용; 다음노드의 주소를 저장할 포인터
	Node<T> *link;

	Node<T>(T element)
	{
		data = element;
	}
};

// LinkedList Class
template <class T>
class LinkedList
{
protected:
	// 첫번째 노드의 주소를 저장할 포인터
	Node<T> *first;
	int current_size;

public:
	// 생성자, 초기화
	LinkedList()
	{
		first = NULL;
		current_size = 0;
	};

	// 노드 개수를 리턴
	int GetSize()
	{
		return current_size;
	};

	// 맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
	// 새 노드를 맨 앞에 붙이고 값을 넣음
	void Insert(T element)
	{
		// 노드 생성
		Node<T> *newNode = new Node<T>(element);

		// 새 노드가 첫번째 노드를 가리킴
		// newnode는 포인터이므로 -> 를 사용해 함수,변수를 불러옴 newnode.link와 뜻은 같다
		newNode->link = first;
		first = newNode;
		current_size++;
	}

	// 맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
	virtual bool Delete(T &element)
	{
		if (first == NULL)
			return false;

		Node<T> *cur = first;
		Node<T> *prev = NULL;

		// 마지막 노드까지 찾아가는 반복문
		while (1)
		{
			if (cur->link == 0)
			{ // 마지막 노드를 찾는것
				if (prev)
					prev->link = cur->link;
				else
					first = first->link;
				break;
			}
			prev = cur;
			cur = cur->link;
		}
		element = cur->data;
		delete cur;
		current_size--;

		return true;
	}
	// 리스트 출력
	void Print()
	{
		Node<T> *cur = first;
		int num = 1;

		while (cur != NULL)
		{
			cout << "[" << num << "|" << cur->data << "]";
			if (cur->link != NULL)
				cout << "->";
			cur = cur->link;
			num++;
		}
		cout << endl;
	}
};

#endif

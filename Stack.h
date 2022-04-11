#ifndef __STACK_H__
#define __STACK_H__

#include "LinkedList.h"

template <class T>	//1. 템플릿 클래스로 확장해야함
class Stack: public LinkedList<T>{	//LinkedList class를 상속받음
	public:
		//2. Stack형식으로 Delete 함수 재정의해야함
		//주의: first, current_size는 class의 멤버변수이므로 this포인터 사용하여 가져옴.
		bool Delete(T& element){
			if(this->first == NULL)	//first가 0이면 false 반환
				return false;//false
			Node<T>* cur = this -> first; // cur는 current 
			element = cur -> data;

			if(cur -> link == NULL)
				this -> first = NULL;
			else
				this -> first = this -> first -> link;

			delete cur; //LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			this->current_size--;
			
			return true;//true
		}
};

#endif

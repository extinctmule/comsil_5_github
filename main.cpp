#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	int mode, selectNumber, tmpItem;
	LinkedList<int> *p;
	// 설명1: Stack 클래스는 LinkedList가 기반 클래스인 파생 클래스이다. 따라서, 서브타입 다형성의 특성을 사용함으로써 LinkedList<int> *p 라는 포인터를 사용해서도 Stack 클래스를 접근할 수 있다.
	// 이때, 정확한 작동을 보장하기 위해서는 파생 클래스(Stack)에서 재정의하는 함수가 virtual로 선언되어야 한다. virtual bool Delete(T& element) 부분은 LinkedList에 포함시키면 된다.
	
	
	bool flag = false;

	cout << "자료구조 선택(1: Stack, Other: Linked List): ";
	cin >> mode;
	
	if(mode == 1)
		p = new Stack<int>();    // (설명1) 정수를 저장하는 스택
	else
		p = new LinkedList<int>();// (설명1) 정수를 저장하는 연결 리스트

	// 출력 부분
	// do
	do{
		prnMenu();
		cin>>selectNumber;

		switch(selectNumber){
		case 1:
			cout<<"원하시는 값을 입력해주세요: ";
			cin>>tmpItem;    p->Insert(tmpItem);
			cout<<tmpItem<<"가 삽입되었습니다."<<endl;
			break;
		case 2:
			if(p->Delete(tmpItem)==true)
				cout<<tmpItem<<"가 삭제되었습니다."<<endl;

			else cout<<"비어있습니다. 삭제 실패"<<endl;
			break;
		case 3:
			cout<<"크기: "<<p->GetSize()<<endl;
			p->Print();
			break;
		case 4:
			flag = true;
			break;
		default:
			cout<<"잘못 입력하셨습니다."<<endl;
			break;
		}
		if(flag) break;

	} while(1);
	// while

	return 0;
}


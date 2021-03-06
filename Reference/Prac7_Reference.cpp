/*
앞선 프로그램은 동작은 하지만 swap()함수의 구성이 두 가지 부분에 있어 효과적이지 못하다.
첫재 swap() 함수에서 포인터를 소환하는 것은 오류가 발생하기 쉽고 읽기도 쉽지 않다.
둘째, 호출 함수에서 변수의 주소를 전달하는 것은 swap()함수의 내부 과정을 너무나도 뻔하게 만든다.
c++의 목적 중 하나는 사용자로 하여금 함수가 어떻게 돌아가는지 걱정하지 않게 하는 것이다.
포인터를 전달하느 ㄴ것은 사실 호출된 프로그램보다 호출한 프로그램에게 부담이 된다.
참조자를 이용하여 swap을 구현해보자
*/

#include <iostream>

using namespace std;
void swap(int &x, int &y);

int main(void)
{
	int x=5,y=10;

	cout << "Befroe swap x : " << x << " y : " << y << endl;
	swap(x,y);
	cout << "After swap x : " << x << " y : " << y << endl;
	return 0;
}

void swap( int &r_x, int &r_y)
{
	int temp;
	temp =r_x;
	r_x= r_y;
	r_y= temp;
}
/*
포인터를 써서 만든 프로그램에서와 같이 두 개의 변수가 선언되었고 그 값이 swap을 들어가기 전에 출력을 시켜 ㅈ ㅜ었으며
다음줄에서는 swap을 호출하였다. 여기서는 주소가 아니라 x,y의 값이 인수로써 전달되었다.
즉 호출하는 함수는 단순히 값만 전달한 것이다.
그렇다면 swap()함수 내부의 과정을 살펴보도록 하자.
swap()이 호출되었을 때 함수의 실행에 사용되는 변수는 참조자로 역할을 하게된다.
즉, &r_x= x(5) r_y= y(10)로 할당과 선언은 동시에 한것으로 볼 수 있다.
이제 이 참조자를 통해 값을 수정하여 보도록 하자 temp라는 변수를 선언하여 놓고 그 값을 참조자 r_x가 가리키고 있는것으로 초기화 한다. 즉 5가 있다.
이제 r_x 참조자 자체를 건드리는 과정이 필요하다 이 값은 x를 의미하므로 참조자 r_y가 가지고 있는 값 10을 넣는다.
또한 r_y 참조자 또한 값이 바뀔 필요가 있으므로 여기서는 temp의 값으로 초기화 한다.
*/
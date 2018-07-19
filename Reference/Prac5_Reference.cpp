/*
널 포인터와 널 참조자
포인터가 초기화되지 않았을 때 혹은 삭제되었을 때 널로 치환되어야 한다.
참조자에서는 이와 다른데, 사실 참조자는 널로 될 수가 없다. 널을 참조하는 참조자는 잘못된 프로그램이다.
이런 때는 어떤일이 발생할지 전혀 예측할 수 없다.
잘 동작되는 것 같기도 하고 혹은 오류가 발생할 수도 있다. 다 잘못된 프로그램이 할 수 있는 일이다.
대부분 컴파일러는 오류 메세지 없이 널 객체를 지원하는데, 실제 사용하려고 하면 제대로 동작하지 안흔다.
설령 이런 일이 없다하더라도 이 프로그램을 다른 컴파일러 또는 컴퓨터로 옮기면 오류가 일어난다.
*/
/*
함수는 두 가지 한계를 가지고 있다. 하나는 매개변수가 값으로 전달되는 것이고, 다른 하나는 반환값이 단 하나밖에 없다는 것이다.

참조자를 이용하여 값들을 함수에 전달하면 이 두 가지 한계를 극복할 수 있다.
C++에서 참조 전달 방식은 두 가지로 일어난다. 하나는 포인터로 전달하는 것이고 하나는 참조자로 전달하는 방법이다.
사용하는 구문 방ㅅ긱은 다르지만 효과는 같다. 함수의 범위 규칙 내에서 값이 복사되는 것이 아니라, 진짜 객체가 함수로 전달이 된다.

함수의 그 매개변수는 스택에 저장됨을 안다면, 함수가 주소 전달 방식으로 값을 전달하였을 때 전체의 객체가 아니라 객체의 주소가 스택에 저장된다.
실제 어떤 컴퓨터의 주소는 레지스터에 저장이 되고 스택엔 아무 것도 없게 된다.
어떤 경우든 컴파일러는 원래의 객체에 도달하는 방법을 알고, 객체를 변화시키고 복사본을 변화시키지 않는다.

참조자를 전달하는 방식은 함수로 하여금 그 객체를 변화시킬 수 있게 한다.
*/

//prac5,6,7 을 비교해 가면서 보도록 하자!
#include <iostream>

using namespace std;
void swap(int x, int y);

int main(void)
{
	int x=5, y=10;

	cout << "Before swap, x " << x << " y " << y << endl;
	swap(x,y);
	cout << "After swap, x " << x << " y " << y << endl;
	return 0;
}
void swap(int x, int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
/*이 프로그램은 main에서의 스왑이 이루어 지지 않음을 알 수 있다.
이는 swap()함수에 x,y의 값이 전달되었다는 것이다.
이는 지역적인 복사가 함수에서 만들어졌다는 것이다. main에서 다시 보았을 땐, 변화가 없는 것을 알 수 있다.
위와 같은 문제를 해결하기 위한 2가지 방안이 있는데 하나는 포인터를 활용하여, 하나는 참조자를 활용하는 방법이다.
*/

/*
	C++에서 정책을 교체하는 4가지 기술...

	1. 일반 함수 - Sort()
		변해야 하는 정책이 있다면 함수 인자화한다 (함수포인터, 함수객체)

	2. 클래스(멤버함수)
		(1). 변하는 부분을 가상함수로 뽑아낸다. - "Template Method"
		(2). 변하는 부분을 인터페이스 기반의 다른 클래스로 - "Strategy Pattern"
														(정책의 재사용성이 뛰어남)

	3. 컴파일 시간에만 교체가 필요하다면?
		변하는 정책을 템플릿 인자화 한다. - "단위 전략 디자인(Policy base design)"
*/
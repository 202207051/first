package chapt07;

public class chain
{
	chain()
	{
		this(10);
		System.out.println("기본 생성자 chain() 호출");
	}

	chain(int x)
	{
		this(5, 6);
		System.out.println("일반 생성자 chain(int x) 호출");
		System.out.println("x의 값 : " + x);
	}

	chain(int x, int y)
	{
		System.out.println("일반 생성자 chain(int x, int y) 호출");
		System.out.println("x와 y값 : " + x + " " + y);
	}
}

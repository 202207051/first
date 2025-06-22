package chapt07;

public class add
{
	add()
	{
		System.out.println("기본 생성자 add() 호출");
	}

	add(int a, int b)
	{
		System.out.println("일반 생성자 add(int a, int b) 호출");
		System.out.println(a + "+" + b + "=" + (a + b));
	}

	add(double a, double b)
	{
		System.out.println("일반 생성자 add(double a, double b) 호출");
		System.out.println(a + "+" + b + "=" + (a + b));
	}

	add(int a, double b)
	{
		System.out.println("일반 생성자 add(int a, double b) 호출");
		System.out.println(a + "+" + b + "=" + (a + b));
	}
}

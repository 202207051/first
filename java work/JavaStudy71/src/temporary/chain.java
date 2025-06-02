package temporary;

public class chain
{
	chain()
	{
		this(10);
		System.out.printf("기본 생성자 chain()호출\n");
	}

	chain(int x)
	{
		this(10, 20);
		System.out.printf("일반 생성자 chain(int x)호출\n");
		System.out.printf("x = %d\n", x);
	}

	chain(int x, int y)
	{
		System.out.printf("일반 생성자 chain(int x, int y)호출\n");
		System.out.printf("x + y = %d + %d\n", x, y);
	}
}

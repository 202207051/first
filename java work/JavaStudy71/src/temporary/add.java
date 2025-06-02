package temporary;

public class add
{
	add()
	{
		System.out.printf("기본 생성자 add()호출\n");
	}

	add(int a, int b)
	{
		System.out.printf("일반 생성자 add(int a, int b)호출\n");
		System.out.printf("a + b = %d\n", (a + b));
	}

	add(double a, double b)
	{
		System.out.printf("일반 생성자 double(double a, double b)호출\n");
		System.out.printf("a + b = %.2f\n", (a + b));
	}

	add(int a, double b)
	{
		System.out.printf("일반 생성자 add(int a, double b)호출\n");
		System.out.printf("a + b = %.2"
				+ "f\n", (a + b));
	}
}

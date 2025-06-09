package ssi;

public class inheritance01 extends calculation
{
	public void mult(int x, int y)
	{
		num = x * y;
		System.out.printf("x * y : %d\n", num);
	}

	public static void main(String[] args)
	{
		int a = 20;
		int b = 10;

		inheritance01 obj = new inheritance01();

		obj.add(a, b);
		System.out.printf("x - y : %d\n", obj.sub(a, b));
		obj.mult(a, b);
	}
}

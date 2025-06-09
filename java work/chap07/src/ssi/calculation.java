package ssi;

public class calculation
{
	int num;

	public void add(int x, int y)
	{
		num = x + y;
		System.out.printf("x + y : %d\n", num);
	}

	public int sub(int x, int y)
	{
		num = x - y;
		return num;
	}
}

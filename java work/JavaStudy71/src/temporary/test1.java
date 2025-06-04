package temporary;

public class test1
{
	public static void main(String[] args)
	{
		int num = 1;

		for (int i = 0; i < 100; i++)
		{
			System.out.printf("%d\t", num);
			num++;
			if (num % 10 == 1)
			{
				System.out.printf("\n");
			}
		}
	}
}

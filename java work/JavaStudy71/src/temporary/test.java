package temporary;

public class test
{
	public static void main(String[] args)
	{
		int num = 1;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				System.out.printf("%d\t", num);
				num++;
			}
			System.out.printf("\n");
		}
	}
}

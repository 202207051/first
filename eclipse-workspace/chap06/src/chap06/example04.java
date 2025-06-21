package chap06;

public class example04
{
	public static void main(String[] args)
	{
		int myarr[][] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 } };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				System.out.print(myarr[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println("myarr[0][1]값 : " + myarr[0][1]);
	}
}

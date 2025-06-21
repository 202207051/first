package chap06;

public class example03
{
	public static void main(String[] args)
	{
		int[][] myarr = new int[2][4];
		myarr[0][0] = 2;
		myarr[0][1] = 5;
		myarr[0][2] = 7;
		myarr[0][3] = 4;
		myarr[1][0] = 9;
		myarr[1][1] = 3;
		myarr[1][2] = 2;
		myarr[1][3] = 8;

		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < 4; i++)
		{
			sum1 += myarr[0][i];
		}
		for (int i = 0; i < 4; i++)
		{
			sum2 += myarr[1][i];
		}

		System.out.println("sum1 합계 : " + sum1);
		System.out.println("sum2 합계 : " + sum2);
	}
}

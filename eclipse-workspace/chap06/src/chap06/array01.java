package chap06;

import java.util.Scanner;

public class array01
{
	public static void main(String[] args)
	{
		String[] myarr;
		myarr = new String[3];

		Scanner s = new Scanner(System.in);

		System.out.println("3개 문자열을 입력하시오.");

		for (int i = 0; i < 3; i++)
		{
			myarr[i] = s.nextLine();
		}
		for (int i = 0; i < 3; i++)
		{
			System.out.println(myarr[i]+" ");
		}
	}
}

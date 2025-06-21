package chap06;

import java.util.Scanner;

public class array03
{
	public static void main(String[] args)
	{
		double[][] marks = new double[2][3];
		Scanner s = new Scanner(System.in);

		for (int i = 0; i < 2; i++)
		{
			System.out.println("학생번호" + (i + 1));
			System.out.print("국어 점수 : ");
			marks[i][0] = s.nextDouble();

			System.out.print("수학 점수 : ");
			marks[i][1] = s.nextDouble();

			marks[i][2] = (marks[i][0] + marks[i][1]) / 2;
		}

		for (int i = 0; i < 2; i++)
		{
			System.out.println("학생번호" + (i + 1));
			System.out.print("국어" + marks[i][0]);
			System.out.print("수학" + marks[i][1]);
			System.out.println("평균" + marks[i][2]);
		}

		for (int i = 0; i < marks.length; i++)
		{
			for (int j = 0; j < marks[i].length; j++)
			{
				System.out.print(marks[i][j] + " ");
			}
			System.out.println();
		}
	}
}

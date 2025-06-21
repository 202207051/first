package chap06;

public class array02
{
	public static void main(String[] args)
	{
		double[] gradearr = { 90, 70.5, 80, 79, 82.5, 50, 70, 90.2, 89.5, 89.7 };
		double sum = 0.0;

		for (int i = 0; i < gradearr.length; i++)
		{
			sum += gradearr[i];
		}
		
		double average = sum/gradearr.length;
		System.out.println("합계: "+sum);
		System.out.println("평균: "+average);		
	}
}

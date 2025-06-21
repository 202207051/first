package chap06;

public class array04
{
	public static void main(String[] args)
	{
		int rows = 2, columns = 3;
		int[][] firstmatrix = { { 2, 3, 4 }, { 3, 2, 1 } };
		int[][] secondmatrix = { { 1, 2, 3 }, { -4, -2, 1 } };

		int[][] sum = new int[rows][columns];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				sum[i][j]=firstmatrix[i][j]+secondmatrix[i][j];
			}
		}
		
		System.out.println("두 행렬의 합 : ");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				System.out.print(sum[i][j]+" ");
			}
			System.out.println();
		}
	}
}

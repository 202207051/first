package chapter08;

public class inheritance01 extends calculation
{
	public void mult(int x, int y) {
		z= x*y;
		System.out.println("두 수의 곱셈 : "+z);
	}

	public static void main(String[] args) {
		int a=20, b=10;
		inheritance01 obj = new inheritance01();
		obj.add(a, b);
		obj.sub(a, b);
		obj.sub(a, b);
	}
}

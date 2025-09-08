class point
{
	int x;
	int y;

	point()
	{
		x = 10;
		y = 20;
	}

	void print()
	{
		System.out.println("(" + x + "," + y + ")");
	}
}

public class code777
{
	public static void main(String[] args)
	{
		point p1 = new point();
		p1.x = 100;
		p1.y = 200;
		point p2 = new point();
		p1.print();
		p2.print();
	}
}
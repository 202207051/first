package chapter08;

public class example01
{
	public static void main(String[] args)
	{
		babycat catobj = new babycat();

		System.out.println("품종 : " + catobj.breed);
		System.out.println("색상 : " + catobj.color);
		
		catobj.eat();
		catobj.menow();
	}
}

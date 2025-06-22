package chapt07;

public class exmple011
{

	public static class Cat
	{
		String breed;
		String color;

		void eat()
		{
			System.out.println("고양이가 밥을 먹습니다.");
		}

		void scratch()
		{
			System.out.println("고양이가 발톱을 갈고 있습니다.");
		}

		void meow()
		{
			System.out.println("고양이가 야옹합니다.");
		}
	}

	public static void main(String[] args)
	{
		Cat catobj = new Cat();

		catobj.breed = "페르시안 고양이";
		catobj.color = "흰색";

		System.out.println("품종 : " + catobj.breed);
		System.out.println("색깔 : " + catobj.color);

		catobj.eat();
		catobj.meow();
	}
}
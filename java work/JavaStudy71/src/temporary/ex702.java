package temporary;

public class ex702
{
	class cat
	{
		String breed;
		String color;

		void eat()
		{
			System.out.printf("먹이를 먹다\n");
		}

		void scratch()
		{
			System.out.printf("발톱으로 할퀴다");
		}

		void meow()
		{
			System.out.printf("야옹");
		}
	}

	public void main(String[] args)
	{
		cat c = new cat();

		c.breed = "야옹이";
		c.color = "흰색";

		System.out.printf("품종은 : %s\n", c.breed);
		System.out.printf("색깔은 : %s\n", c.color);

		c.eat();
		c.scratch();
		c.meow();

		c.breed = "쌉살이";
		c.color = "검정색";
		System.out.printf("품종은 : %s\n", c.breed);
		System.out.printf("색깔은 : %s\n", c.color);
	}

}

		
		
		

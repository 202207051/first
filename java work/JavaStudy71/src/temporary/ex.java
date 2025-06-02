package temporary;

public class ex
{

	public static void main(String[] args)
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

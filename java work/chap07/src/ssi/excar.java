package ssi;

class Car
{
	String model;
	String color;
	int cost;
	int tax;

	public Car()
	{
		System.out.println("기본 생성자");
	}

	public Car(String model, String color, int cost, int tax)
	{
		this.model = model;
		this.color = color;
		this.cost = cost;
		this.tax = tax;
	}

	public int price()
	{
		return cost + tax;
	}
}

public class excar
{
	public static void main(String[] args)
	{
		Car c0 = new Car();
		Car c1 = new Car("소나타", "white", 3000, 300);
		Car c2 = new Car("프라이드", "red", 2000, 100);

		c0.model = "벤츠";
		c0.color = "Black";
		c0.cost = 7000;
		c0.tax = 1400;

		System.out.printf("모델 : %s, 색상 : %s, 가격 : %d, 세금 %d\n", c0.model, c0.color, c0.cost, c0.price());
		System.out.printf("%s의 소비자 가격은 : %d\n", c1.model, c1.price());
		System.out.printf("%s의 소비자 가격은 : %d\n", c2.model, c2.price());
	}

}
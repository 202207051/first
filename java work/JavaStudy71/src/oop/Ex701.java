package oop;

public class Ex701
{
	public static void main(String[] args)
	{
		Cat cat0bj = new Cat();

		cat0bj.breed = "도둑 고양이";
		cat0bj.color = "검정색";

		System.out.println("고양이 품종은 : " + cat0bj.breed);
		System.out.println("고양이 색상은 : " + cat0bj.color);
		System.out.println(cat0bj);

		cat0bj.eat();
		cat0bj.scratch();
		cat0bj.meow();
	}

}

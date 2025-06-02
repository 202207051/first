package oop;

class Catt
{
	String breed;
	String color;
	int age;
	double weight;

	void eat()
	{
		System.out.println("고양이가 생선을 먹는다");
	}

	void scratch()
	{
		System.out.println("발톱으로 할퀸다.");
	}

	void meow()
	{
		System.out.println("고양이가 야 옹~");
	}
}

public class Ex7011
{

	public static void main(String[] args)
	{
		Catt cat0bj = new Catt();

		cat0bj.breed = "도둑 고양이";
		cat0bj.color = "하얀색";

		System.out.println("고양이 품종은 : " + cat0bj.breed);
		System.out.println("고양이 색상은 : " + cat0bj.color);
		System.out.println(cat0bj);

		cat0bj.eat();
		cat0bj.meow();
	}

}

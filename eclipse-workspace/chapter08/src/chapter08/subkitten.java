package chapter08;

public class subkitten extends supercat
{
	String age = "2살";
	
	void printinfo()
	{
		System.out.println("아기 고양이 입니다");
	}

	void printdetails()
	{
		super.printinfo();
		System.out.println("품종은 " + super.breed + ", 나이는 " + super.age);

		printinfo();
		System.out.println("품종은 " + this.breed + ", 나이는 " + this.age);
	}
}

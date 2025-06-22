package chapter08;

public class child extends parent
{
	String name = "홍길동";

	void details()
	{
		super.details();
		System.out.println(name);
	}

	void printdetails()
	{
		details();
		System.out.println("부모 이름 : "+super.name);
		System.out.println("자식 이름 : "+this.name);
	}
}

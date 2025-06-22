package chapter08;

public class subkitten2 extends supercat2
{
	String name;
	String age = "2살";

	subkitten2(String n1, String n2)
	{
		super(n1);
		this.name = n2;
		System.out.println("아기 고양이입니다" + "이름은 " + name);
	}
}

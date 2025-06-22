package chapt07;

public class example02
{
	static void mymethod1()
	{
		System.out.println("정적 메서드 호출");
	}

	public void mymethod2()
	{
		System.out.println("인스턴스 메서드 호출");
	}

	public static void main(String[] args)
	{
		mymethod1();

		example02 myobj = new example02();
		myobj.mymethod2();
	}
}

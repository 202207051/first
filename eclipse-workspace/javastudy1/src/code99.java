class friend1
{
	String name;
	int age;

	void printfriend()
	{
		System.out.println("name : " + name + ", age : " + age);
	}
}

public class code99
{
	public static void main(String[] args)
	{
		friend1 f = new friend1();
		f.printfriend();

		f.name = "alce";
		f.age = 20;
		f.printfriend();
	}
}

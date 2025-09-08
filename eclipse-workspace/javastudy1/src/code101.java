class friend
{
	String name;
	int age;

	friend()
	{

	}

	friend(String n, int a)
	{
		name = n;
		age = a;
	}

	void printfriend()
	{
		System.out.println("name : " + name + ", age : " + age);
	}
}

public class code101
{
	public static void main(String[] args)
	{
		friend f = new friend("alice",20);
		f.printfriend();
	}
}

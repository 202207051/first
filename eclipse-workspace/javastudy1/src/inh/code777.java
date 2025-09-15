package inh;

class parent
{
	int x = 10;
	int y = 20;

	void show()
	{
		System.out.println("parent show");
	}

	void print()
	{
		System.out.println("i am parent print");
	}
}

class child extends parent
{
	int y = 200;
	int z = 300;

	void show()
	{
		System.out.println("child show");
	}

	void check()
	{
		System.out.println("child checking");
	}
}

class person
{
	private String name;
	private String phone;

	person()
	{

	}

	person(String name, String phone)
	{
		this.name = name;
		this.phone = phone;
	}

	void printperon()
	{
		System.out.println("name : " + name + " phone : " + phone);
		System.out.println("phone : " + phone);
	}

}


public class code777
{

	public static void main(String[] args)
	{
		parent p = new parent();
		child c = new child();

		System.out.println(p.x);
		System.out.println(p.y);

		p.show();
		p.print();

		System.out.println(c.x);
		System.out.println(c.y);
		System.out.println(c.z);

		c.print();
		c.show();
		c.check();
	}

}

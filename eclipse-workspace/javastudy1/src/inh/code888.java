package inh;

class parent1
{
	parent1()
	{
		System.out.println("parent1 call");
	}

	void printparent1()
	{
		System.out.println("parent1 입니다");
	}
}

class child1 extends parent1
{
	child1()
	{
		System.out.println("child1 call");
	}

	void printchild1()
	{
		System.out.println("child1 입니다");
	}
}

public class code888
{

	public static void main(String[] args)
	{
		child1 c = new child1();
		c.printparent1();
		c.printchild1();
	}

}
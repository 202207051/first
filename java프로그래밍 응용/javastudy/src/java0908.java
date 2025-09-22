class car
{
	String kind;
	String color;
	int year;

	void run()
	{
		System.out.println("car is running");
	}

	void speedup()
	{
		System.out.println("car is speeding up");
	}
}

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
		System.out.println("name : " + name + ", age " + age);
	}
}

class point
{
	int x;
	int y;

	point()
	{
		x = 10;
		y = 20;
	}

	void print()
	{
		System.out.println("(" + x + " , " + y + ")");
	}
}

class student
{
	int no;
	String name;
	double score;

	student()
	{

	}

	student(int n)
	{
		no = n;
	}

	student(int n, String nm)
	{
		no = n;
		name = nm;
	}

	student(int n, String nm, double s)
	{
		no = n;
		name = nm;
		score = s;
	}

	void printstudent()
	{
		System.out.println("no : " + no + ", name : " + name + ", score : " + score);
	}
}

class personinfo
{
	String name;
	int age;
	double height;

	personinfo()
	{

	}

	personinfo(String n, int a, double h)
	{
		name = n;
		age = a;
		height = h;
	}

	void printall()
	{
		System.out.println("name :" + name);
		System.out.println("age :" + age);
		System.out.println("height :" + height);
		System.out.println();
	}
}

class data
{
	int value;
	static int count;

	void print()
	{
		System.out.println("value : " + value++);
		System.out.println("count : " + count++);
	}
}

class bankaccount
{
	String name;
	double balance;
	static int count;

	bankaccount(String name, double balance)
	{
		this.name = name;
		this.balance = balance;

		count++;
		System.out.println(name + "고객의 잔고 : " + balance);
	}
}

class book
{
	String title;
	int price;
	
	book(String title, int price)
	{
		this.title = title;
		this.price = price;
	}
}


public class java0908
{
	public static void main(String[] args)
	{
		car mycar = new car();
		mycar.kind = "sonata";
		mycar.color = "white";
		mycar.year = 2015;

		car yourcar = new car();
		yourcar.kind = "pride";
		yourcar.color = "blue";
		yourcar.year = 2017;

		mycar.run();
		yourcar.run();

		mycar.speedup();
		yourcar.speedup();

		System.out.println(mycar);
		System.out.println(mycar.kind);
		System.out.println(mycar.color);
		System.out.println(mycar.year);

		System.out.println(yourcar);
		System.out.println(yourcar.kind);
		System.out.println(yourcar.color);
		System.out.println(yourcar.year);

		friend f = new friend();
		f.printfriend();

		f.name = "alce";
		f.age = 20;
		f.printfriend();

		point p1 = new point();
		p1.x = 100;
		p1.y = 200;

		point p2 = new point();
		p1.print();
		p2.print();

		friend f1 = new friend("alice", 20);
		f.printfriend();

		student s1 = new student();
		student s2 = new student(10);
		student s3 = new student(15, "david");
		student s4 = new student(20, "paul", 92.5);
		s1.printstudent();
		s2.printstudent();
		s3.printstudent();
		s4.printstudent();

		personinfo pi1 = new personinfo();
		personinfo pi2 = new personinfo("alice", 10, 115.5);
		pi1.printall();
		pi2.printall();

		data d1 = new data();
		data d2 = new data();
		d1.print();
		d2.print();

		d1.print();
		d2.print();

		bankaccount b1 = new bankaccount("alice", 100000);
		bankaccount b2 = new bankaccount("paul", 50000);
		bankaccount b3 = new bankaccount("cindy", 30000);
		bankaccount b4 = new bankaccount("david", 150000);
		bankaccount b5 = new bankaccount("tom", 200000);

		System.out.println();
		System.out.println("number of account : " + bankaccount.count);
		
		book bo1 = new book("peter pan",100);
		book bo2 = new book("aladdin", 90);
		
		System.out.println(bo1.title+", "+bo1.price);
		System.out.println(bo2.title+", "+bo2.price);
	}
}

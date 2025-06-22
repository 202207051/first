package chapt07;

public class memberchain
{
	String firstname;
	String country;
	int age;

	public memberchain()
	{
		this("홍길순");
	}

	public memberchain(String mname)
	{
		this(mname, 20);
	}

	public memberchain(String mname, int mage)
	{
		this(mname, mage, "대한민국");
	}

	public memberchain(String mname, int mage, String mcountry)
	{
		firstname= mname;
		age =mage;
		country=mcountry;
	}

	void printinfo()
	{
		System.out.println("이름 : " + firstname);
		System.out.println("국적 : " + country);
		System.out.println("나이 : " + age);
	}
}

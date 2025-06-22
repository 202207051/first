package chapt07;

public class student
{
	int id;
	String name;

	student()
	{
		System.out.println("기본 생성자 student() 호출");
	}

	student(int pram1, String parm2)
	{
		System.out.println("일반 생성자 student(...) 호출");
		id = pram1;
		name = parm2;
	}

	void insertrecord(int parm1, String parm2)
	{
		id = parm1;
		name = parm2;
	}

	void printinfo()
	{
		System.out.println("아이디 : " + id);
		System.out.println("이름 : " + name);
	}
}

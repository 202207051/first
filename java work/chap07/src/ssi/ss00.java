package ssi;

class fafa
{
	String fName = "은주";
	String lName = "정";
	String house = "서울시 동작구";
	String car = "쏘나타";
	int asset = 20;

	public fafa()
	{
		System.out.println("fafa() 생성자 호출");
	}

	void eat()
	{
		System.out.println("한정식을 좋아해");
	}

	void sport()
	{
		System.out.println("골프를 좋아해");
	}
}

class son extends fafa
{
	String fName = "철수";
	String car = "벤츠";
	int asset = 5;

	public son()
	{
		System.out.println("son() 생성자 호출");
	}

	void eat()
	{
		System.out.println("돈까를 좋아해");
	}
}

public class ss00
{
	public static void main(String[] args)
	{
//		fafa f = new fafa();
//		System.out.printf("아버지는 %s%s입니다.\n", f.fName, f.lName);
//		System.out.printf("아버지 주소는 %s입니다.\n", f.house);
//		System.out.printf("아버지 재산은 %d입니다.\n", f.asset);
//		System.out.printf("아버지 자동차는 %s입니다.\n", f.car);
//		f.eat();
//		f.sport();

		System.out.println();

		son s = new son();
		System.out.printf("아들은 %s%s입니다.\n", s.fName, s.lName);
		System.out.printf("아들 주소는 %s입니다.\n", s.house);
		System.out.printf("아들 재산은 %d입니다.\n", s.asset);
		System.out.printf("아들 자동차는 %s입니다.\n", s.car);	
		s.eat();
		s.sport();
	}
}

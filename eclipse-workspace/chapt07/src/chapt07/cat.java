package chapt07;

public class cat
{
	String breed;
	String color;

	cat()
	{
		System.out.println("cat() 생상자 호출합니다");
	}

	cat(String pbreed)
	{
		System.out.println("cat(...)생성자 호출합니다");
		breed = pbreed;
	}

	cat(String pbreed, String pcolor)
	{
		System.out.println("cat(...)생성자 호출합니다");
		breed = pbreed;
		color = pcolor;
	}

	void eat()
	{
		System.out.println("먹이를 먹다");
	}

	void scratch()
	{
		System.out.println("발톱을 할퀴다");
	}

	void meow()
	{
		System.out.println("야옹 하고 울다");
	}
}

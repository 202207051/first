package chapt07;

public class accessmodifier03
{
	public static void main(String[] args)
	{
		dog obj = new dog();

		obj.breed = "포메라니안";
		obj.color = "갈색";

		System.out.println("강아지 품종 : " + obj.breed);
		System.out.println("강아지 색상 : " + obj.color);
		obj.bowwow();
		obj.age=10;
		System.out.println("강아지 나이 : "+obj.age);
		obj.run();
		
		obj.name="다운";
		System.out.println("강아지 이름 : ",obj.name);
		obj.sleep;
	}
}

package chapt07;

public class example04
{
	public static void main(String[] args)
	{
		cat cat1 = new cat();
		cat1.breed = "페르시안 고양이";
		cat cat2 = new cat();
		cat2.breed = "샴";
		cat cat3 = new cat();
		cat3.breed = "러시안블루";

		System.out.println("첫 번째 고양이 품종 : " + cat1.breed);
		System.out.println("두 번째 고양이 품종 : " + cat2.breed);
		System.out.println("세 번째 고양이 품종 : " + cat3.breed);
	}
}

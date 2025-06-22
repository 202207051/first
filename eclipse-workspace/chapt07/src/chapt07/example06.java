package chapt07;

public class example06
{
	public static void main(String[] args)
	{
		cat cat1 = new cat();
		cat1.breed = "페르시안 고양이";
		cat1.color = "흰색";

		cat cat2 = new cat("샴");
		cat2.color = "치즈색";

		cat cat3 = new cat("러시안블루", "회색");

		System.out.println("첫 번째 고양이 품종 : " + cat1.breed + "\t색상 : " + cat1.color);
		System.out.println("두 번째 고양이 품종 : " + cat2.breed + "\t색상 : " + cat2.color);
		System.out.println("세 번째 고양이 품종 : " + cat3.breed + "\t색상 : " + cat3.color);
	}
}

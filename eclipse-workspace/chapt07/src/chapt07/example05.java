package chapt07;

public class example05
{
	public static void main(String[] args)
	{
		cat catobj1 = new cat("페르시안 고양이");
		
		cat catobj2 = new cat("샴");
		
		cat catobj3 = new cat();
		catobj3.breed = "러시안 블루";
		
		System.out.println("첫 번째 고양이 품종 : "+catobj1.breed);
		System.out.println("두 번째 고양이 품종 : "+catobj2.breed);
		System.out.println("세 번째 고양이 품종 : "+catobj3.breed);
	}
}

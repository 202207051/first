package chapt07;

public class example01
{
	public static void main(String[] args)
	{
		cat catobj = new cat();
		catobj.breed = "페르시안 고양이";
		catobj.color = "흰색";

		System.out.println("품종 : " + catobj.breed);
		System.out.println("색깔 : " + catobj.color);
	}
}

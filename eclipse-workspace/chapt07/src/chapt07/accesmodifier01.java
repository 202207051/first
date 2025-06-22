package chapt07;

public class accesmodifier01
{
	public static void main(String[] args)
	{
		dog dogobj = new dog();
		
		dogobj.breed="포메라니안";
		dogobj.color="갈색";
		
		System.out.println("강아지 품종 : "+dogobj.breed);
		System.out.println("강아지 품종 : "+dogobj.color);
		
		dogobj.bowwow();
	}
}

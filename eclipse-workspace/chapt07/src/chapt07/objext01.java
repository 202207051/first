package chapt07;

public class objext01
{
	public static void main(String[] args)
	{
		student stobj = new student();
		
		stobj.id=202207051;
		stobj.name="박영환";
		stobj.printinfo();
		
		student stobj2 =new student();
		
		stobj2.insertrecord(202207051, "박영환");
		stobj2.printinfo();
	}
}

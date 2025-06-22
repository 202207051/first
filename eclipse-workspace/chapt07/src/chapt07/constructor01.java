package chapt07;

public class constructor01
{
	public static void main(String[] args)
	{
		System.out.println("****학생 주소록****");
		student stobj = new student();
		
		stobj.insertrecord(202207051, "박영환");
		stobj.printinfo();
	}
}

package chapt07;

public class constructor02
{
	public static void main(String[] args)
	{
		System.out.println("****학생 주소록****");
		student stobj1 = new student();

		stobj1.insertrecord(202207051, "박영환");
		stobj1.printinfo();

		student stobj2 = new student(202207051, "박영환");
		stobj2.printinfo();
	}
}

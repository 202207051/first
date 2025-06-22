package chap06;

public class example07
{
	public static void main(String[] args)
	{
		String s1 = "java";
		String s2 = "java";
		String s3 = "java";
		System.out.println(s1 == s2);
		System.out.println(s1 != s2);

		System.out.println(s2 == s3);
		System.out.println(s2 != s3);

		String s4 = s2 + s3;
		System.out.println(s4);
	}
}

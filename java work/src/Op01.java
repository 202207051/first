public class Op01 {

	public static void main(String[] args) {
		Cat cobj1 = new Cat();
		Cat cobj2 = new Cat();
		
		cobj1.breed = "도둑고양이";
		cobj1.Age = 10;
		cobj1.Color ="black";
		
		cobj2.breed = "애완 고양이";
		cobj2.Age = 5;
		cobj2.Color = "White";
		cobj2.weight = 16;
		
		System.out.println("고양이 객체1 입니다.");
		System.out.print(cobj1.breed+"	");
		System.out.print(cobj1.Age+"	");
		System.out.println(cobj1.Color+"	");
		
		System.out.println();
		System.out.println("고양이 객체2 입니다.");
		System.out.print(cobj2.breed+"	");
		System.out.print(cobj2.Age+"	");
		System.out.print(cobj2.Color+"	");
		System.out.print(cobj2.weight+"	");
	}

}

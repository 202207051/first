package W4;
//Person클래스
class Person{
  private String name;
  private int age;

  //setter
  public void setName(String name) {
      this.name = name;
  }
  public void setAge(int age) {
      this.age = age;
  }

  //getter
  public String getName() {
      return name;
  }
  public int getAge() {
      return age;
  }
}

public class W4_2 {
  public static void main(String[] args) {
      // TODO Auto-generated method stub
      Person p = new Person();

      //setter
      p.setName("Panda");
      p.setAge(25);

      //getter
      System.out.println("name : " + p.getName());
      System.out.println("Age : " + p.getAge());
  }
}

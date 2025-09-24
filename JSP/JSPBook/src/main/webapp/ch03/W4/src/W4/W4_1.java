/*
 * 작성자 : 함원준
 * 작성일 : 2025-09-18
 * 프로젝트명 : getter-setter
 */
package W4;

//1. Car3 클래스 선언과 정의
class Car3{
  //색깔 변수 : 문자열 데이터 타입 col 선언
  String col;
  // 속도 변수 : 정수형 데이터 타입 sp 선언
  int sp;

  //2. 속도증가 기능 : 속도 증가값만큼 미리만든 upSpeed( 매개변수 정수형 sp )선언과 정의
  //메서드 호출한 곳에 돌려줄 반환값이 없을때 데이터 타입은 void
  void upSpeed(int sp) {
      this.sp = this.sp + sp;
  }

  void downSpeed(int sp) {
      this.sp = sp;   //this.sp = this.sp - sp
  }

  //col의 값을 반환할 경우 호출한곳에 돌려줄 반환값이 있음
  //반환값의 데이터 타입은 String
  String getColor() {
      return col;
  }

  //sp를 반환할 경우 호출한 곳에 돌려줄 반환값이 있음
  //반환값의 데이터 타입은 int
  int getSpeed() {
      return sp;
  }

  //색깔을 등록하기 위해 메서드 호출시 매개변수 구분하기 위해 클래스 변수는 자신의 변수 : this.col
  void setColor( String col ) {
      this.col = col;
  }

  //속도를 등록시 클래스 변수와 매개변수를 구분하기 위해 클래스 변수는 자신의 변수 : this.sp
  void setSpeed( int sp ) {
      this.sp = sp;
  }
}

public class W4_1 {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        // 2. 인스턴스 생성 : 참조형 변수 c2 -> new 생성자()
        Car3 c2 = new Car3();

        // 3. 인스턴스 변수를 통해서 직접 변수 접근
        // c2.col = "Red";  c2.sp = 10;

        c2.setColor("Red");
        c2.setSpeed(10);

        // 4. 인스턴스 변수를 통해서 메서드 변수 접근
        // 반환값을 호출한 후 출력 : getter사용
        System.out.println("c2.col : " + c2.getColor());
        System.out.println("c2.sp : " + c2.getSpeed());
    }
}


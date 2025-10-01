package W5;
/*
작성자 : 함원준
작성일 : 2025-09-25
프로젝트명 : getter_setter : 접근 제어 수식어 private
분석 :
따라서 private 접근 제한자를 사용 할 경우, 필드변수에는 접근 하는 방법은 두 가지
1. 값 가져오기 : getter함수
2. 값 변경하기 : setter함수
주의 ) 인스턴스 변수명.필드변수 사용 불가!
========================================================================
*/
//1. Car3 클래스 선언과 정의
class Car3{
    //색깔 변수 : 문자열 데이터 타입 col 선언
    private String col;
    // 속도 변수 : 정수형 데이터 타입 sp 선언
    private int sp;

    //클래스 기능 : 속도 올리기 메서드 upSpeed( 매개변수 정수형 sp )선언과 정의
    //값을 반환하지 않음 : 반환형 데이터 타입은 void

    // 변수명이 같아도 클래스변수와 매개변수를 구분하기 위해 클래스 변수는 자신의 변수 : this.sp
    void upSpeed( int sp ) {
        this.sp += sp; // this.sp = this.sp + sp
    }
    void dwonSpeed( int sp ) {
        this.sp -= sp; //sp = sp - sp
    }
    //col를 반환할 경우 문자열로 반환
    String getColor( ) {
        return col;
    }
    //sp를 반환할 경우 정수로 반환
    int getSpeed( ) {
        return sp;
    }
//메서드를 통해서 필드변수 접근하기
//변수명이 같아도 클래스변수와 매개변수를 구분하기 위해 클래스 변수는 자신의 변수 : this.col
void setColor( String col ) {
 this.col = col;
}

//메서드를 통해서 필드변수 접근하기
//변수명이 같아도 클래스변수와 매개변수를 구분하기 위해 클래스 변수는 자신의 변수 : this.sp
void setSpeed( int sp ) {
 this.sp = sp;
}
}

public class W5_1 {
 public static void main(String[] args) {
     // TODO Auto-generated method stub
     // 2. 인스턴스 변수 생성 : 클래스명 인스턴스 변수 = new 클래스명()
     Car3 c2 = new Car3();
     
     // 3. 인스턴스 변수를 통해서 필드 변수 접근불가 : private 일 경우
     /*
      * c2.col = "Red"; c2.sp = 10;
      */
     c2.setColor("Red");
     c2.setSpeed(10);

     // 4. 인스턴스 변수를 통해서 메서드 접근
     //필드변수값 차례로 출력 : getter사용
     System.out.println("c2.col : " + c2.getColor() );
     System.out.println("c2.sp : " + c2.getSpeed() );
 }
}

package W4;

class Student{
    private String name;
    private int score;

    //생성자
    Student(String name, int score){
        this.name = name;
        this.score = score;
    }

    //이름 읽기 전용 getter만 선언
    public String getName() {
        return name;
    }

    //점수 쓰기 전용 setter
    public void setScore(int score) {
        //점수가 0보다 크고 100이하일 경우만 대입
        if( score >= 0 && score <= 100) this.score = score;
    }

    //점수 읽기 전용 getter
    public int getScore() {
        return score;
    }
}

public class W4_4 {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        //생성자를 통한 초기값 지정, 이름과 점수를 직접 입력받지 않는 경우
        Student s = new Student("panda", 99);

        //이름 호출 : getter
        System.out.println(" name : " + s.getName());

        //점수 호출 : getter
        System.out.println(" score : " + s.getScore());

        //setScore()호출
        s.setScore(100);
        System.out.println(" name : " + s.getName());
        System.out.println(" score : " + s.getScore());
    }
}

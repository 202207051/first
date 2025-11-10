package pkg12;

import java.util.*;

public class code11 {
	public static void main(String[] args) {
		ArrayList<String> list = new ArrayList<String>();
		list.add("김철수");
		list.add("나도향");
		list.add("도도반");
		list.add("람보");
		list.add("마동석");
		list.add("박두식");
		System.out.println(list);
		list.set(3, "홍길동");
		list.remove(4);
		System.out.println(list.size());
		System.out.println(list.get(0));
		System.out.println(list.get(3));
		list.remove(4);
		System.out.println(list.contains("마동석")); //TRUE : 배열에 있음 FALSE : 배열에 없음
		System.out.println(list.indexOf("김철수")); //TRUE : 0 FALSE : -1
	}
}

package pkg12;

import java.io.*;
import java.util.*;

public class ex04 {

	public static void main(String[] args) {
		try {
			File file = new File("example103.txt");
			if (!file.exists())
				file.createNewFile();
			
			FileInputStream fis = new FileInputStream(file);
			int i=0;
			
			while((i=fis.read()) != -1) {
				System.out.print((char)i);
			}
			fis.close();
			System.out.println("\n 파일 읽기 성공");
		} catch(Exception e) {
			System.out.println(e);
		}
	}

}

package L04;

import java.util.Scanner;

public class two_run {
	
	public void print() {
		two_file file = new two_file();
		file.fileRead();
	}
	
	public void input(int id,String name,float score) {
		two_file file = new two_file();
		file.fileWrite(id,name,score);
	}

	public void menu() {
		System.out.println("1. 输出成绩列表");
		System.out.println("2. 输入学生成绩");
		System.out.println("输入-1退出程序");
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		
		while(number != -1) {
			if(number == 1)
				print();
			else if(number == 2) {
				System.out.println("学号：");
				int id = scanner.nextInt();
				System.out.println("姓名：");
				String name = scanner.next();
				System.out.println("成绩：");
				float score = scanner.nextFloat();
				
				input(id,name,score);
				System.out.println("成功写入文件");
			}
		
			System.out.println("1. 输出成绩列表");
			System.out.println("2. 输入学生成绩");
			System.out.println("输入-1退出程序");
			number = scanner.nextInt();
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		two_run run = new two_run();
		run.menu();
	}

}

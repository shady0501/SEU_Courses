package homework05;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Random;
import java.io.*;

public class hashmap {
	HashMap<Integer,Student> map = new HashMap<Integer,Student>();
		
	public void initial() {
		Student stu1 = new Student();
		stu1.setName("张三");
		stu1.setScore(80);
		
		Student stu2 = new Student();
		stu2.setName("李四");
		stu2.setScore(79.5f);
		
		Student stu3 = new Student();
		stu3.setName("王五");
		stu3.setScore(91);

		Student stu4 = new Student();
		stu4.setName("赵六");
		stu4.setScore(60);

		Student stu5 = new Student();
		stu5.setName("宋七");
		stu5.setScore(18.6f);
		
		map.put(71108501,stu1);
		map.put(71108502,stu2);
		map.put(71108503,stu3);
		map.put(71108504,stu4);
		map.put(71108505,stu5);
	}

	public String randomName() {
		String[] lastName = {"张","李","王","赵","刘",
									"陈","周","孟","范","高"};
		String[] firstName = {"浩","宇","然","轩","航",
									 "铭","泽","梓","豪","睿"};
		
		Random random = new Random();
		int lastNamee = random.nextInt(10);
		int length = random.nextInt(2);
		int firstName1 = random.nextInt(10);
		int firstName2 = random.nextInt(10);
		String name = "";
		
		if(length == 1) 
			name = lastName[lastNamee] + firstName[firstName1];
		else {
			if(firstName1 != firstName2)
				name = lastName[lastNamee] + firstName[firstName1] + firstName[firstName2];
			else if(firstName1 - 1 > 0)
				name = lastName[lastNamee] + firstName[firstName1] + firstName[firstName1 - 1];
			else 
				name = lastName[lastNamee] + firstName[firstName1] + firstName[firstName1 + 1];
		}
		return name;
	}
		
	public void random() {
		int key = 71108505;
		
		for(int i=0;i<1000;++i) {
			++key;
			Student stu = new Student();
			stu.setName(randomName());
			
			Random random = new Random();
			int score = random.nextInt(101);
			stu.setScore(score);
			map.put(key, stu);
		}
	}
	
	public void fileInput() {
		try(ObjectInputStream obInput = new ObjectInputStream(new FileInputStream("student.dat"))) {
			HashMap<Integer,Student> hamap = (HashMap<Integer,Student>)obInput.readObject();
			Iterator<Integer> iterator = hamap.keySet().iterator();
			
			while(iterator.hasNext()) {
				int key = iterator.next();
				Student stu = hamap.get(key);
				System.out.println(key+" "+stu.getName()+" "+stu.getScore());
			}		
			
			System.out.println("读文件成功");
		}
		catch(IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void fileOutput() {
		initial();
		random();
		
		try(ObjectOutputStream obOutput = new ObjectOutputStream(new FileOutputStream("student.dat"))){
			obOutput.writeObject(map);
			System.out.println("写文件成功");
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public void print() {
		initial();
		random();
		Iterator<Integer> iterator = map.keySet().iterator();
		
		while(iterator.hasNext()) {
			int key = iterator.next();
			Student stu = map.get(key);
			System.out.println(key+" "+stu.getName()+" "+stu.getScore());
		}
	}
}

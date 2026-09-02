package L04;

import java.io.*;
import java.nio.*;

public class two_file {
	
	public void fileRead() {
		try {
			//BufferedInputStream read = new BufferedInputStream(new FileInputStream("d:/test.dat"));
			BufferedReader read = new BufferedReader(new InputStreamReader(new FileInputStream("d:/test.dat"), "UTF-8"));
			
			int b = read.read();
			while(b != -1){
				
				System.out.print((char)b);
				b = read.read();
			}
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public void fileWrite(int id,String name,float score) {
		two_student stu = new two_student();
		stu.setId(id);
		stu.setName(name);
		stu.setScore(score);
		
		try {
			BufferedOutputStream write = new BufferedOutputStream(new FileOutputStream("d:/test.dat",true));
			byte[] b1 = Integer.toString(id).getBytes();
			byte[] b2 = name.getBytes("UTF-8");
			byte[] b3 = Float.toString(score).getBytes();
			write.write(b1);
			write.write(',');
			write.write(b2);
			write.write(',');
			write.write(b3);
			write.write('.');	
			write.write(System.lineSeparator().getBytes());
			write.flush();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
}

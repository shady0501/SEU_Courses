package L04;

import java.io.File;
import java.util.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class one_FileFilter {
	ArrayList<File> files;
	File path;
	String suffix;
	
	//缺省构造函数
	public one_FileFilter() {
		
	}
	
	//构造函数
	public one_FileFilter(File path, String suffix) {
		this.files = new ArrayList<File>();
		this.path  = path;
		this.suffix = suffix;
	}
	
	//递归过滤满足条件的文件名
	public void filter(File path,String suffixName) {
		if(path.isDirectory()) {
			File[] fileInThisPath = path.listFiles();
			
			for(File f:fileInThisPath) {
				if(f.isDirectory())
					filter(f,suffixName);
				else {
					Pattern pattern = Pattern.compile(suffixName);// 使用正则表达式进行匹配
					Matcher matcher = pattern.matcher(f.getName());

					if (matcher.find()) 
						files.add(f);
				}
			}
		}
	}

	//排序
	public void sort(int item) {
		if(item == 1)//升序排序
			Collections.sort(files,(f1,f2)->Long.compare(f1.lastModified(),f2.lastModified()));//lambda表达式
		else if(item == 2)//降序排序
			Collections.sort(files,(f1,f2)->-Long.compare(f1.lastModified(),f2.lastModified()));
		
		if(!files.isEmpty()) {
			System.out.println("匹配到的文件数为："+files.size());
			System.out.println(files.toString());
		}
		else 
			System.out.println("该路径下无匹配文件");
	}
	
	public void menu() {
		Scanner scanner = new Scanner(System.in);
		System.out.println("输入目录名");
		String directoryName = scanner.next();
		System.out.println("输入后缀名");
		String suffixName = scanner.next();
		System.out.println("升序排列输入1，降序排列输入2");
		int item = scanner.nextInt();
		
		one_FileFilter lister = new one_FileFilter(new File(directoryName),suffixName);
		lister.filter(new File(directoryName),suffixName);
		lister.sort(item);
	}
	
	public static void main(String[] args) {
		one_FileFilter lister = new one_FileFilter();
		lister.menu();
	}
}

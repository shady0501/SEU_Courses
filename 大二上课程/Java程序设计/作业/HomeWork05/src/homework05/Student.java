package homework05;

import java.io.*;

public class Student implements Serializable{
	private String name;
	private float score;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public float getScore() {
		return score;
	}
	
	public void setScore(float score) {
		this.score = score;
	}
	
	@Override
	public String toString() {
		return getName()+" "+getScore();
	}
}

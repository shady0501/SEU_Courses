package multiThread;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class ClientThread extends Thread{
	Socket client;
	BufferedReader in;
	PrintWriter out;
	
	public ClientThread() {
		try {
			InetAddress address = InetAddress.getLocalHost();
			client = new Socket(address,ServerDaemon.PORT);
			
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())),true);
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void run() {
		String threadName = Thread.currentThread().getName();
		out.println(threadName);
		try {
			System.out.println(in.readLine());
			//Thread.sleep(3000);
			Thread.sleep(100);
			out.println("bye");
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			try {
				client.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args) {
		for(int i=0;i<12;i++) {
			ClientThread client = new ClientThread();
			client.start();
		}
	}
}

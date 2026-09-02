package netWork;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {	
	public void client() {
		try {
			Socket socket = new Socket("localhost",8088);
			
			try {
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);

				BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));

				while(true) {
					System.out.print("client：");	
					String str = consoleReader.readLine();
					if(str == "exit")
						break;
					out.println(str);
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					System.out.println("server："+in.readLine());
				}
			}finally {
				if(socket != null && !socket.isClosed())
					socket.close();
			}
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		Client cnt = new Client();
		cnt.client();
	}
}

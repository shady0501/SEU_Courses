package netWork;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public void server() {
		try {
			ServerSocket soc = new ServerSocket(8088);
			System.out.println("start");
			Socket socket = soc.accept();

			try {
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);

				while(true) {
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					String str = in.readLine();
					if(str != null) {
						System.out.println("client："+str);
						System.out.print("server：");
						BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
						out.println(consoleReader.readLine());
					}
					else {
						System.out.println("over");
						break;
					}
				}
			}catch(Exception e) {
				e.printStackTrace();
			}finally {
				socket.close();
				soc.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		Server sver = new Server();
		sver.server();
	}
}

package multiThread;

import java.net.ServerSocket;

public class ServerDaemon {
	public static final int PORT = 28080;
	private static final int MAX_THREADS = 10;
	public static int CURRENT_THREADS = 0;
	ServerSocket server;
	
	public ServerDaemon() {
		System.out.println("Server started.");
		try {
			server = new ServerSocket(PORT);
			while(true) {
				if(CURRENT_THREADS < MAX_THREADS) {
					ServerThread thread = new ServerThread(server.accept());
					thread.start();
				}
				Thread.sleep(1);
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			try {
				server.close();
			}catch(Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args) {
		new ServerDaemon();
	}
}

package multiThread;

public class multiThread extends Thread{
	private static final int ticketNumber = 100;
	static int n = 0;
	static Object obj = new Object();

	public void run() {
		while(true) {
			try {
				Thread.sleep(200);
			}
			catch(Exception e) {
				e.printStackTrace();
			}
			synchronized (obj) {
				if(n<ticketNumber) {
					String name = Thread.currentThread().getName();
					System.out.println(name + "正在售出第"+n+"张票");
					n++;
				}
				else {
					String name = Thread.currentThread().getName();
					System.out.println(name + "票已售罄");
					break;
				}
			} 
		}
	}
	int i=0;
	public static void main(String[] args) {
		multiThread t1 = new multiThread();
		t1.setName("窗口1");
		t1.start();
		multiThread t2 = new multiThread();
		t2.setName("窗口2");
		t2.start();
		multiThread t3 = new multiThread();
		t3.setName("窗口3");
		t3.start();	
	}
}

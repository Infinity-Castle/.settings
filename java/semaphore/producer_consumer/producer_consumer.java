import java.util.concurrent.Semaphore;

public class producer_consumer {
    static Semaphore mutex = new Semaphore(1); // Semaphore for mutual exclusion
    static int[] buffer = new int[5]; // Shared buffer
    static int in = 0, out = 0; // Index variables for buffer

    static class Producer implements Runnable {
        public void run() {
            try {
                for (int i = 0; i < 10; i++) {
                    mutex.acquire(); // Acquire mutex to access buffer
                    buffer[in] = i; // Produce item
                    System.out.println("Produced: " + i);
                    in = (in + 1) % 5; // Update index
                    mutex.release(); // Release mutex
                    Thread.sleep(1000); // Simulate some work
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Consumer implements Runnable {
        public void run() {
            try {
                for (int i = 0; i < 10; i++) {
                    mutex.acquire(); // Acquire mutex to access buffer
                    int item = buffer[out]; // Consume item
                    System.out.println("Consumed: " + item);
                    out = (out + 1) % 5; // Update index
                    mutex.release(); // Release mutex
                    Thread.sleep(1500); // Simulate some work
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        Thread producerThread = new Thread(new Producer());
        Thread consumerThread = new Thread(new Consumer());

        producerThread.start();
        consumerThread.start();
    }
}

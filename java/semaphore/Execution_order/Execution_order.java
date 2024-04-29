import java.util.concurrent.Semaphore;

public class Execution_order {
    static Semaphore semaphore = new Semaphore(0); // Semaphore to control execution order

    static void f1() {
        System.out.println("Function f1: Enter username");
        // Simulate user input
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        semaphore.release(); // Signal that f1 has executed
    }

    static void f2() {
        try {
            semaphore.acquire(); // Wait for f1 to execute
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Function f2: Enter password");
    }

    public static void main(String[] args) {
        Thread t2 = new Thread(ExecutionOrder::f2);
        Thread t1 = new Thread(ExecutionOrder::f1);

        t2.start();
        t1.start();
    }
}

// here if i set semaphore count to 0 it will block the thread which has acquired the lock as it has became negative, and will start only when it becomes positive
// and sequence in which threads are starting doesn't matter in this case
// but in case of semaphore count as 1
// it will execute the current process first as it is non blocking and then second process will release the lock afterwards

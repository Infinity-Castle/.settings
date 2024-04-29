import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class Producer_consumer{
    public static void main(String []args){
        BlockingQueue<Integer> queue=new ArrayBlockingQueue<>(10);

        Thread p=new Thread(new Producer(queue));
        Thread c=new Thread(new Consumer(queue));

        p.start();
        c.start();
    }

    static class Producer implements Runnable{
        private final BlockingQueue<Integer> q;
        Producer(BlockingQueue<Integer> q){
            this.q=q;
        }

        @Override
        public void run(){
            for(int i=0;i<=10;i++){
                try{
                    Thread.sleep(1000);
                    q.put(i+1);
                    System.out.println("Producer has produced "+(i+1));
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumer implements Runnable{
        private final BlockingQueue<Integer> q;
        Consumer(BlockingQueue<Integer> q){
            this.q=q;
        }

        @Override
        public void run(){
            for(int i=0;i<=10;i++){
                try{
                    Integer val=this.q.take();
                    Thread.sleep(2000);
                    System.out.println("Consumer has consumed "+val);
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
}
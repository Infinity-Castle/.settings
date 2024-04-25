class program{
    public static void main(String[] args){
        Thread evenThread=new Thread(new Even());
        Thread oddThread=new Thread(new Odd());
        Thread primeThread=new Thread(new Prime());

        evenThread.start();
        oddThread.start();
        primeThread.start();

    }

    static class Even implements Runnable{
        public void run(){
            for(int i=0;i<20;i+=2){
                System.out.println("Even: "+i);

                try{
                    Thread.sleep(1000);
                } catch(InterruptedException e){
                    e.printStackTrace();
                }
            }
        }
    }

    static class Odd implements Runnable{
        public void run(){
            for(int i=1;i<20;i+=2){
                System.out.println("Odd: "+i);

                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Prime implements Runnable{
        public void run(){
            for(int i=2;i<20;i++){
                if(isPrime(i)){
                    System.out.println("Prime: "+i);
                }
                try {
                    Thread.sleep(250);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        boolean isPrime(int num){
            if (num <= 1) {
                return false;
            }
            for (int i = 2; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
}
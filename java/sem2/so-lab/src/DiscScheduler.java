import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

public class DiscScheduler {
    public static class Process {
        private int pos;
        private int arrivalTime;
        private int deadlineTime;
        public Process(int pos, int arrivalTime, int deadlineTime) {
            this.pos = pos;
            this.arrivalTime = arrivalTime;
            this.deadlineTime = deadlineTime;
        }
        public Process(int pos) {
            this.pos = pos;
        }
        public String toString(){
            return "deadlineTime: " + deadlineTime + ", pos: " + pos + ", startTime: " + arrivalTime;
        }
    }

    public static class Disc {
        private ArrayList<Process> processes = new ArrayList();

        public Disc (int n, int maxPos, int maxArrivalTime){
            Random random = new Random();
            for (int i = 0; i < n; i++) {
                add(new Process(random.nextInt(maxPos), random.nextInt(maxArrivalTime), 0));
            }
        }
        public Disc(){
            add(new Process(10, 0, 0));
            add(new Process(20, 10, 0));
            add(new Process(60, 20, 0));
            add(new Process(30, 30, 0));
            add(new Process(10, 40, 0));
        }
        public void add(Process d){
            processes.add(d);
        }
        public void remove(Process d){
            processes.remove(d);
        }

        public int FCFS(int headPos) {
            Collections.sort(processes, Comparator.comparingInt(p -> p.arrivalTime));
            int seekCount = 0;
            for (Process process : processes){
                seekCount += Math.abs(process.pos - headPos);
                headPos = process.pos;
            }
            processes.clear();
            return seekCount;
        }
        public int SSTF(int headPos){
            int seekCount = 0;
            Process currentProcess = processes.get(0);
            for (Process process : processes){
                if(Math.abs(process.pos - headPos))
                seekCount += Math.abs(process.pos - headPos);
                headPos = process.pos;
            }
            return seekCount;
        }
        public int SCAN(int headPos){
            int seekCount = 0;
            return seekCount;
        }
        public int CSCAN(int headPos){
            int seekCount = 0;
            return seekCount;
        }
    }

    public static void main(String[] args) {
        Disc disc;
        int totalSeekCount;

        disc = new Disc();
        totalSeekCount = disc.FCFS(50);
        System.out.println(totalSeekCount);

        disc = new Disc();
        totalSeekCount = disc.SSTF(50);
        System.out.println(totalSeekCount);
    }
}

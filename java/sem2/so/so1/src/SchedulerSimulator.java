import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Random;

public class SchedulerSimulator {
    private static class Process {
        int id;
        int burstTime;
        int arrivalTime;
        int waitingTime;
        int remainingTime;
        int turnaroundTime;
        boolean executed;

        public Process(int id, int burstTime, int arrivalTime) {
            this.id = id;
            this.burstTime = burstTime;
            this.arrivalTime = arrivalTime;
            this.waitingTime = 0;
            this.remainingTime = burstTime;
            this.turnaroundTime = 0;
            this.executed = false;
        }
    }
    private static List<Process> generateProcesses(int n, int maxBurstTime, int maxArrivalTime) {
        List<Process> processes = new ArrayList<>();
        Random random = new Random();
        for (int i = 1; i <= n; i++) {
            int burstTime = random.nextInt(maxBurstTime) + 1;
            int arrivalTime = random.nextInt(maxArrivalTime) + 1;
            processes.add(new Process(i, burstTime, arrivalTime));
        }
        return processes;
    }
    private static void scheduleFCFS(List<Process> processes) {
        int currentTime = 0;
        for (Process process : processes) {
            if (process.arrivalTime > currentTime) {
                currentTime = process.arrivalTime;
            }
            process.waitingTime = currentTime - process.arrivalTime;
            process.turnaroundTime = process.waitingTime + process.burstTime;
            currentTime += process.burstTime;
            process.executed = true;
        }
    }
    private static void scheduleSJF(List<Process> processes) {
        int currentTime = 0;
        List<Process> queue = new ArrayList<>();
        for (Process process : processes) {
            if (process.arrivalTime > currentTime) {
                currentTime = process.arrivalTime;
            }
            queue.add(process);
        }
        while (!queue.isEmpty()) {
            Collections.sort(queue, new Comparator<Process>() {
                @Override
                public int compare(Process p1, Process p2) {
                    return Integer.compare(p1.burstTime, p2.burstTime);
                }
            });
            Process process = queue.get(0);
            process.waitingTime = currentTime - process.arrivalTime;
            process.turnaroundTime = process.waitingTime + process.burstTime;
            currentTime += process.burstTime;
            process.executed = true;
            queue.remove(0);
        }
    }
    private static void scheduleSJFPreemptive(List<Process> processes) {
        int currentTime = 0;
        List<Process> queue = new ArrayList<>();
        Process currentProcess = null;
        while (true) {
            for (Process process : processes) {
                if (process.arrivalTime <= currentTime && !process.executed && (currentProcess == null || process.burstTime < currentProcess.burstTime)) {
                    if (currentProcess != null) {
                        queue.add(currentProcess);
                    }
                    currentProcess = process;
                }
            }
            if (currentProcess == null) {
                break;
            }
            currentProcess.remainingTime--;
            if (currentProcess.remainingTime == 0) {
                currentProcess.waitingTime = currentTime - currentProcess.arrivalTime - currentProcess.burstTime + 1;
                currentProcess.turnaroundTime = currentProcess.waitingTime + currentProcess.burstTime;
                currentProcess.executed = true;
                currentProcess = null;
            }
            currentTime++;
            if (!queue.isEmpty() && currentProcess == null) {
                Collections.sort(queue, new Comparator<Process>() {
                    @Override
                    public int compare(Process p1, Process p2) {
                        return Integer.compare(p1.burstTime, p2.burstTime);
                    }
                });
                currentProcess = queue.get(0);
                queue.remove(0);
            }
        }
    }
    private static void scheduleSJFNonPreemptive(List<Process> processes) {
        int currentTime = 0;
        PriorityQueue<Process> queue = new PriorityQueue<>(Comparator.comparingInt(p -> p.burstTime));
        List<Process> executedProcesses = new ArrayList<>();

        while (!processes.isEmpty() || !queue.isEmpty()) {
            while (!processes.isEmpty() && processes.get(0).arrivalTime <= currentTime) {
                queue.add(processes.remove(0));
            }
            Process currentProcess = queue.poll();
            if (currentProcess == null || currentProcess.executed) {
                currentTime++;
                continue;
            }
            currentProcess.executed = true;
            currentProcess.waitingTime = currentTime - currentProcess.arrivalTime;
            currentProcess.turnaroundTime = currentProcess.waitingTime + currentProcess.burstTime;
            executedProcesses.add(currentProcess);
            currentTime += currentProcess.burstTime;
        }

        processes.clear();
        processes.addAll(executedProcesses);
    }
    private static void scheduleRR(List<Process> processes, int quantum) {
        int currentTime = 0;
        List<Process> queue = new ArrayList<>();
        Queue<Process> roundRobinQueue = new LinkedList<>();
        for (Process process : processes) {
            if (process.arrivalTime > currentTime) {
                currentTime = process.arrivalTime;
            }
            queue.add(process);
        }
        while (!queue.isEmpty() || !roundRobinQueue.isEmpty()) {
            for (Process process : queue) {
                if (process.arrivalTime <= currentTime && !process.executed) {
                    roundRobinQueue.offer(process);
                }
            }
            if (!roundRobinQueue.isEmpty()) {
                Process currentProcess = roundRobinQueue.poll();
                if (currentProcess.remainingTime <= quantum) {
                    currentProcess.waitingTime = currentTime - currentProcess.arrivalTime - currentProcess.burstTime + 1;
                    currentProcess.turnaroundTime = currentProcess.waitingTime + currentProcess.burstTime;
                    currentProcess.executed = true;
                    currentTime += currentProcess.remainingTime;
                    currentProcess.remainingTime = 0;
                } else {
                    currentProcess.remainingTime -= quantum;
                    currentTime += quantum;
                    roundRobinQueue.offer(currentProcess);
                }
            } else {
                currentTime++;
            }
        }
    }

    public static void main(String[] args) {


        int n = 50;
        int maxBurstTime = 20;
        int maxArrivalTime = 20;
        int quantum = 4;


        List<Process> processes = generateProcesses(n, maxBurstTime, maxArrivalTime);
        List<Process> fcfsProcesses = new ArrayList<>(processes);
        scheduleFCFS(fcfsProcesses);
        double fcfsAverageWaitingTime = 0;
        for (Process process : fcfsProcesses) {
            fcfsAverageWaitingTime += process.waitingTime;
        }
        fcfsAverageWaitingTime /= n;
        List<Process> sjfPreemptiveProcesses = new ArrayList<>(processes);


        scheduleSJFPreemptive(sjfPreemptiveProcesses);
        double sjfPreemptiveAverageWaitingTime = 0;
        for (Process process : sjfPreemptiveProcesses) {
            sjfPreemptiveAverageWaitingTime += process.waitingTime;
        }
        sjfPreemptiveAverageWaitingTime /= n;


        List<Process> sjfNonPreemptiveProcesses = new ArrayList<>(processes);
        scheduleSJF(sjfNonPreemptiveProcesses);
        double sjfNonPreemptiveAverageWaitingTime = 0;
        for (Process process : sjfNonPreemptiveProcesses) {
            sjfNonPreemptiveAverageWaitingTime += process.waitingTime;
        }
        sjfNonPreemptiveAverageWaitingTime /= n;


        List<Process> rrProcesses = new ArrayList<>(processes);
        /*scheduleRR(rrProcesses, quantum);
        double rrAverageWaitingTime = 0;
        for (Process process : rrProcesses) {
            rrAverageWaitingTime += process.waitingTime;
        }
        rrAverageWaitingTime /= n;*/


        System.out.println("Algorytm FCFS: średni czas oczekiwania = " + fcfsAverageWaitingTime);
        System.out.println("Algorytm SJF z wywłaszczaniem: średni czas oczekiwania = " + sjfPreemptiveAverageWaitingTime);
        System.out.println("Algorytm SJF bez wywłaszczania: średni czas oczekiwania = " + sjfNonPreemptiveAverageWaitingTime);
        //System.out.println("Algorytm rotacyjny z wyborem kwantu czasu: średni czas oczekiwania = " + rrAverageWaitingTime);
    }
}
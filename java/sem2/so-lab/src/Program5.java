import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Program5 {
    public static class Processor{
        public Processor(int maxPower){
            this.maxPower = maxPower;
        }
        public Processor(){
            maxPower = 1000;
        }
        int currentPowerLevel = 0;
        int maxPower;
        int time = 0;
        public ArrayList<Process> processes = new ArrayList<>();

        int powerLevelZapytanieCount = 0;

        public float getPowerLevel() {
            powerLevelZapytanieCount++;
            return (float)currentPowerLevel / (float)maxPower;
        }
        public int getPowerLevelZapytanieCount(){
            return powerLevelZapytanieCount;
        }
        public int nextTime(){
            for(Process process : processes){
                if(process.decrementTime() <= 0){
                    currentPowerLevel -= process.powerConsumption;
                    processes.remove(process);
                }
            }
        }
        public boolean addProcess(Process process){
            currentPowerLevel += process.powerConsumption;
            return processes.add(process);
        }
    }
    public static class Process{
        public Process(int powerConsumption, int time){
            this.powerConsumption = powerConsumption;
            this.time = time;
        }
        int powerConsumption;
        public int getPowerConsumption(){
            return powerConsumption;
        }
        int time;
        public int getTime(){
            return time;
        }
        public int decrementTime(){
            return --time;
        }
    }
    public static ArrayList<Processor> generateProcessors(int N, int p){
        ArrayList<Processor> processors = new ArrayList<>();
        for(int i = 0; i < N; i++){
            processors.add(new Processor(p));
        }
        return processors;
    }
    public static ArrayList<Process> generateReferenceString(int length, int maxPowerConsumption, int maxTime) {
        ArrayList<Process> referenceString = new ArrayList<Process>();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            referenceString.add(new Process(random.nextInt(maxPowerConsumption), random.nextInt(maxTime)));
        }
        return referenceString;
    }
    public static void Strat1(ArrayList<Process> refString, int N, int p, int z){
        ArrayList<Processor> processors = generateProcessors(N, 1000);
        Random random = new Random();
        for(Process process : refString){
            Processor processor = processors.get(random.nextInt(processors.size()));
            for(int i = 0; i < z; i++){
                Processor processor2 = processors.get(random.nextInt(processors.size()));
                if(processor2.getPowerLevel() <= p){
                    processor = processor2;
                    break;
                }
            }
            processor.addProcess(process);
        }
    }
    public static void Strat2(ArrayList<Process> refString, int N, int p){
        ArrayList<Processor> processors = generateProcessors(N, 1000);
        ArrayList<Processor> processors2 = new ArrayList<>(processors);
        Random random = new Random();
        for(Process process : refString){
            Processor processor = processors.get(random.nextInt(processors.size()));
            if(processor.getPowerLevel() > p){
                for(Processor processor2 : processors2){
                    if(processor2.getPowerLevel() <= p){
                        processor = processor2;
                        break;
                    }
                    else processors2.remove(processor2); //can i do this???
                }
            }
            processor.addProcess(process);
        }
    }
    public static void Strat3(ArrayList<Process> refString, int N, int p, int r){
        ArrayList<Processor> processors = generateProcessors(N, 1000);
        Random random = new Random();
        for(Process process : refString){
            Processor processor = processors.get(random.nextInt(processors.size()));

        }
    }
    public static void main(String[] args) {
        int p = 0;
        int r = 0;
        int z = 0;
        int N = 0;

        ArrayList<Process> refString = generateReferenceString(1000, 100, 100);
        Strat1(refString, N, p, z);
        Strat2(refString, N, p);
        Strat3(refString, N, p, r);
    }
}

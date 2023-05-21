public class Student2StrExec implements IExecutor<Student, String>{
    StringBuffer line = new StringBuffer();
    @Override
    public void execute(Student elem){
        line.append(elem.toString() + ", ");
    }
    @Override
    public String getResult(){
        line.delete(line.length() - 2, line.length());
        return line.toString();
    }
}

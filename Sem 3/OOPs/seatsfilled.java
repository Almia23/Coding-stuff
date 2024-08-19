public class SeatsFilledException extends Exception {
    public SeatsFilledException() {
        super("Seats are already filled for this year of joining.");
    }
}

public class Student {
    private static int lastTwoDigitsOfYear = 23; // Assuming current year is 2023
    private static int nextRegistrationNumber = lastTwoDigitsOfYear * 100;

    private String name;
    private int registrationNumber;

    public Student(String name) throws SeatsFilledException {
        if (nextRegistrationNumber > lastTwoDigitsOfYear * 100 + 25) {
            throw new SeatsFilledException();
        }

        this.name = name;
        this.registrationNumber = nextRegistrationNumber;
        nextRegistrationNumber++;
    }

    public String getName() {
        return name;
    }

    public int getRegistrationNumber() {
        return registrationNumber;
    }

    public static void main(String[] args) {
        try {
            Student student1 = new Student("Alice");
            System.out.println("Student 1 registered successfully. Name: " + student1.getName() + ", Reg. Number: " + student1.getRegistrationNumber());
        } catch (SeatsFilledException e) {
            System.out.println("Student 1 registration failed: " + e.getMessage());
        }

        try {
            Student student2 = new Student("Bob");
            System.out.println("Student 2 registered successfully. Name: " + student2.getName() + ", Reg. Number: " + student2.getRegistrationNumber());
        } catch (SeatsFilledException e) {
            System.out.println("Student 2 registration failed: " + e.getMessage());
        }
    }
}

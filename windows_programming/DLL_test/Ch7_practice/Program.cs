using System;

class Person
{
    // default: private
    int id;
    protected string name;

    void Say()
    {
        Console.WriteLine("Person");
    }
}

class Student : Person
{
    void Say()
    {
        Console.WriteLine("Student");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Student student = new Student();    
        
    }
}


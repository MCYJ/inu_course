using System;



class Program
{
    class Person
    {
        public void Func1()
        {
            Console.WriteLine("Fun1");
        }

        public void Func2()
        {
            Console.WriteLine("Fun2");
        }
        public static void Hi()
        {
            Console.WriteLine("Hi");
        }
    }

    delegate void DelegateFunc();

    static void Main(string[] args)
    {
        Person p1 = new Person();

        p1.Func1();

        DelegateFunc insa = new DelegateFunc(Person.Hi);

        insa();
    }
}
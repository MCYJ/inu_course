using System;
namespace test1
{
    namespace test2
    {
        class NamespaceTest
        {
            static void Main(string[] args)
            {
                int a = 2;
                Console.WriteLine(new OuterClass());
            }
        }
    }
    
}

class OuterClass
{
    public static int a = 1;

    public OuterClass()
    {
        Console.WriteLine("instance initialized");
    }
}
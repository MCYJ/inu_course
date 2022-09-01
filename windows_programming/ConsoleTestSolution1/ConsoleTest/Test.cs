using System;
class Test
{
    // a와 b 비교하여 조건에 따라 값 반환
    static string abc(int a, int b)
    {
        if (a == b) return "정답";
        else if (a < b) return "너무 커";
        else return "너무 작어";
    }
    static void Main(string[] args)
    {
        //string s = "123";
        //float f = 321;

        //int hap = Convert.ToInt32(s) + Convert.ToInt32(f);

        //Console.WriteLine(hap);

        //string s = "";

        //for (int i = 97; i < 97+26; i++)
        //{
        //    s += Convert.ToChar(i);
        //    Console.WriteLine(s);
        //}

        //Console.Write("하나의 수 s1 입력 : ");
        //string s1 = Console.ReadLine();
        //Console.Write("또 하나의 s2 입력 : ");
        //string s2 = Console.ReadLine();
        //Console.Write("{0}과 {1}의 합은 = {2}", s1, s2, Convert.ToInt32(s1) + Convert.ToInt32(s2));

        Random su = new Random();

        int fix_su = su.Next(1,100);
        
        int num_try = 0;

        while (true)
        {
            Console.WriteLine("1부터 100사이 상대가 생각하고 있는 수를 입력하세요.");
            int input_su = Convert.ToInt32(Console.ReadLine());

            num_try++;

            string r = abc(fix_su, input_su);

            if (r == "정답")
            {
                Console.WriteLine("랜덤 값은 "+fix_su);
                Console.WriteLine("시도 횟수 = "+num_try);
                break;
            } else
            {
                Console.WriteLine(r);
            }
        }

        

    }
    
}
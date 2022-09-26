using System;

   class ProgramDoWhile
   {
        static void Main(string[] args)
        {
            int numTotal = 0, evenNum = 0, evenTotal = 0, oddNum = 0, oddTotal = 0;
        do
        {
            Console.Write("하나의 정수 입력 : ");
            int num = Convert.ToInt32(Console.ReadLine());
            if (num == -1)
            {
                Console.WriteLine("입력 데이터 갯수는 {0}", numTotal);
                Console.WriteLine("입력 데이터 짝수 갯수는 {0}", evenNum);
                Console.WriteLine("입력 데이터 짝수의 합은 {0}", evenTotal);
                Console.WriteLine("입력 데이터 홀수 갯수는 {0}", oddNum);
                Console.WriteLine("입력 데이터 홀수의 합은 {0}", oddTotal);
                break;
            }

            numTotal++;
            if (num % 2 == 0)
            {
                evenNum++;
                evenTotal += num;
            }
            else
            {
                oddNum++;
                oddTotal += num;
            }
        } while (true);
        }
}


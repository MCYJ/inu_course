using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

class RockScissorsPaper
{
    static string GetResult(int com, int user)
    {
        if (com == user)
        {
            return "비겼습니다";
        } 
        else
        {
            if (com == 1)
            {
                if (user == 2) return "이겼습니다";
                return "졌습니다";
            }
            if (com == 2)
            {
                if (user == 1) return "졌습니다";
                return "졌습니다";
            }
            if (com == 3)
            {
                if (user == 1) return "이겼습니다";
                return "졌습니다";
            }

            // 비정상 상황
            return "오류발생";
        }
        
    }
    static void Main(string[] args)
    {
        Random r = new Random();
        while (true)
        {
            int num = r.Next(1, 3);
            Console.Write("가위 바위 보를 입력하세요.");
            string choice = Console.ReadLine();
            Console.WriteLine(choice);
            int choiceNum = 0;
            if (choice == "가위")
            {
                choiceNum = 1;
            }
            else if (choice == "바위")
            {
                choiceNum = 2;
            }
            else
            {
                choiceNum = 3;
            }

            string result = GetResult(num, choiceNum);
            Console.Write("컴퓨터의 선택 : "+num);
            Console.WriteLine(result);
            if (result == "이겼습니다")
            {
                break; 
            }
        }
       

    }
}


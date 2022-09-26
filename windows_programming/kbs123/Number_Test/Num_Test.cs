//// //  [1] 단계  
//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//        // Next(n,m) ; n부터 m 까지 양의 정수 발생
//        // Next(n); 0부터 n-1 사이의 양의 정수 발생

//        int count = 0;
//        while (true)
//        {
//            Console.Write(" 상대가 생각하고 있는 수를 입력하세요(1-100사이의 수 ):  ");
//            int input_su = Convert.ToInt16(Console.ReadLine());

//            count++;
//            if (fix_su < input_su)
//            {
//                Console.WriteLine("너무 커");
//            }
//            else if (fix_su > input_su)
//            {
//                Console.WriteLine("너무 작어");
//            }
//            else if (fix_su == input_su)
//            {
//                Console.WriteLine("정답");
//                break;
//            }
//        }
//        Console.WriteLine("시도횟수 = {0}", count);
//        Console.WriteLine("랜덤 수는  = {0}", fix_su);

//    }
//}






// //  [2] 단계  
// // ==============   메소드로 처리 ======================

using System;

class Num_Test
{
    static void Main(string[] args)
    {
        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
        Random Number = new Random();
        int fix_su = Number.Next(1, 100);
        int input_su; int count = 0;
        while (true)
        {
            Console.Write(" 상대가 생각하고 있는 수를 입력하세요:  ");
            input_su = Convert.ToInt16(Console.ReadLine());
            count++;
            string r = abc(fix_su, input_su);  // 매개변수 2개를 가지고 함수호출
            Console.WriteLine(r);
            if (r == "정답")
            {
                Console.WriteLine("시도횟수 = {0}", count);
                Console.WriteLine("랜덤 수는  = {0}", fix_su);
                break;
            }
        }

//        ////  [2-1] Main 안에 있을 때  74부터 92까지 주석
//        string abc(int a, int b)
//        {
//            string r_value = "";
//            if (a < b)
//            {
//                r_value = "너무 커";
//            }
//            else if (a > b)
//            {
//                r_value = "너무 작어";
//            }
//            else if (a == b)
//            {
//                r_value = "정답";

//            }
//            return r_value;
//        }  // 리턴값으로 너무 커, 너무작어, 정답  으로 함


    }


    ////  [2-2] Main 밖에 있을 때 - 같은 클래스 내에 있을 때   98부터 117까지 주석
    //// 다음과 같은 에러 메세지가 출력 됨 - static 아닌 필드, 메서드 또는 속성abc(int, int) 에 객체 참조가 필요합니다.
    string abc(int a, int b)
    {
        string r_value = "";
        if (a < b)
        {
            r_value = "너무 커";
        }
        else if (a > b)
        {
            r_value = "너무 작어";
        }
        else if (a == b)
        {
            r_value = "정답";

        }
        return r_value;
    }  // 리턴값으로 너무 커, 너무작어, 정답  으로 함



    ////  [2-3] Main 밖에 있을 때 - 같은 클래스 내에 있을 때   121부터 141까지 주석
    //// 다음과 같은 에러 메세지가 출력 됨 - static 아닌 필드, 메서드 또는 속성abc(int, int) 에 객체 참조가 필요합니다.
    ///
    //string abc(int a, int b)     // 에러 확인 후 static 추가  할 것
    //{
    //    string r_value = "";
    //    if (a < b)
    //    {
    //        r_value = "너무 커";
    //    }
    //    else if (a > b)
    //    {
    //        r_value = "너무 작어";
    //    }
    //    else if (a == b)
    //    {
    //        r_value = "정답";

    //    }
    //    return r_value;
    //}  // 리턴값으로 너무 커, 너무작어, 정답  으로 함


}


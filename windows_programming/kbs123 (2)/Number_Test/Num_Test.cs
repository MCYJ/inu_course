//// //  [1] 단계  1-40 라인 까지
//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//         int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//         Next(n,m) ; n부터 m 까지 양의 정수 발생
//         Next(n); 0부터 n-1 사이의 양의 정수 발생

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
//// [1] 단계 끝



//// //  [2] 단계  Main 안에 메소드가 있을때    44 -94 라인까지
//// // ==============   메소드로 처리 ======================

//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//        int input_su; int count = 0;
//        while (true)
//        {
//            Console.Write(" 상대가 생각하고 있는 수를 입력하세요:  ");
//            input_su = Convert.ToInt16(Console.ReadLine());
//            count++;
//            string r = abc(fix_su, input_su);  // 매개변수 2개를 가지고 함수호출
//            Console.WriteLine(r);
//            if (r == "정답")
//            {
//                Console.WriteLine("시도횟수 = {0}", count);
//                Console.WriteLine("랜덤 수는  = {0}", fix_su);
//                break;
//            }
//        }



//        //////  [2] Main 안에 메소드가 있을 때  
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
//    }
//}
//// [2] 단계  끝



//////  [3] 단계 Main 밖에 메소드가 있을 때   98 - 149 라인까지
//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//        int input_su; int count = 0;
//        while (true)
//        {
//            Console.Write(" 상대가 생각하고 있는 수를 입력하세요:  ");
//            input_su = Convert.ToInt16(Console.ReadLine());
//            count++;
//            string r = abc(fix_su, input_su);  // 매개변수 2개를 가지고 함수호출
//            Console.WriteLine(r);
//            if (r == "정답")
//            {
//                Console.WriteLine("시도횟수 = {0}", count);
//                Console.WriteLine("랜덤 수는  = {0}", fix_su);
//                break;
//            }
//        }

//    }



//    //  [3] 단계 Main 밖에 메소드가 있을 때
//    // 다음과 같은 에러 메세지가 출력 됨 - static 아닌 필드, 메서드 또는 속성abc(int, int) 에 객체 참조가 필요합니다.
//      static string abc(int a, int b)    // 메소드 앞에 static 이 붙는다
//      {
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
//}
//// //[3] 단계 끝




//// // [4] 단계    메소드가 다른 클래스에 있을때   154 - 208 라인까지
//// // abc 이름이 현재 컨텍스트에 없습니다.  에러메세지 나옴
//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//        int input_su; int count = 0;
//        while (true)
//        {
//            Console.Write(" 상대가 생각하고 있는 수를 입력하세요:  ");
//            input_su = Convert.ToInt16(Console.ReadLine());
//            count++;
//            string r = Num_Method.abc(fix_su, input_su);  // abc 메소드가 있는 위치를 지정해 줌
//            Console.WriteLine(r);                // abc 가 오픈을 허락하지 않으므로 접근이 안됨 public  붙여야함
//            if (r == "정답")
//            {
//                Console.WriteLine("시도횟수 = {0}", count);
//                Console.WriteLine("랜덤 수는  = {0}", fix_su);
//                break;
//            }
//        }

//    }
//} // 추가함



//    //  [4] 단계 메소드가 다른 클래스에 있을 때
//class Num_Method    // 추가함 
//{                  // 추가함
//    public static string abc(int a, int b)    // public 추가해 줌
//    {
//        string r_value = "";
//        if (a < b)
//        {
//            r_value = "너무 커";
//        }
//        else if (a > b)
//        {
//            r_value = "너무 작어";
//        }
//        else if (a == b)
//        {
//            r_value = "정답";

//        }
//        return r_value;
//    }  // 리턴값으로 너무 커, 너무작어, 정답  으로 함
//}
//// //[4] 단계 끝






//// // [5] 단계   클래스가 다른 파일로 분리되어 있을 때    215 - 269 라인까지
//// 
//using System;

//class Num_Test
//{
//    static void Main(string[] args)
//    {
//        // int fix_su = 44;  // 상대방이 생각한 임의의 수- 각자 다르게 지정할것
//        Random Number = new Random();
//        int fix_su = Number.Next(1, 100);
//        int input_su; int count = 0;
//        while (true)
//        {
//            Console.Write(" 상대가 생각하고 있는 수를 입력하세요:  ");
//            input_su = Convert.ToInt16(Console.ReadLine());
//            count++;
//            string r = Num_Method.abc(fix_su, input_su);  // abc 메소드가 있는 위치를 지정해 줌
//            Console.WriteLine(r);                // abc 가 오픈을 허락하지 않으므로 접근이 안됨 public  붙여야함
//            if (r == "정답")
//            {
//                Console.WriteLine("시도횟수 = {0}", count);
//                Console.WriteLine("랜덤 수는  = {0}", fix_su);
//                break;
//            }
//        }

//    }
//} // 추가함



////  [5] 클래스가 다른 파일로 분리되어 있을 때
//class Num_Method    // 추가함 
//{                  // 추가함
//    public static string abc(int a, int b)    // public 추가해 줌
//    {
//        string r_value = "";
//        if (a < b)
//        {
//            r_value = "너무 커";
//        }
//        else if (a > b)
//        {
//            r_value = "너무 작어";
//        }
//        else if (a == b)
//        {
//            r_value = "정답";

//        }
//        return r_value;
//    }  // 리턴값으로 너무 커, 너무작어, 정답  으로 함
//}
//// //[5] 단계 끝
///
///  (1) 247- 269 라인 복사 후 주석처리
///  (2) 프로젝트에서 다른 크래스 만들고 글래스 이름을 Num_Method  로 함
///  (3) 새로 만든 클래스에서 Num_Method 에서 내용 모두 지우고 붙여넣기 후 Number_Test 실행함

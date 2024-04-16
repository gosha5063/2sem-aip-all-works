using System;

namespace example{
    class Program{
        
        static string input(){
            string s = Console.ReadLine();
            return s;
        }   
        static void Main(){
            Console.WriteLine("Введите количество сток n: ");
            int n = int.Parse(input());
            string [] s = new string[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"Введите строку номер{i+1}");
                s[i] = input();
                int groups = 0;
                int count = 0;
                foreach (char item in s[i])
                {
                    if(char.IsAsciiLetter(item)){
                        count++;
                    }
                    else{
                        if(count!=0){
                            groups++;
                        }
                        count = 0;
                    }
                }
                if(count!=0)groups++;
                if(groups>1){
                    s[i] = s[i].Replace('+','1');
                    s[i] = s[i].Replace('-','2');
                    s[i] = s[i].Replace('*','3');
                }
            }
        for (int i = 0; i < n; i++)
        {
            Console.WriteLine(s[i]);
        }
        
        }

    }
}
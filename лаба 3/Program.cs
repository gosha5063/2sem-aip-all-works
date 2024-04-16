using System;

namespace ReferenceTypeExample
{
    class Squere{
        private double a,b,c;
        private int left, right;
        public Squere(double a, double b, double c, int left, int right){
            this.a = a;this.b = b;this.c = c;this.left = left;this.right = right;
        }

        public List<double> Find_sol(){
            List<double> arr = new List<double>();
            if(a == 0 && b!=0){arr.Add(b = -c/b); return arr;}
            if(a == 0 && b == 0){Console.WriteLine("Корней нет");return arr;}
            double discr = Math.Pow(b,2) - 4*a*c;
            if(discr < 0){Console.WriteLine("Корней нет");return arr;}
            arr.Add((-b + Math.Pow(discr,0.5))/2*a);
            if(arr[0] != (-b - Math.Pow(discr,0.5))/2*a){
                arr.Add((-b - Math.Pow(discr,0.5))/2*a);
            }
            return arr;
        }   
    }
    class Program
    {
        static void Main(string[] args)
        {
            double a,b,c;
            Console.WriteLine("Введите коэфиценты a,b,c");
            try{
                string[] split = Console.ReadLine().Split(' ');
                a = double.Parse(split[0]);
                b = double.Parse(split[1]); 
                c = double.Parse(split[2]);
                Squere s = new Squere(a,b,c,-100,100);
                foreach(double i in s.Find_sol()){
                    Console.WriteLine(i);
                }
            }
            
            catch(Exception ex)
            {
                Console.WriteLine($"Ваш ввод некорректен: {ex.Message}");
            }
        }
    }
}

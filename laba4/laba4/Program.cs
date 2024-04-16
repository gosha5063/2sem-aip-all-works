using System;
using System.Data;

namespace ReferenceTypeExample
{

    class Program{
        static double[,] Plus(double[,]a, double[,]b){
            int n = a.GetLength(0);
            double[,] res = new double[n,n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    {
                        res[i,j] = a[i,j] + b[i,j];
                    }
            }
            return res;
        }
        static double[,] Multiple(double[,]a, double[,]b){
            int n = a.GetLength(0);
            double[,] res = new double[n,n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j< n; j++)
                {
                    res[i,j] = 0;
                    for (int m = 0; m < n; m++)
                    {
                        res[i,j] += a[i,m] * b[m,j];
                    }

                }
            }
            return res;
        }
        private static void Print(double [,] matrix){
            int n = matrix.GetLength(0);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(matrix[i,j] + " ");
                }
                Console.WriteLine();
            }
        }
        static void Main(){
            Console.WriteLine("Введите размер матрицы n");
            int n;
            n = int.Parse(Console.ReadLine());
            double[,] a = new double[n,n];
            double[,] b = new double[n,n];
            double[,] c = new double[n,n];
            double[][,] arr = {a,b,c};
            for (int cout = 0; cout < 3; cout++)
            {
                Console.WriteLine($"Введите {cout+1} матрицу");
                for (int i = 0; i < n; i++)
                {
                    string[] s = Console.ReadLine().Split();
                    for (int j = 0; j < n; j++)
                    {
                        arr[cout][i,j] = double.Parse(s[j]);
                    }
                }
            }
            Console.WriteLine("Result: ");
            Print(Multiple(Plus(a,b),c));
        }
    }
}
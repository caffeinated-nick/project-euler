using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fibonacci
{
    class Program
    {
        static void Main(string[] args)
        {
            int ans = 0;
            int j = 1;
            int i = 2;
            int temp;
            while(i < 4000000)
            {
                if(i % 2 == 0)
                {
                    ans += i;
                }
                temp = i;
                i += j;
                j = temp;
                Console.WriteLine(ans);
            }
            Console.WriteLine("The answer is: " + ans);
            Console.ReadLine();
        }
    }
}

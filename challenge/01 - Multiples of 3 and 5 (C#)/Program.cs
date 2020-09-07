using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Multiples_of_3_and_5
{
    class Program
    {
        static void Main(string[] args)
        {
            int ans = 0;
            for(int i = 0; i < 1000; i++)
            {
                if(i % 3 == 0)
                {
                    ans += i;
                }
                else if(i % 5 == 0)
                {
                    ans += i;
                }
                Console.WriteLine(ans);
            }
            Console.WriteLine("The answer is: " + ans);
            Console.ReadLine();
        }
    }
}

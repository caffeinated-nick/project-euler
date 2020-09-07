package com.company;

public class Main {

    public static void main(String[] args) {
        for(int a = 1000; a > 0; a--)
        {
            for(int b = 1000; b > a; b--)
            {
                for(int c = 1000; c > b; c--)
                {
                    if(a + b + c == 1000)
                    {
                        if((a * a) + (b * b) == (c * c))
                        {
                            System.out.println("a is: " + a + ", b is: " + b + ", c is: " + c);
                            System.out.println(a * b * c);
                        }
                    }
                }
            }
        }
    }
}

package com.company;

public class Main {

    public static void main(String[] args) {

        double sum = 2;

        for(int i = 2; i < 2000000; i++)
        {
            if(isPrime(i))
            {
                sum += i;
                System.out.println(i + " is prime, bringing the total to: " + sum);
            }
        }
        System.out.printf("%.0f", sum);
    }

    public static boolean isPrime(int num)
    {
        if(num % 2 == 0)
        {
            return false;
        }

        for(int i = 3; i < num; i+=2)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

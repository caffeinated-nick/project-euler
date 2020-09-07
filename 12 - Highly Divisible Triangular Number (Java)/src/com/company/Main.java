package com.company;

import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {
        int currentNumber = 1, divisor = 0, prevDivisor = 0, count = 1;
        boolean finished = false;
        double testNum = 0, sumTotal = 0;

        ArrayList primeDivisors = new ArrayList();
        ArrayList divisorQuantity = new ArrayList();


        while (!finished) {
            sumTotal += currentNumber;
            testNum = sumTotal;
            divisor = 0;
            prevDivisor = 0;
            count = 1;
            primeDivisors.clear();
            divisorQuantity.clear();

            //get all of the prime divisors
            for(int i = 2; i < testNum; i++){
                if(testNum % i == 0){
                    testNum = testNum / i;
                    primeDivisors.add(i);
                    i = 1;
                }
            }
            primeDivisors.add((int) testNum);

            System.out.println("Current natural number: " + currentNumber + ", Sum total: " + sumTotal);
            System.out.println("Prime factors of that number: ");
            Collections.sort(primeDivisors);

            //find the number of positive divisors per prime factor
            for(int i = 0; i < primeDivisors.size(); i++){
                divisor = (int) primeDivisors.get(i);
                if(i != 0){
                    if(prevDivisor == divisor){
                        count++;
                    } else {
                        divisorQuantity.add(count + 1);
                        count = 1;
                    }
                }
                System.out.print(divisor + ", ");
                prevDivisor = divisor;
            }
            divisorQuantity.add(count + 1);

            System.out.println();
            System.out.println("Divisor quantities: ");
            System.out.println(divisorQuantity + ", ");

            count = 1;

            //multiple these sums to find the quantity
            for(int i = 0; i < divisorQuantity.size(); i++){
                count *= (int) divisorQuantity.get(i);
            }

            System.out.println("The total divisors was: " + count);
            currentNumber++;
            if(count >= 500){
                finished = true;
                System.out.println((int) sumTotal);
            }
            System.out.println();
        }
    }
}

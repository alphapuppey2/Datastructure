package StackJava;

import java.util.*;

public class StackArray {

    public static void main(String args[]) {
        Stack<String> head = new Stack<String>();

        head.push("U");
        head.push("S");
        head.push("C");

        Display(head);
        head.pop();
        System.out.println("The Top is :: " + head.peek());
        Display(head);

    }

    public static String Top(Stack<String> L) {
        return L.peek();
    }

    public static void Display(Stack<String> C) {
        for (String s : C) {
            System.out.println(s);
        }

    }
}

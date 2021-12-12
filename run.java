//Coded by osman tosun
class Node {

    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {

    Node head = null;
    public static int es;

    public void add(Node x) {
        if (head == null) {
            head = x;
            es++;
        } else {
            Node tmp = head;
            while (tmp.next != null) {
                tmp = tmp.next;
            }
            tmp.next = x;
            es++;
        }
    }

    public int[] toArray() {
        Node tmp = head;
        int i = 0, arrLen = 0;
        int arr[] = new int[es];
        while (tmp != null) {
            arr[i] = tmp.data;
            tmp = tmp.next;
            i++;
        }
        return arr;
    }

}

class MergeSort {

    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i = 0; i < n1; ++i) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void sort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            sort(arr, l, m);
            sort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
}

public class run {

    public static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        LinkedList a = new LinkedList();
        Node n0 = new Node(10);
        Node n1 = new Node(550);
        Node n2 = new Node(30);
        Node n3 = new Node(50);
        Node n4 = new Node(100);
        Node n5 = new Node(1);

        a.add(n0);
        a.add(n1);
        a.add(n2);
        a.add(n3);
        a.add(n4);
        a.add(n5);

        int array[] = a.toArray();
        System.out.println("Befor Sorting");
        printArray(array);

        System.out.println("\n**************\n");

        MergeSort ob = new MergeSort();
        ob.sort(array, 0, array.length - 1);
        System.out.println("After Sorting");
        printArray(array);
    }
}
//Coded by osman tosun

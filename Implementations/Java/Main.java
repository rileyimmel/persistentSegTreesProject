public class Main {
    public static void main(String[] args) {
        // ——— Example Case 0 (original) ———
        System.out.println("\033[1;33m=== Starting Example Case 0 ===\033[0m");
        long[] a = {1, 2, 3, 4, 5};
        PST S1 = new PST(5);
        S1.construct(a);
        // version 0 in red
        System.out.println("The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{1, 2, 3, 4, 5}\033[0m");
        System.out.println("Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..2]\033[0m gives: \033[1;31m"
                + S1.query(0, 1, 2) + "\033[0m");
        // update → version 1 in blue
        System.out.println("\033[1;36mApplying update: index = 1, new value = 5\033[0m");
        S1.update(1, 5);
        System.out.println("The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{1, 5, 3, 4, 5}\033[0m");
        System.out.println("Querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..2]\033[0m gives: \033[1;34m"
                + S1.query(1, 1, 2) + "\033[0m\n");

        // ——— Example Case 1 | All zeros, update at the end ———
        System.out.println("\033[1;33m=== Starting Example Case 1 | All zeros, update at the end ===\033[0m");
        long[] b = {0, 0, 0, 0};
        PST S2 = new PST(4);
        S2.construct(b);
        // version 0 in red
        System.out.println("The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{0, 0, 0, 0}\033[0m");
        System.out.println("Querying \033[1;31mversion 0\033[0m on range \033[1;31m[0..3]\033[0m gives: \033[1;31m"
                + S2.query(0, 0, 3) + "\033[0m");
        // version 1 in blue
        System.out.println("\033[1;36mApplying update: index = 3, new value = 7\033[0m");
        S2.update(3, 7);
        System.out.println("The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{0, 0, 0, 7}\033[0m");
        System.out.println("Querying \033[1;34mversion 1\033[0m on range \033[1;34m[2..3]\033[0m gives: \033[1;34m"
                + S2.query(1, 2, 3) + "\033[0m\n");

        // ——— Example Case 2 | Positives & Negatives ———
        System.out.println("\033[1;33m=== Starting Example Case 2 | Positives & Negatives ===\033[0m");
        long[] d = {1, -1, 2, -2, 3};
        PST S4 = new PST(5);
        S4.construct(d);
        // version 0 in red
        System.out.println("The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{1, -1, 2, -2, 3}\033[0m");
        System.out.println("Querying \033[1;31mversion 0\033[0m on range \033[1;31m[0..4]\033[0m gives: \033[1;31m"
                + S4.query(0, 0, 4) + "\033[0m");
        // version 1 in blue
        System.out.println("\033[1;36mApplying update: index = 1, new value = 5\033[0m");
        S4.update(1, 5);
        System.out.println("The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{1, 5, 2, -2, 3}\033[0m");
        System.out.println("Querying \033[1;34mversion 1\033[0m on range \033[1;34m[0..2]\033[0m gives: \033[1;34m"
                + S4.query(1, 0, 2) + "\033[0m\n");

        // ——— Example Case 3 | A tree with 4 versions ———
        System.out.println("\033[1;33m=== Starting Example Case 3 | A tree with 4 versions ===\033[0m");
        long[] e = {10, 20, 30, 40};
        PST S5 = new PST(4);
        S5.construct(e);
        // version 0 in red
        System.out.println("The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{10, 20, 30, 40}\033[0m");
        System.out.println("Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..2]\033[0m gives: \033[1;31m"
                + S5.query(0, 1, 2) + "\033[0m");
        // version 1 in blue
        System.out.println("\033[1;36mApplying update: index = 0, new value = 100\033[0m");
        S5.update(0, 100);
        System.out.println("The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{100, 20, 30, 40}\033[0m");
        System.out.println("Querying \033[1;34mversion 1\033[0m on range \033[1;34m[0..1]\033[0m gives: \033[1;34m"
                + S5.query(1, 0, 1) + "\033[0m");
        // version 2 in green
        System.out.println("\033[1;36mApplying update: index = 3, new value = 5\033[0m");
        S5.update(3, 5);
        System.out.println("The tree at \033[1;32mversion 2\033[0m is storing: \033[1;32m{100, 20, 30, 5}\033[0m");
        System.out.println("Querying \033[1;32mversion 2\033[0m on range \033[1;32m[2..3]\033[0m gives: \033[1;32m"
                + S5.query(2, 2, 3) + "\033[0m");
        // version 3 in magenta
        System.out.println("\033[1;36mApplying update: index = 1, new value = 50\033[0m");
        S5.update(1, 50);
        System.out.println("The tree at \033[1;35mversion 3\033[0m is storing: \033[1;35m{100, 50, 30, 5}\033[0m");
        System.out.println("Querying \033[1;35mversion 3\033[0m on range \033[1;35m[0..3]\033[0m gives: \033[1;35m"
                + S5.query(3, 0, 3) + "\033[0m\n");

        // ——— Example Case 4 | Querying a past version ———
        System.out.println("\033[1;33m=== Starting Example Case 4 | Querying a past version ===\033[0m");
        long[] f = {2, 4, 6, 8, 10};
        PST S6 = new PST(5);
        S6.construct(f);
        // version 0 in red
        System.out.println("The tree at \033[1;31mversion 0\033[0m is storing: \033[1;31m{2, 4, 6, 8, 10}\033[0m");
        System.out.println("Querying \033[1;31mversion 0\033[0m on range \033[1;31m[1..4]\033[0m gives: \033[1;31m"
                + S6.query(0, 1, 4) + "\033[0m");
        // version 1 in blue
        System.out.println("\033[1;36mApplying update: index = 2, new value = 12\033[0m");
        S6.update(2, 12);
        System.out.println("The tree at \033[1;34mversion 1\033[0m is storing: \033[1;34m{2, 4, 12, 8, 10}\033[0m");
        System.out.println("Querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..4]\033[0m gives: \033[1;34m"
                + S6.query(1, 1, 4) + "\033[0m");
        // version 2 in green
        System.out.println("\033[1;36mApplying update: index = 4, new value = 0\033[0m");
        S6.update(4, 0);
        System.out.println("The tree at \033[1;32mversion 2\033[0m is storing: \033[1;32m{2, 4, 12, 8, 0}\033[0m");
        System.out.println("Querying \033[1;32mversion 2\033[0m on range \033[1;32m[1..4]\033[0m gives: \033[1;32m"
                + S6.query(2, 1, 4) + "\033[0m");
        // version 3 in magenta
        System.out.println("\033[1;36mApplying update: index = 3, new value = 16\033[0m");
        S6.update(3, 16);
        System.out.println("The tree at \033[1;35mversion 3\033[0m is storing: \033[1;35m{2, 4, 12, 16, 0}\033[0m");
        System.out.println("Querying \033[1;35mversion 3\033[0m on range \033[1;35m[1..4]\033[0m gives: \033[1;35m"
                + S6.query(3, 1, 4) + "\033[0m");
        // revisit an earlier version after further updates
        System.out.println("\033[1;36mRe-querying past version:\033[0m");
        System.out.println("Even after later updates, querying \033[1;34mversion 1\033[0m on range \033[1;34m[1..4]\033[0m still gives: \033[1;34m"
                + S6.query(1, 1, 4) + "\033[0m");
    }
}
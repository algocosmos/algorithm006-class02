//给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务
//都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
//
// 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
//
// 你需要计算完成所有任务所需要的最短时间。
//
// 示例 1：
//
//
//输入: tasks = ["A","A","A","B","B","B"], n = 2
//输出: 8
//执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
//
//
// 注：
//
//
// 任务的总个数为 [1, 10000]。
// n 的取值范围为 [0, 100]。
//
// Related Topics 贪心算法 队列 数组


import java.util.Arrays;

class Solution621 {
    // 没思路
    // 参考官方题解
    // 链接：https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/
    // 排序法：优先安排个数多的任务
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        Arrays.sort(map);
        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0)
                    break;
                if (i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                time++;
                i++;
            }
            Arrays.sort(map);
        }
        return time;
    }
}

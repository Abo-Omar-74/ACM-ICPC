#include <iostream>
#include <deque>
#include <queue>
/*
Problem link : https://vjudge.net/problem/SPOJ-PQUEUE

    # UVA 12100 - Printer Queue , ACM ICPC NWERC 2006

    Problem Statment :
    The only printer in the computer science students' union is experiencing an extremely heavy workload. Sometimes there are a hundred jobs in the printer queue and you may have to wait for hours to get a single page of output.

Because some jobs are more important than others, the Hacker General has invented and implemented a simple priority system for the print job queue. Now, each job is assigned a priority between 1 and 9 (with 9 being the highest priority, and 1 being the lowest), and the printer operates as follows.

The first job J in queue is taken from the queue.
If there is some job in the queue with a higher priority than job J, then move J to the end of the queue without printing it.
Otherwise, print job J (and do not put it back in the queue).
In this way, all those important muffin recipes that the Hacker General is printing get printed very quickly. Of course, those annoying term papers that others are printing may have to wait for quite some time to get printed, but that's life.

Your problem with the new policy is that it has become quite tricky to determine when your print job will actually be completed. You decide to write a program to figure this out. The program will be given the current queue (as a list of priorities) as well as the position of your job in the queue, and must then calculate how long it will take until your job is printed, assuming that no additional jobs will be added to the queue. To simplify matters, we assume that printing a job always takes exactly one minute, and that adding and removing jobs from the queue is instantaneous.

Input
One line with a positive integer: the number of test cases (at most 100). Then for each test case:

One line with two integers n and m, where n is the number of jobs in the queue (1 ≤ n ≤ 100) and m is the position of your job (0 ≤ m ≤ n-1). The first position in the queue is number 0, the second is number 1, and so on.
One line with n integers in the range 1 to 9, giving the priorities of the jobs in the queue. The first integer gives the priority of the first job, the second integer the priority of the second job, and so on.
Output
For each test case, print one line with a single integer; the number of minutes until your job is completely printed, assuming that no additional print jobs will arrive.

Example
Input:
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

Output:
1
2
5
*/
/*
    solution: read the problem statement carefully and try to solve it before reading this solution

    idea :
    To simulate the problem statement you must have the following information :

    -   The Largest number among all these numbers which will be updated each time you print a number
        So you should have another container that holds these numbers Sorted in my case I have used a priority queue

    -   One important thing to keep in mind is that :
        The position of the number we are concerned about its printing time will be changed many times
        as a result, If we have numbers equal to it we could not differentiate between them

    -   To solve such a problem you must flag the number in the position (m) given in the problem statement
        in my case, I saved the value of the number at position (m) in a variable named target
        and put a -1 in the m position instead to flag the target number

    Finally The approach:

    - entering t
    - for t times entering n, m, and some sort of n numbers
    - while entering the numbers if push them into a queue (to save their original order ) and priority queue (to have information about the order of number to be printed )
    - while (true):
        if we have  reached our target
        then print it (increase the number of printed papers by one ) and break the loop
        (REMARK: I know that I have reached the target if target_now numberToBePrinted == target and -1 is at the d.front which means that it will be the one to be printed )

        else
            do the operation stated in the problem
            if (the first number in the queue is not the largest)
                move numbers to the back of the queue until you find the largest one
            else
            print the largest (printed_papers++), update the largest one value by removing the printed one from the priority queue

         AND WE ARE DONE!
*/

using namespace std;

int main()
{
  int n, t, m, x, target;
  cin >> t;
  while (t--)
  {
    int printed_papers = 0;
    deque<int> d;
    priority_queue<int> pq;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      if (i != m)
        d.push_back(x);
      else
        target = x, d.push_back(-1);
      pq.push(x);
    }
    while (true)
    {
      int numberToBePrinted = pq.top();
      if (numberToBePrinted == target && d.front() == -1)
      {
        printed_papers++;
        break;
      }
      if (d.front() != numberToBePrinted)
        d.push_back(d.front());
      else
        printed_papers++, pq.pop();
      d.pop_front();
    }
    cout << printed_papers << endl;
  }
  return 0;
}

<h2><a href="https://www.geeksforgeeks.org/problems/vertical-sum/1">Vertical sum</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary tree having <strong>n</strong> nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
     <span style="font-size: 18px;">  1
    /    \
  2      3
 /  \    /  \
4   5  6   7
<strong>Output: <br></strong>4 2 12 3 7<strong>
Explanation:</strong></span>
<span style="font-size: 18px;">The tree has 5 vertical lines
Line 1 has only one node 4 =&gt; vertical sum is 4.
Line 2 has only one node 2 =&gt; vertical sum is 2.
Line-3 has three nodes: 1,5,6 =&gt; vertical sum is 1+5+6 = 12.
Line-4 has only one node 3 =&gt; vertical sum is 3.
Line-5 has only one node 7 =&gt; vertical sum is 7.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">          1<br>         /<br>        2<br>       /<br>      3<br>     /<br>    4<br>   /<br>  6<br> /<br>7
<strong>Output: <br></strong>7 6 5 4 3 2 1<strong>
Explanation:</strong></span>
<span style="font-size: 18px;">There are seven vertical lines each having one node.</span></pre>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong><br><span style="font-size: 18px;">You don't need to take input. Just complete the function<strong>&nbsp;verticalSum()&nbsp;</strong>that takes <strong>root </strong>node of the tree<strong>&nbsp;</strong>as parameter and returns an array containing&nbsp;the vertical sum of tree from left to right.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>: O(nlogn).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(n).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;=n&lt;=10<sup>4</sup><br>1&lt;= Node value &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;
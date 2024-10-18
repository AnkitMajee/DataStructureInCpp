<h2><a href="https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1">Combination Sum II</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of integers <strong>arr, </strong>the<strong> </strong>length of the array <strong>n, </strong>and an integer <strong>k</strong>, find all the unique combinations in arr where the sum of the combination is equal to <strong>k</strong>. Each number can only be used once in a combination.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> </span>
<span style="font-size: 18px;">n = 5, k = 7</span>
<span style="font-size: 18px;">arr[] = { 1, 2, 3, 3, 5 }</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">{ { 1, 3, 3 }, { 2, 5 } }</span>
<strong><span style="font-size: 18px;">Explanation:</span></strong>
<span style="font-size: 18px;">1 + 3 + 3 = 7</span>
<span style="font-size: 18px;">2 + 5 = 7</span></pre>
<p><span style="font-size: 18px;">Example 2:</span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">n = 6, k = 35</span>
<span style="font-size: 18px;">arr[] = { 5, 10, 15, 20, 25, 30 }</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">{ { 5,10, 20 }, { 5, 30 }, { 10, 25 }, { 15, 20 } }</span>
<strong><span style="font-size: 18px;">Explanation:</span></strong>
<span style="font-size: 18px;">5 + 10 + 20 = 35</span>
<span style="font-size: 18px;">5 + 30 = 35</span>
<span style="font-size: 18px;">10 + 25 = 35</span>
<span style="font-size: 18px;">15 + 20 = 35</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>CombinationSum2()</strong> which takes arr[],n, and k as input parameters and returns all the unique combinations.</span><br>&nbsp;</p>
<p><strong><span style="font-size: 18px;">Constraints:</span></strong><br><span style="font-size: 18px;">1 &lt;= n &lt;= 100<br>1 &lt;= arr[i] &lt;= 50<br>1 &lt;= k &lt;= 30</span></p>
<p><span style="font-size: 18px;">let<strong>&nbsp;</strong>p = number of elements, at maximum, can sum up to the given value k.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(2<sup>min(n,p)</sup>)<br></span><span style="font-size: 18px;"><strong>Expected Auxiliary Space:</strong> O(n)</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Recursion</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;
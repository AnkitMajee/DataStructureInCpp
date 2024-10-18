<h2><a href="https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1">Union of Two Sorted Arrays</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two sorted arrays of size <strong>n</strong> and <strong>m</strong> respectively, find their union.&nbsp;</span><span style="font-size: 18px;">The Union of two arrays can be defined as the&nbsp;</span><strong style="font-size: 18px;">common&nbsp;</strong><span style="font-size: 18px;">and&nbsp;</span><strong style="font-size: 18px;">distinct&nbsp;</strong><span style="font-size: 18px;">elements in the two arrays.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 5, arr2 [] = {1, 2, 3, 6, 7}
<strong>Output</strong>: <br>1 2 3 4 5 6 7
<strong>Explanation</strong>: <br>Distinct elements including both the arrays are: 1 2 3 4 5 6 7.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
<strong>Output</strong>: <br>1 2 3 4 5
<strong>Explanation</strong>: <br>Distinct elements including both the arrays are: 1 2 3 4 5.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 3:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
<strong>Output</strong>: <br>1 2
<strong>Explanation</strong>: <br>Distinct elements including both the arrays are: 1 2.</span></pre>
<p><strong><span style="font-size: 18px;">Your Task:&nbsp;</span></strong><br><span style="font-size: 18px;">You do not need to read input or print anything. Complete the function <strong>findUnion()&nbsp;</strong>that takes two arrays <strong>arr1[]</strong>, <strong>arr2[],</strong> and their size <strong>n&nbsp;</strong>and <strong>m&nbsp;</strong>as input parameters and returns a list containing the&nbsp;<strong>union of the two arrays</strong>. </span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(n+m).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(n+m).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n, m&nbsp;&lt;= 10<sup>5</sup><br>-10<sup>9</sup> &lt;= arr1[i], arr2[i] &lt;= 10<sup>9</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;
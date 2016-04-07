# BiGraph-Maxium-Match
BiGraph Maxium Match (augmenting path algorithm) By C/C++

采用标准输入/输出
• 输入格式：
– 第一行：整数n，表示顶点个数
– 后续每行：两个整数a,b（0≤a,b≤n-1），表示顶点va与vb相邻
– a=b=-1表示输入结束
– 输入可以保证是二部图
• 输出格式：
– 第一行：整数m，表示匹配M中包含的边数
– 后续m行：M中的每条边ei，按照以下格式：
• 每行为ei的两个端点标号ei.a ei.b(ei.a<ei.b)
• 各行顺序：按ei.a升序

举例：
样例输入：
5\n
0,3\n
0,4\n
1,3\n
2,4\n
-1,-1\n
样例输出：
2\n
0,3\n
2,4\n

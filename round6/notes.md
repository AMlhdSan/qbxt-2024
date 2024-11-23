# $Round$ $6$ $Notes$

## $T1$ $排列小葱$

> ### 题目背景
> 
> 你是能看到第一题的friends呢。
> 
> ——hja
> 
> ### 题目描述
> 
> 在一个繁忙的厨房里，住着各种蔬菜和调味料。其中，小葱一直是厨师们钟爱的配料之一。它总是被切成均匀的小段，与其他食材完美融合。然而，小葱最近遇到了一个困扰——它想找出自己在菜肴中的最佳排列。
> 
> 一天，小葱对它的好朋友胡椒粉说：“胡椒，我想知道如何排列，能让每道菜都变得更加出色。你能帮我吗？”
> 
> 胡椒粉微微飘舞，笑着回答：“当然可以，小葱！但这可能得借助我们在厨房的其他小伙伴。何不召集大家来一起探索呢？”
> 
> 于是，小葱和胡椒粉召集了厨房中的所有食材：番茄、黄瓜、大蒜、姜，还有香菜。他们决定举行一场“排列大会”，尝试各种不同的排列组合，以找出最佳的提升菜品风味的方法。
> 
> 在这次大会上，各种食材按照不同的次序被安排在一起，形成了无数种不同的新口味。有时，小葱被安排在最后，为菜品增色提味；有时，它在中间，成为串联其他食材的桥梁。每一种排列都展示出不同的味道层次，而每一个组合都充满了创造力和惊喜。
> 
> 经过多次尝试，小葱发现，虽然自己的位置和排列重要，但更显著的是和其他食材的配合与和谐。小葱领悟到：“并不是我单独要成为最佳，而是应与其他伙伴们一起混搭出最佳。”
> 
> 胡椒粉点头表示赞同：“是啊，关键在于彼此搭配的化学反应，这让每道菜都升华到新的层次。”
> 
> 从此以后，小葱不再一味追求自身的最佳排列，而是更关注和其他食材的协作。通过相互配合，它们带来的美味让厨师和食客们都赞不绝口。小葱明白了，真正的美味，源自于多种食材的精妙排列与和谐融合。现在总共有$N$个食材，第$i$个食物的美味度为$a_i$，现在小葱可以随意排列这些食材，总共有$N!$种排列方法。如果一个放在前面的食材的美味度比一个放在后面的食材的美味度更大，那么它们就会贡献它们美味度乘积的和谐值。现在问所有$N!$种排列的和谐值的总和是多少。
> 
> ### 输入格式
> 
> 第一行一个正整数$N$。
> 
> 第二行$N$个正整数代表$a_i$。
> 
> ### 输出格式
> 
> 一行一个整数代表答案对$100000007$取模的结果。
> 
> ### 样例 #1
> 
> #### 样例输入 #1
> 
> ```
> 3
> 1 2 3
> ```
> 
> #### 样例输出 #1
> 
> ```
> 33
> ```
> 
> ### 提示
> 
> #### 样例解释
> 
> | 食材排列 | 和谐值 |
> | --- | --- |
> | 1,2,3 | 0   |
> | 1,3,2 | 6   |
> | 2,1,3 | 2   |
> | 2,3,1 | 5   |
> | 3,1,2 | 9   |
> | 3,2,1 | 11  |
> 
> ### 数据范围
> 
> 对于$40\%$的数据，$N\leq 10$。
> 
> 对于$60\%$的数据，$N\leq 1000$。
> 
> 对于$50\%$的数据，所有$a_i$互不相同。
> 
> 对于$100\%$的数据，$1\leq N\leq 10^5,1\leq a_i\leq 10^9$。

1. 暴力写法：STL库 $next\_permutation$ 。
  
2. 优化：三重循环 $\Rightarrow$ 二重循环 $\Rightarrow$ 一重循环
  

## $T2$ $小葱大葱超级作战$

> ### 题目背景
> 
> 你是能看到第二题的friends呢。
> 
> ——aoao
> 
> ### 题目描述
> 
> 在一个熙熙攘攘的菜园里，生活着两位有些小争斗的小伙伴——小葱和大葱。平日里，他们常常吵嚷谁才是“菜园之王”，但一直未能分出胜负。
> 
> 一天，阳光洒在叶片上，微风轻轻荡漾。大葱决定提出一个挑战来一决高下：“小葱，我们今天来比试一场，就一项挑战，让我们看看谁才是菜园真正的王者吧！”
> 
> 小葱爽快地答应了：“好啊！那就比一场拔萝卜比赛，我们来看看力量和灵巧谁能更胜一筹。”
> 
> 两人来到菜园的一角，一颗特大号的萝卜挺立在那儿，紧紧扎根于泥土中。比赛的规则很简单，谁能最快拔出这颗萝卜，谁就获胜。
> 
> 大葱信心满满地走上前去，运用他强壮的力量紧紧握住萝卜，试图将其拔出。尽管萝卜扎根深深，大葱加大力气，但它却紋丝不动。
> 
> 这时，小葱走上前来，观察了一下四周。凭借着聪明机智的小葱想出了一个方法。他开始围着萝卜四周移动，利用他的灵活和技巧，慢慢地松动了萝卜周围的土壤。
> 
> 不久之后，小葱利用突破口轻巧地拔动萝卜，最终牢牢握住萝卜顶端，将其从泥土中拔了出来。大葱服气地点了点头，对小葱说：“你的机智和方法确实令人惊叹。”
> 
> 小葱微微一笑，回应道：“力量是重要的，但某些时候，我们也需要一点策略和灵活。”
> 
> 大葱感觉小葱在嘲讽他，因此向小葱发起了挑战。现在小葱大葱各有$N$个萝卜，每个萝卜都是不一样的。小葱会从他的萝卜中选出$x$个参战（如果只是选择顺序不同但是选出的萝卜是一样的算同一种方案），同时大葱为了欺负小葱，会从大葱的萝卜中选出$x+y$个参战。现在问对于所有可能的$x$，大葱选出一些萝卜参战的方案数之和是多少。
> 
> ### 输入格式
> 
> 一行三个整数$N,y,p$。
> 
> ### 输出格式
> 
> 一行一个整数代表答案对$p$取模的结果。
> 
> ### 样例 #1
> 
> #### 样例输入 #1
> 
> ```
> 3 1 233
> ```
> 
> #### 样例输出 #1
> 
> ```
> 15
> ```
> 
> ### 提示
> 
> #### 样例解释
> 
> | 方案编号 | 小葱选的萝卜 | 大葱选的萝卜 |
> | --- | --- | --- |
> | 1~3 |     | (1),(2),(3) |
> | 4~6 | 1   | (1,2),(1,3),(2,3) |
> | 7~9 | 2   | (1,2),(1,3),(2,3) |
> | 10~12 | 3   | (1,2),(1,3),(2,3) |
> | 13  | 1,2 | (1,2,3) |
> | 14  | 1,3 | (1,2,3) |
> | 15  | 2,3 | (1,2,3) |
> 
> ### 数据范围
> 
> 对于$40\%$的数据，$1\leq N\leq 1000$。
> 
> 对于$60\%$的数据，$1\leq N\leq 10^6$。
> 
> 对于$75\%$的数据，$p$为质数。
> 
> 对于$50\%$的数据，$y=0$。
> 
> 对于$100\%$的数据，$1\leq N\leq 10^9,1\leq p\leq 10^6,-N\leq y\leq N$。

1. 看数据范围，肯定不是枚举
  
2. 化简：
  

$$
\displaystyle \sum\limits_x {n \choose x} {n \choose x+y}
$$$$
\Rightarrow \displaystyle \sum\limits_x {n \choose x} {n \choose n-x-y}
$$

3. 组合意义！
  

$$
\Rightarrow {n \choose x}：在前n个数中取x个
$$$$
\Rightarrow {n \choose n-x-y}：在后n个数中取n-x-y个
$$$$
\Rightarrow \sum\limits_x {n \choose x} {n \choose n-x-y}：在2n个数中取n-y个
$$$$
\Rightarrow \sum\limits_x {n \choose x} {n \choose n-x-y}={2n \choose x}
$$

4. 故本题即求
  

$$
\displaystyle {2n \choose x} \% p
$$

5. 卢卡斯定理：
  
  $$
  {n \choose m}\%p={n\%p \choose m\%p}{n/p \choose m/p}
  $$
6. 拓展卢卡斯定理：
  

$$
k={p_1}^{r_1}{p_2}^{r_2}{p_3}^{r_3}...{p_t}^{r_t}
$$$$
\Rightarrow {n \choose m} \% p^r
$$$$
\Rightarrow {n \choose m}=\cfrac{n!}{m!(n-m)!}
$$$$
\Rightarrow n!=p^ab,m!=p^cd,(n-m)!=p^ef
$$$$
以n!=p^ab为例，a=\lfloor \frac {n}{p} \rfloor +\lfloor \frac {n}{p^2} \rfloor +...
$$

7. 范德蒙德卷积
  
  $$
  \sum\limits_{i=0}^{k}{n \choose i}{m \choose k-i}={n+m \choose k}
  $$
  
  ~~怎么感觉在上数论课......~~
  

## $T3$ $小平方葱$

> ### 题目背景
> 
> 你是能看到第三题的friends呢。
> 
> ——laekov
> 
> ### 题目描述
> 
> 在一个奇妙的数学王国里，住着一个活泼而机智的小家伙——小葱。小葱不仅是厨房中不可或缺的角色，也是数学王国的好奇心探险者。最近，小葱对数学中的“平方”产生了浓厚的兴趣，总想探个究竟。
> 
> 某天，小葱决定踏上探索平方的旅程。他找到王国的智者——老数学家“平方”，询问关于平方的奥秘。
> 
> “小葱，”平方微笑着说，“平方是指将一个数与它自身相乘，结果有着令人惊叹的特性。”
> 
> 为了让小葱更理解，平方给出了一些例子：“举个例子，数字3的平方是9，因为 $3 \times 3 = 9$。而这些平方数常常会在图形、面积计算以及许多数学问题中出现。”
> 
> 小葱听得入迷，眼睛闪烁着兴奋的光芒。他意识到，平方不仅仅是一个运算符号，更是改变数字世界视角的方法。
> 
> 在探索途中，小葱遇到了各种有“平方”特性的奇妙景象。比如，他走进一个神奇的花园，发现所有花瓣的数量都是某个数的平方。动植物也优雅地排列成平方形状，让整个景观显得格外和谐美丽。
> 
> 小葱还结识了其他数字精灵，比如立方精灵、平方根精灵，他们各自都是数学王国中不可或缺的一部分。他们告诉小葱，他们一起构建了一个和谐的数学世界。
> 
> 通过这一系列探索，小葱不仅知道平方计算的重要性，还意识到数学的奇妙与无限可能。小葱高兴地向平方道谢，并返回厨房，准备与小伙伴们分享这段奇妙旅程中的收获。
> 
> 此后，小葱在厨房中施展其学到的“平方”技艺，为各种菜肴增添了一丝数学的魔力。而数学王国也因小葱的技艺，给小葱出了一道难题。现在数学王国有$N$个数$a_1,a_2,\cdots,a_N$，同时数学王国给了$M$次操作。如果是操作类型2，则是给定$l,r$，询问$\sum_{i=l}^ra_i$的值。但如果是操作类型$1$，则是给定$l,r$，数学王国需要小葱把这段区间里面的每个数变为这个数各位数字的$k$次方之和。例如如果$k=2$，那么$23$会变成$2^2+3^2=13$。现在小葱人麻了，你需要帮他实现这些操作。
> 
> ### 输入格式
> 
> 第一行三个整数$N,M,k$。
> 
> 第二行$N$个整数代表$a_1,a_2,\cdots,a_N$。
> 
> 接下来$M$行每行三个整数代表$opt,l,r$，其中$opt$是操作的类型。
> 
> ### 输出格式
> 
> 对于每次询问，输出一行一个答案对$10^9+7$取模的结果。
> 
> ### 样例 #1
> 
> #### 样例输入 #1
> 
> ```
> 5 5 2
> 1 2 3 4 5
> 2 1 5
> 1 1 5
> 2 1 5
> 1 1 5
> 2 1 5
> ```
> 
> #### 样例输出 #1
> 
> ```
> 15
> 55
> 164
> ```
> 
> ### 提示
> 
> 对于$40\%$的数据，$N,M\leq 10^3$。
> 
> 对于另外$20\%$的数据，$l=1,r=N$。
> 
> 对于$10\%$的数据，$k=1$。
> 
> 对于$20\%$的数据，$k=2$。
> 
> 对于$30\%$的数据，$k=3$。
> 
> 对于$40\%$的数据，$k=4$。
> 
> 对于$100\%$的数据，$1\leq N,M\leq 10^5,1\leq k\leq 4,1\leq l\leq r\leq N,1\leq a_i\leq 10^9$。

## $T4$ $The$ $end$ $of$ $小葱$ $2024$

> ## 题目背景
> 
> 你是能看到第四题的friends呢。
> 
> ——rivenhe
> 
> ## 题目描述
> 
> 在这个充满变化与惊喜的时间王国里，小葱是一位观察者，他对时间流逝充满了好奇。在2024年即将结束之际，小葱决定仔细记录这一年的点滴，希望能找到时间流转的深刻意义。
> 
> ### 年末的回顾
> 
> 为了回顾2024年的精彩瞬间，小葱启动了他的小型时间旅程机，这机器可以重现过去的亮点。他细细浏览这一年的重要时刻：有高科技的飞速发展，有人类在环境保护上的新突破，还有各国在文化与体育上的交流盛况。
> 
> 小葱见证了全球团结应对挑战的努力，感受到无数人在追求梦想路上留下的奋斗足迹。他心想：“即使时间飞逝，人们的努力与成长给这个世界带来了很多值得铭记的变化。”
> 
> ### 节日的庆祝
> 
> 在2024年的最后一周，小葱被邀请参与一个盛大的节日庆典。城市的街道上灯火辉煌，人们在欢庆中分享着温暖的故事，期许更美好的明年。小葱和大家一起参与倒数计时，共同欢呼：“2025，我们来了！”
> 
> 庆典上，小葱注意到人们在新年愿望卡上写下的心愿：有人期待健康，有人期盼爱情，还有人希望获得勇气去迎接新的挑战。小葱也悄悄写下自己的愿望，希望永远保持好奇心，持续探索未知。
> 
> ### 时光的启示
> 
> 在午夜钟声的伴随下，小葱静静地看着这些众生群像，心中产生了一些领悟。他明白，虽然年华似水而逝，但每个结束都是新的开始，正如2024年与2025年的交接。
> 
> “每一年都有其独特的故事和意义，”小葱对自己说，“关键在于如何享受过程，学习如何从每个瞬间中拾起智慧。”
> 
> 于是，伴随着新年的钟声，小葱意识到：无论时间如何流转，重要的是在每个季节中积极生活、探索和成长。这场跨年的体验让他更加理解了时光的无价和生命的意义。
> 
> 小葱怀揣着这份新领悟，开始出了一套新的题目。小葱题库里面有总共$N$道题，小葱想拿这$N$道题组$M$套题出来。对于第$i$套题，小葱会给定一个出题密码$p_i$，$p_i$是一个$k_i$进制的数字串，数字串可能包含`?`，代表可以匹配任意数字的一个符号。如果第$j$道题的特征值在$k_i$进制下能够匹配$p_i$，那么第$j$道题就会被编入第$i$套题，同时第$i$套题的题目难度是由这套题所有的题目的难度乘积再加上$z_i$所得到的值的最小质因子大小。很快，小葱就发现，如果想要计算一套题的难度实在过于困难，因此小葱为第$i$套题指定了一个难度上限$x_i$，小葱希望这套题的难度和$x_i$的最小值是多少。
> 
> ## 输入格式
> 
> 第一行两个整数$N,M$。
> 
> 第二行$N$个数代表每道题特征值$a_i$，用十进制表示。
> 
> 第三行$N$个数代表每道题的难度$d_i$。
> 
> 接下来$M$行，每行包含$k_i,p_i,x_i,z_i$，代表一套题目的四个参数。
> 
> ## 输出格式
> 
> 对于每套题目，一行一个正整数代表答案。
> 
> ## 样例 #1
> 
> ### 样例输入 #1
> 
> ```
> 4 8
> 1 2 3 4
> 2 23 233 2333
> 2 ? 100 3
> 3 ? 100 3
> 4 ? 100 3
> 5 ? 100 3
> 2 ?? 100 3
> 3 ?? 100 3
> 2 1? 100 2
> 2 ?0 100 2
> ```
> 
> ### 样例输出 #1
> 
> ```
> 5
> 7
> 71
> 13
> 71
> 13
> 3
> 5
> ```
> 
> ## 提示
> 
> ### 样例解释
> 
> | 套题编号 | 所选题目特征值 | 最终难度 |
> | --- | --- | --- |
> | 1   | 1   | 5   |
> | 2   | 1,2 | 49  |
> | 3   | 1,2,3 | 10721 |
> | 4   | 1,2,3,4 | 25005097 |
> | 5   | 1,2,3 | 10721 |
> | 6   | 1,2,3,4 | 25005097 |
> | 7   | 2,3 | 5361 |
> | 8   | 2   | 25  |
> 
> ### 数据范围
> 
> 对于$40\%$的数据，$N,M\leq 50$。
> 
> 对于$60\%$的数据，$N,M\leq 1000$。
> 
> 对于另外$10\%$的数据，$s_i$没有问号。
> 
> 对于另外$10\%$的数据，$x_i=3$。
> 
> 对于$100\%$的数据，$1\leq N,M\leq 2\times 10^4,1\leq a_i\leq N,1\leq d_i\leq 10^{18},2\leq k_i\leq 36,1\leq |p_i|\leq 64,1\leq x_i\leq 100,1\leq z_i\leq 10^{18}$，保证所有$a_i$互不相同，超过十进制用大写字母A~Z表示。
# MarkDown常用操作汇总:
- - -
## 一 认识Markdown    
Markdown是一种 **_标记语言_**，通常为程序员群体所用，也是国际杂志编辑和写作者广泛使用的标记语言。  
应运而生：使用word或pages写作，可能会因为操作系统不同而出现格式问题。使用txt写作，又苦于没有排版。  
Markdown语法十分简单，常用的标记符号不超过十个，不到半小时就能完全掌握，却能让人专注内容而不是纠结排版。

## 优点：  
（1）纯文本，兼容性极强  
（2）专注文字而不是排版  
（3）格式转换方便，可以轻松转换为html、电子书等  
（4）标记语法具有极好的可读性。

## 二 基本用法  
1、单个回车，视为空格  
2、连续回车，才能分段  
3、行尾加两个空格，就可以段内换行  
4、注释可使用HTML的注释  
5、也可以使用HTML标签 

## 三 语法规则  
### 1 标题  
第一种是使用 # 表示标题，其中 # 号必须在行首，
第二种是使用 === 或者 --- 表示。
```
#　H1标题
##　H2标题
###　H3标题
####　H4标题
#####　H5标题
######　H6标题
```
![](https://img-blog.csdn.net/20180617104727399?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FmZWlfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70) 
### 2 列表
  #### (1)无序列表（*,+,-）
```
* 列表1
* 列表2
+ 列表3
+ 列表4
- 列表5
- 列表6
```
    嵌套:
```
 * 列表1
    * 子列表1
    * 子列表2
* 列表2
 ```   
 #### (2)有序列表（数字+点号）
 ```
1. 文本
2. 音乐
    1. 童话
    2. 列了都要爱
    3. 天下
3. 电影
 ```
 ### 3 文字格式
 使用 * 和 ** 分别表示斜体和粗体，删除线使用两个 ~ 表示
 #### （1)粗体
 ```
 ** 粗体 **
__ 粗体 __
```
#### （2)斜体
```
* 斜体 *
_ 斜体 _
```
#### （3)粗体+斜体
```
*** 粗斜体 ***
___ 粗斜体 ___  
```
####  （4)删除（MarkDown Pad2 暂不支持）
```
~~ 斜体 ~~
```

![](https://img-blog.csdn.net/20180617104742331?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FmZWlfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70) 

### 4 链接
链接和图片的写法类似，图片仅在超链接前多了一个 ! ，一般是 [文字描述] (链接)
#### （1)直接设置（行内形式） 
``` 
语法：[链接名称](链接地址 “链接title”)
[百度](http://www.baidu.com "百度一下，你就知道")
```
#### （2)间接设置（参考形式） 
``` 
语法：[链接名称][标记]
　　　　　[标记]: 链接地址 “链接title”
[百度][1]
[1]: http://www.baidu.com "百度一下，你就知道"
```
#### （3)隐式设置（行内形式） 
``` 
语法：[链接名称][]
　　　　　[链接名称]: 链接地址 “链接title”
[百度][]
[百度]: http://www.baidu.com "百度一下，你就知道"
```

### 5 图片
链接和图片的写法类似，图片仅在超链接前多了一个 ! ，一般是 [文字描述] (链接)
#### (1)直接设置（行内形式)
```
语法：![替代文本](链接地址 “链接title”)
![百度](https://www.baidu.com/img/bd_logo1.png "百度一下，你就知道")
```

#### (2)间接设置（参考形式)
```
语法：[替代文本][标记]
　　　　　[标记]: 链接地址 “链接title”
![百度][1]
[1]: https://www.baidu.com/img/bd_logo1.png "百度一下，你就知道"
```

### 6 引用
```
> 一级引用
>> 二级引用
>>> 三级引用
```
会显示以下效果：

![](https://img-blog.csdn.net/20180409210901089?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)  
1）引用换行：
　　末尾加两个空格。

　　2）引用内包含其他语法：
　　如：标题、列表、代码块
　　注：一定要写在引开头处
### 7 水平分割线
使用三个或以上的 - 或者 * 表示，且这一行只有符号，注意不要被识别为二级标题即可，例如中间或者前面可以加空格。
```
---
___
***
```
### 8 代码块
#### (1)代码
用反引号（`），左上角ESC按键下面。
```
`我是代码句`
```
#### (2)代码段
4个空格（或Tab缩进）定义代码块。
    
    我是代码段1
    我是代码段2
    我是代码段3
    
#### (3)用三个以上的反引号定义段开始和结束



    ``` java
    public class Test {
        public static void main(String[] args) {
            System.out.println("Hello World");
        }
    }
    ```

会显示以下效果：  
![](https://img-blog.csdn.net/20180409220239031?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

### 9 表格
  **关于冒号**（:）  
左边：以下内容左对齐  
右边：以下内容右对齐  
两边：以下内容居中对齐

```
| 项目      |    价格 | 数量  |
| :-------- | --------:| :--: |
| Computer  | 1600 元 |  5   |
| Phone     |   12 元 |  12  |
| Pipe      |    1 元 | 234  |
```
会显示以下效果：  
![](https://img-blog.csdn.net/20180409211150024?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

### 10 文档目录
只需在你想要放入目录结构的位置写入 [TOC] 即可。
会显示以下效果：  
![](https://img-blog.csdn.net/20180409220313275?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

### 11 转义字符
有的时间在使用 MarkDown 进行排版时，可以很方便的快速进行排版，但是有时还需要使用一些 MarkDown 语法中特殊的符号（比如：*，-，+这些），该怎么办呢？我们可以借助转义字符达到我们想要的效果。

```
\\　反斜杠
\`　反引号
\*　星号
\_　下划线
\+　加号
\-　减号
\#　井号
\.　句号
\~　感叹号

```
### 12 UML图
#### （1)渲染序列图：

    ```sequence
    小异常->大异常: 嘿，老大, 看完博客评论了没?
    Note right of 大异常: 大异常愣了一下，说：
    大异常-->小异常: 呀，差点忘了，马上评论
    ```

会显示以下效果：  
![](https://img-blog.csdn.net/20180409221335012?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 

#### （2)渲染流程图：
    ```flow
    st=>start: 开始
    e=>end: 结束
    com=>operation: 开始评论
    cond=>condition: 确认评论？

    st->com->cond
    cond(yes)->e
    cond(no)->com
    ```
会显示以下效果：  
![](https://img-blog.csdn.net/20180409221935594?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3VuODExMjEzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast) 


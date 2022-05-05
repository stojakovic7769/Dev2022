# Git常用操作汇总:
- - -
## *基本的操作,能保证数据的推送*
**1 暂存更改:**
```
    git add --all"
```
**2 提交本地**
```
    git commit -m "修改摘要信息:"
```
**3 推送到远程库:**
```
    git push
```
**4 将远程资源库Repository的内容拉取到本地资源库:**
```
    git pull
```
Note:在其他电脑上进行clone操作时,也需要先配置密钥.  
1  ```ssh-keygen -t rsa -C "stojakovic7769@126.com"```  
2  登录GitHub,setting ,找到SSH相关,将密钥复制进去.  
3  再执行clone操作,即可将文件克隆到本地.

## 20220426

创建分支:    ```git checkout -b BRANCHNAME```  
转到分支:    ```git checkout BRANCHNAME```  
推送到分支 :```git push origin BRANCHNAME```  
查看远程分支: ```git branch -r```  
查看所有分支: ```git branch -a```  

## 20220427
将远程指定分支拉取到本地指定分支上:  
```git pull origin <远程分支名>:<本地分支名>或者 git pull origin <远程分支名>```  
将本地当前分支 推送到 远程指定分支上:  
```git push origin <本地分支名>:<远程分支名>```  
将本地当前分支 推送到 与本地当前分支同名的远程分支上:   
```git push origin <本地分支名>```   
将本地分支与远程同名分支相关联:   
```git push --set-upstream origin <本地分支名>```  
  - - -
删除本地分支:  
  ```git branch -D <本地分支名>```   
```git branch -d ``` 会在删除前检查merge状态（其与上游分支或者与head）  
```git branch -D ``` 是git branch --delete --force的简写，它会直接删除。 
  - - - 
git删除远程分支:```git push origin --delete [branch_name]```  
- - -


# MarkDown常用操作汇总:
- - -
## 认识Markdown  
Markdown是一种 [标记语言]，通常为程序员群体所用，也是国际杂志编辑和写作者广泛使用的标记语言。  
应运而生：使用word或pages写作，可能会因为操作系统不同而出现格式问题。使用txt写作，又苦于没有排版。  
Markdown语法十分简单，常用的标记符号不超过十个，不到半小时就能完全掌握，却能让人专注内容而不是纠结排版。

## 优点：  
（1）纯文本，兼容性极强  
（2）专注文字而不是排版  
（3）格式转换方便，可以轻松转换为html、电子书等  
（4）标记语法具有极好的可读性。



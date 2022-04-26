20220425

git add -all
git push https://github.com/stojakovic7769/Dev2022/

Note:在其他电脑上进行clone操作时,也需要先配置密钥.
1  ssh-keygen -t rsa -C "stojakovic7769@126.com"
2  登录GitHub,setting ,找到SSH相关,将密钥复制进去.
3  再执行clone操作,即可将文件克隆到本地.

Note:
创建分支.   git checkout -b BRANCHNAME
转到分支    git checkout BRANCHNAME
推送到分支 git push origin BRANCHNAME
查看远程分支 git branch -r
查看所有分支 git branch -a
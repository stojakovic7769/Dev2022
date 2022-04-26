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

将远程指定分支 拉取到 本地指定分支上  git pull origin <远程分支名>:<本地分支名>或者 git pull origin <远程分支名>

将本地当前分支 推送到 远程指定分支上  git push origin <本地分支名>:<远程分支名>

将本地当前分支 推送到 与本地当前分支同名的远程分支上 git push origin <本地分支名>

将本地分支与远程同名分支相关联 git push --set-upstream origin <本地分支名>

# https://www.runoob.com/linux/linux-comm-xargs.html


# 利用xargs复制文件

ls | head -n 5 | xargs -I {} cp {} /home/darwinkong/code/cpp/redis
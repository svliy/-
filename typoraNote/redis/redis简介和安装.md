### 启动

必须启动redis.conf和redis-server，然后启动redis-cli

```shell
redis-server：Redis服务器启动命令
redis-cli：客户端，操作入口

# ./bin/redis-server ./redis/redis.conf
```

### 基本操作

类型是value值的类型

```c++
清库 flushdb
```


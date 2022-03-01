### 配置格式

在Spring Boot中多环境配置文件名需要满足application-{profile}.properties的格式

其中{profile}对应你的环境标识，比如：

|   环境   |          具体格式           |
| :------: | :-------------------------: |
| 测试环境 | application-test.properties |
| 生产环境 | application-prod.properties |
| 开发环境 | application-dev.properties  |

在application.properties文件中通过spring.profiles.active属性来设置加载环境

例：

```java
spring.profiles.active=dev
```

此时加载开发环境。

为了区别不同的环境，在不同的环境配置文件中通过`server.port`设置不同的端口号。

|   环境   | 端口号 |
| :------: | :----: |
| 测试环境 |  8002  |
| 生产环境 |  8003  |
| 开发环境 |  8001  |


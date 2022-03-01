# Swagger

### 学习目标

- 了解Swagger的作用和概念
- 了解前后端分离
- 在SpringBoot中集成Swagger

### Swagger简介

##### 前后端分离

Vue+SpringBoot

后端时代：前端只用管理静态页面；使用html，js，css，jQu将数据交给后端。后端使用模板引擎JSP，后端是主力。

前后端分离时代：

- 后端：后端控制层，服务层，数据访问层。【后端团队】
- 前端：前端控制层，视图层。【前端团队】
  - 伪造后端数据json。数据已经存在，不需要后端，前端工程依旧可以跑起来。
- 前后端如何交互？答：API
- 前后端相对独立，松耦合；
- 前后端甚至可以部署在不同的服务器上；



产生一个问题：

- 前后端集成联调，前端人员和后端人员无法做到“及时协商，尽早解决”，最终导致问题集中爆发；

解决方案：

- 首先指定一个schema[计划的提纲],实时更新最新API，降低集成的风险；
- 早些年：制定word计划文档；
- 前后端分离：
  - 前端测试后端接口:postman（测试请求）
  - 后端提供接口，需要实时更新最新的消息及改动！

### Swagger

- 号称世界上最流行的API框架
- RestFul Api 文档在线自动生成工具===》**API文档与API定义同步更新**
- 直接运行，可以在线测试API接口
- 支持多种语言：（Java，Php...）



官网：



在项目中使用Swagger需要springbox；

- swagger2
- ui

### SpringBoot集成Swagger

1. 新建一个SpringBoot Web项目

   maven？搜索springfox-swag

2. 导入Maven相关依赖（导入jar包）

```xml
<dependency>
            <groupId>io.springfox</groupId>
            <artifactId>springfox-swagger2</artifactId>
            <version>2.7.0</version>
            <scope>provided</scope>
        </dependency>

        <dependency>
            <groupId>io.springfox</groupId>
            <artifactId>springfox-swagger-ui</artifactId>
            <version>2.7.0</version>
            <scope>provided</scope>
        </dependency>
```
3. 编写一个Hello工程

   

4. 配置Swagger==》Config

   ```java
   @Configuration   //加上会配置到配置里面
   @EnableSwagger2  //开启Swagger2
   public class SwaggerConfig {
   
       @Bean
       public Docket webApiConfig() {
   
           return new Docket(DocumentationType.SWAGGER_2)
                   .groupName("webApi")
                   .apiInfo(webApiInfo())
                   .select()
                   .paths(Predicates.not(PathSelectors.regex("/error.*")))
                   .build();
   
       }
   
       private ApiInfo webApiInfo() {
   
           return new ApiInfoBuilder()
                   .title("seekerSkill测试中心")
                   .description("本文档描述了seekerSkill项目接口定义")
                   .version("1.0")
                   .contact(new Contact("seekerSkill", "", ""))
                   .build();
       }
   }
   ```

5. 测试运行

   访问网页http://localhost:8080/swagger-ui.html

   ![image-20210802212554693](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210802212554693.png)

### 配置Swagger

### Swagger配置扫描接口

Docket的select（）

```java
//配置了Swagger的Docket的bean实例
    @Bean
    public Docket docket(){
        return new Docket(DocumentationType.SWAGGER_2)
                .apiInfo(apiInfo())
                .select()
                //配置要扫描接口的方式：RequestHandlerSelectors
                //指定要扫描的包：basePackage("com.example.layui.controller")
                //扫描全部：any()
                //none():都不扫描
                //withClassAnnotation:扫描类上的注解，参数是一个注解的反射对象
                //withMethodAnnotation:扫描方法上的注解，参数是一个
                .apis(RequestHandlerSelectors.basePackage("com.example.layui.controller"))
                //paths():过滤什么路径
                .paths(PathSelectors.ant("/hello/**"))
                .build();
    }
```

配置是否启动Swagger

我只希望我的Swagger在生产环境中使用，在发布的时候不使用？

1. 判断是不是生产环境 flag = false
2. 注入enble（flag）

配置API文档的分组

```

```

如何配置多个分组，使用多个Docket实例即可

```java

```



   实体类配置

协同开发，写API接口文档

先看spring视频打好基础



![image-20210803144151120](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210803144151120.png)

![image-20210803145452233](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210803145452233.png)

任务





https://blog.csdn.net/jxysgzs/article/details/110818712

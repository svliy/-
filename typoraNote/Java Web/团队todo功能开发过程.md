### 数据库

1. team![image-20210815164538792](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210815164538792.png)

2. team_todo

![image-20210815164547408](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210815164547408.png)

3. team_user

![image-20210815164556164](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20210815164556164.png)

sfa copy /b G:\fix\v1.mp4 + G:\fix\v2.mp4 + G:\fix\v4.mp4

错误：

1.实体类和数据库对应错误。

2.怎么防止别人修改团队的名称和简介

3.怎么及时更新数据

4.退出团队api的路径参数id用团队id还是表team-user的id

5.todo的id用户能获取吗?

什么是相应参数

team-user中创建者在创建时就进入

能不能从数据库角度修改相应的参数



**Q：**怎么将团队待办加入到团队中每个人的待办列表中？

**答：** 默认不考虑待办截止时间问题。在团队创建者创建团队待办时，将该待办加入到当前团队中每个人的待办列表，同时标注为团队待办。在有新的队员加入团队时，将团队待办加入到自己的待办列表中。

权限管理

进度：

1.创建一个团队，并绑定是自己创建的

2.



**Q：**

1.检测问题

2.组员完成度：未实现

3.数据库中个别字段的长度不对

4.接收返回值


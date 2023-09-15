# wyy
使用Qt模仿的网易云音乐

**环境**：Clion（MinGw） + QtCreator

# 效果图

由于图片较多，若未显示，需要挂梯子

## 个性推荐页面

(官方)

![image-20230909210245551](image/README/image-20230909210245551.png)

![image-20230909211024461](image/README/image-20230909211024461.png)

![image-20230909211037528](image/README/image-20230909211037528.png)

（模仿）

* 使用QGraphView + 定时器实现轮播图自动翻页
* QStackWidget + QTabWidget 实现多页面
* QGridLayout实现画廊图片显示
* 利用QSS重绘QScrollArea的滚动条

![image-20230909210410026](image/README/image-20230909210410026.png)

![image-20230909210650310](image/README/image-20230909210650310.png)

![image-20230909210719888](image/README/image-20230909210719888.png)

## 搜索栏Popup弹窗

（官方）

![image-20230909210949714](image/README/image-20230909210949714.png)

（模仿）

* 使用事件过滤器（eventFilter）控制是否显示popup

![image-20230909210931385](image/README/image-20230909210931385.png)

## 个人信息弹窗

（官方）

![image-20230909211127089](image/README/image-20230909211127089.png)

（模仿）

![image-20230909211145516](image/README/image-20230909211145516.png)

## 消息窗口

（官方）

![image-20230909211220679](image/README/image-20230909211220679.png)

（模仿）

![image-20230909211248682](image/README/image-20230909211248682.png)

## 设置页面

（官方）

![image-20230909211425201](image/README/image-20230909211425201.png)

（模仿）

* 使用QSS重绘复选框、单选框、下拉列表框等控件

![image-20230909211443414](image/README/image-20230909211443414.png)

![image-20230909212819931](image/README/image-20230909212819931.png)

![image-20230909211533005](image/README/image-20230909211533005.png)

## 排行榜页面

（官方）

![image-20230909211657599](image/README/image-20230909211657599.png)

![image-20230909211712148](image/README/image-20230909211712148.png)

（模仿）

![image-20230909211728188](image/README/image-20230909211728188.png)

![image-20230909211752316](image/README/image-20230909211752316.png)

## 最新音乐

（官方）

![image-20230909211906070](image/README/image-20230909211906070.png)

（模仿）

![image-20230909211925299](image/README/image-20230909211925299.png)

## 歌曲播放

（官方）

![image-20230909212035258](image/README/image-20230909212035258.png)

（模仿）

* 使用QMediaPlayer实现歌曲播放
* 使用QSS重绘QProgressBar

![image-20230909212111900](image/README/image-20230909212111900.png)

## 音乐列表

（官方）

![image-20230915200435913](.\image\README\image-20230915200435913.png)

（模仿）

* 使用`QTableView`实现音乐列表
* 使用自定义`delegate`实现自定义表格内按钮
* 使用`QSortFilterProxyModel`以及正则表达式实现表格内搜索、排序功能

![image-20230915200605569](.\image\README\image-20230915200605569.png)

![image-20230915201016551](.\image\README\image-20230915201016551.png)

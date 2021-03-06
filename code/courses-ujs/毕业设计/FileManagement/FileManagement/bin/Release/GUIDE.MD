局域网内电子文档管理平台 操作指南

1.软件简介
应用名称：局域网内电子文档管理平台
文件名：FileManagement.exe
应用版本：1.0.0
作者：沈鑫楠
修改日期：2019年5月14日
软件开发平台：Microsoft Visual Studio 2013 Ultimate、Microsoft SQL Server 2014 
该软件运行于 Windows 平台。

2.运行环境
（1）硬件要求 
①1GHz 或更高的微处理器 
②使用 1G 或以上内存 
③不少于 100MB 的可用硬盘空间 
（2）软件要求 
①Windows 7或以上的操作系统 
②.NET Framework 4.7.2 或以上 

3.使用说明
3.1 安装和初始化
（1）安装必备软件
在客户机上安装好 Windows 7 操作系统，配置好 TCP/IP 协议，确保计算机可以连接互联网。 
配置完成之后，安装好.NET Framework 4.7 运行库。 
（2）安装局域网内电子文档管理平台
<1>桌面上双击安装文件 setup.exe；
<2>选择安装路径，并点击下一步按钮；
<3>选择是否创建桌面快捷方式，并点击下一步按钮；
<4>点击确认安装按钮，进行安装；
<5>安装完成后，点击结束，退出安装程序。

3.2 启动系统
1.双击桌面快捷方式“局域网内电子文档管理平台（客户端）”，启动管理平台系统
2.根据管理员分配的用户名和密码开始使用管理平台
3.系统主要功能
（1）初始化系统和用户登录：系统初始化后，用户需要进行登录操作，通过验证后才能进入平台进行操作；
（2）显示文档与版本信息：用户成功登陆平台后，就可以从平台的界面中看到平台中已经存在的电子文档。用户可以选择不同方式查看电子文档，包括：大图标、小图标以及详细信息。当用户点击某一个文档时，平台会自动加载出该文档的各个版本，并显示在界面上供用户查看。同样地，用户可以选择以三种方式查看文档的版本信息，包括：大图标、小图标以及详细信息；
（3）上传文档：用户通过选择需要上传文档所属的主题以及需要上传的文档在本机的路径可以将文档从自己的计算机中上传到平台；
（4）浏览文档：用户通过选择需要下载的文档以及下载的文档保存在本地的路径可以将文档从平台中下载到自己的计算机中浏览。本平台应具有下载完成后自动打开文档供用户浏览的功能；
（5）修改文档：用户通过选择需要修改的文档以及需要修改的文档保存在本地的路径可以对平台中的文档进行修改操作。本平台应具有下载完成后自动打开文档供用户修改的功能；
（6）删除文档：用户通过选择需要删除的文档可以对平台中的文档进行删除操作；
（7）浏览文档的某个版本：用户通过选择需要浏览的文档的版本并指定需要浏览的文档版本保存在本地的路径，从而可以浏览文档的指定版本，包括最新版本与历史版本。本平台应具有下载完成后自动打开文档版本供用户进行浏览的功能；
（8）删除文档的某个版本：用户通过选择需要删除的文档的版本可以删除文档的指定版本。
4.使用注意事项
（1）登陆时用户名密码如果连续三次输入错误，账户会被锁定
（2）第一次登陆需要设定密保邮箱或手机号
（3）个人账户中的数据以及上传的文档加密存储，请放心使用
（4）请勿使用SQL注入等非法操作破坏数据库
（5）请勿使用爬虫等程序自动化获取数据，按钮点击频率有严格的限制
（6）请勿尝试越权访问数据，数据库进行了访问控制限制。


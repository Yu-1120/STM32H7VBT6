# STM32H7VBT6
反客-STM32H7VBT6-自己的一些代码

STM32下载烧录事项说明：https://www.weact-tc.cn/2019/11/30/STM32Download/
Gitee码云资料例程固件链接：https://gitee.com/WeAct-TC/MiniSTM32H7xx.git
Github资料例程固件链接：     https://github.com/WeActTC/MiniSTM32H7xx.git
常用电脑软件链接： https://pan.baidu.com/s/1wPy3f_cRzPJc_YnOVKTprA 
提取码： rji7

---

# STM32 下载烧录教程以及问题汇总

![img](https://www.weact-tc.cn/images/STM32/STM32F4x1/stm32f411.jpg)



# ISP模式下载

通过ISP模式下载程序，我们支持两种烧录方法：一种是[串口下载](https://www.weact-tc.cn/2019/11/30/STM32Download/#串口下载)，需要USB转串口；另一种是[USB下载](https://www.weact-tc.cn/2019/11/30/STM32Download/#USB下载（DFU下载）)（推荐），只需要一根数据线。

> 进入ISP模式的方法
>
> - 方法1：上电状态下，按住BOOT0键和复位键，然后松开复位键，0.5秒后松开BOOT0键
> - 方法2：掉电状态下，按住BOOT0键，上电后0.5S松开BOOT0键

> 连接方法
>
> - USB下载：USB数据线连接板子的TYPE-C接口
> - 串口下载：USB转串口连接PA9、PA10

> 下载软件推荐STM32CubeProgammer，`WeAct Studio Download Tool`

## 串口下载

USB转串口 (ex.：CH340) `TX` - `PA10` ,`RX` - `PA9`，同时不要将MCU的`Type-C`连接到电脑，必须使用外部供电，不然会影响MCU下载。串口下载有两个烧录工具，一个是ST官方的STM32CubeProgammer，另一个是我们推出的免安装烧录工具 `WeAct Studio Download Tool`（推荐）

### 使用STM32CubeProgammer进行串口下载

![STM32CubeProgrammer 串口下载1](https://www.weact-tc.cn/images/STM32/stm32cubeprog%E4%B8%B2%E5%8F%A31.png)
![STM32CubeProgrammer 串口下载2](https://www.weact-tc.cn/images/STM32/stm32cubeprog%E4%B8%B2%E5%8F%A32.png)

### 使用WeAct Studio Download Tool进行串口下载

[点我下载WeAct Studio Download Tool](https://www.weact-tc.cn/Download/WeAct_Studio_Download_Tool.zip)

1. 解压`WeAct Studio Download Tool`
2. 双击`WeAct Studio UART Download Tool.bat`
3. 拖入固件，或者输入软件目录下的固件名，回车输入串口号,单片机进入ISP模式,再回车开始下载
   ![img](https://www.weact-tc.cn/images/STM32/WeActStudioUARTDownLoader1.png)
4. 下载结果如图所示
   ![img](https://www.weact-tc.cn/images/STM32/WeActStudioUARTDownLoader2.png)

## USB下载（DFU下载）

USB下载也有两种烧录工具，一个是ST官方的STM32CubeProgammer，另一个是我们推出的免安装烧录工具 `WeAct Studio Download Tool`（推荐）

### 使用STM32CubeProgammer进行USB下载

1. STM32CubeProgrammer勾选USB模式
   ![img](https://www.weact-tc.cn/images/STM32/stm32cubeprogUSB1.png)
2. MCU进入ISP模式，使用USB数据线连接电脑
3. 设备管理器->通用串行总线设备出现`STM32 Bootloader`或者`DFU in FS Mode`设备，如果是`STM Device in DFU Mode`，请看[为什么烧录软件找不到设备](https://www.weact-tc.cn/2019/11/30/STM32Download/#为什么烧录软件找不到设备)，根据说明操作
4. 拖入固件，确保MCU已经进入ISP模式,点击`Download`开始下载
5. 断开连接，复位即可

### 使用WeAct Studio Download Tool进行USB下载

> [点我下载WeAct Studio Download Tool](https://www.weact-tc.cn/Download/WeAct_Studio_Download_Tool.zip)

1. 解压`WeAct Studio Download Tool`
2. 双击`WeAct Studio USB Download Tool.bat`
3. MCU进入ISP模式，使用USB数据线连接电脑
4. 设备管理器->通用串行总线设备出现`STM32 Bootloader`或者`DFU in FS Mode`设备，如果是`STM Device in DFU Mode`，请看[为什么烧录软件找不到设备](https://www.weact-tc.cn/2019/11/30/STM32Download/#为什么烧录软件找不到设备)，根据说明操作
5. 拖入固件，或者输入软件目录下的固件名,确保MCU已经进入ISP模式,点击回车开始下载，忽略`Error: Start operation failed`错误，不影响程序下载的完整性
6. 烧录结果如下，然后复位即可
   ![img](https://www.weact-tc.cn/images/STM32/weactdownloadtool1.jpg)

### 为什么烧录软件找不到设备

如果设备管理器出现的设备是`STM Device in DFU Mode`，烧录软件将无法正确识别设备，需要右键卸载设备同时勾选删除此设备的驱动程序软件，之后再安装`WeAct Studio Download Tool/DFU_Driver/Driver/`目录下的驱动，选择`STM32Bootloader.inf`，右键点选安装

### 出现Error: failed to download Segment[0]怎么解决

USB下载受天气影响可能存在一定的不稳定性，如反复出现如下ERROR或者出现`设备无法识别`，请采用串口下载，并断开USB连接。

```
Error: failed to download Segment[0]
Error: failed to download the File
```

> 上述`ERROR`造成原因：室温偏低，HSI产生偏差，`USB下载`使用的是`外部高速晶振`，而`ISP程序`（`ST的自举程序`）通过`HSI`测量外部晶振HSE频率然后再配置时钟，当`HSI`偏差过大，`HSE`测量频率不正确，从而使得USB时序不对，造成下载错误。具体详情可见网盘 `/通用文档/AN2606 STM32微控制器系统存储器自举模式.pdf`
>
> > 解决方法：适当加热MCU至`25°C`以上（`用手捂热`）

# ST-Link/J-link下载

连接STM32的SW接口：

| SW接口 |
| ------ |
| GND    |
| SCK    |
| DIO    |
| 3.3V   |

在MDK软件点击下载按钮或者在STM32CubeProg中选择ST-Link根据提示操作即可。

1. CubeMX工程或标准库工程，要使能SW调试接口，不然调试器是不能识别出MCU
2. 代码工程晶振设置不对或其他异常导致调试器不能识别MCU，此时手动设置MCU进入ISP模式，调试器就能识别出MCU，再点击下载即可
3. ISP模式只是ST公司固化在MCU里面的一段启动代码，检查BOOTx设置，运行模式则转跳地址`0x08000000`运行，下载模式则等待下载命令，此时SW调试下载接口是开放的，调试器可以读取下载MCU代码。
4. 调试接口分SW接口和JTAG接口，ARM的调试器基本都支持SW接口
5. JLink 能连接上芯片，但是不能下载，请升级Jlink驱动到最新版本，V6.50a测试可用

| JTAG接口  | 转接                           | SW接口 |
| --------- | ------------------------------ | ------ |
| TMS       |                                | SWDIO  |
| TCK       |                                | SWCLK  |
| VTEST 1脚 | 某些JLink需要接到3.3V才识别MCU | 3.3V   |
| 3.3V      |                                | 3.3V   |
| GND       |                                | GND    |

![JTAG接口 和 SW 接口](https://www.weact-tc.cn/images/STM32/JTAG.png)

# WeAct_HID_FW_Bootloader 下载

[点我下载软件](http://weact-tc.cn/Download/WeAct_HID_FW_Bootloader.zip)

> `仅支持STM32F4系列核心板`
> STM32F4核心板出厂时已经预烧录了HID Bootloader

STM32F401CC、STM32F401CE、STM32F411CE 核心板均可使用，实现类似 51 单片机下载，但无需串口，只需一根数据线，
和修改Keil工程两个地方（详情见视频）即可实现。速度比串口下载更快且更方便

![WeAct HID FW Bootloader 软件界面](https://www.weact-tc.cn/images/STM32/HIDFlash2.png)

## APP 工程修改方法

1. 修改工程ROM起始地址为 `0x8004000`
   ![STM32CubeIDE 设置](https://www.weact-tc.cn/images/STM32/stm32cubeideset.jpg)
   ![Keil MDK 设置](https://www.weact-tc.cn/images/STM32/APPSetup1MDK.png)

2. main()函数开头增加以下代码

   ```
   SCB->VTOR = FLASH_BASE | 0x4000; 
   ```

   ## 软件使用步骤

3. 将核心板用数据线连接电脑，出现WeAct HID设备

4. 按住KEY键，重新上电或复位进入Bootloader

5. 软件选择固件，点击<下载固件>即可完成下载

6. 所选固件会随KEIL重新编译而更新，无需重新选择

## 进入Bootloader方法

1. 按住<KEY键>，重新上电或复位，`C13 LED` 闪烁即可松开
2. APP进入Bootloader 参考stm32f401_test_APP 0x8004000.zip 工程

## 在Bootloader 中

1. 单击/双击<`KEY键`>为 `C13 LED` 亮灭
2. SW 调试口开放，可以用调试器烧写，无需进入DFU模式

## 退出Bootloader 方法

1. 复位MCU， 复位键/上位机点击<MCU 复位>
2. 长按<`KEY键`>，`C13 LED` 闪烁即可松开

## 注意事项

1. 首次烧录 `Bootloader`，MCU不会往下运行，同时 `C13 LED` 200MS闪烁，只需再次复位MCU即可
2. `Bootloader` 以及APP烧录软件源码均不开放

## 使用教程视频

<video width="400" height="200" controls="" __idm_id__="16385" style="display: block; margin-left: auto; margin-right: auto; max-width: 100%; margin-bottom: 20px; color: rgb(85, 85, 85); font-family: Lato, &quot;PingFang SC&quot;, &quot;Microsoft YaHei&quot;, sans-serif; font-size: 18px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: justify; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-thickness: initial; text-decoration-style: initial; text-decoration-color: initial;"></video>

> 这里强烈推荐使用调试器烧录程序，方便快捷，亦可调试
> 网上老旧资料较多，推荐参考[ST官网](https://www.stmcu.com.cn/)比较科学
> 关于stm32的下载烧录问题，不定时更新

![img](https://www.weact-tc.cn/images/weact-logo2.png)

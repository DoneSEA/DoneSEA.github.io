*此固件是基于[MicroPython](https://micropython.org)的衍生版本[MicroPython_LoBo](https://github.com/loboris/MicroPython_ESP32_psRAM_LoBo)构建的.*

## 添加了一些X1024的专用模块
*当前版本尚未完善，处于开发阶段。*
### xfpga moudle
用于X1024板子上ESP32与xilinx FPGA交互 *（当前仅支持给FPGA编程）*

```python
import xfpga
xfpga.overlay('xxx.bit')
```
你需要注意
* 你需要把.bit文件放在ESP32的 /sd/overlay/ 路径下(如果没有 overlay文件夹，手动创建一个)。
* 当前版本，配置FPGA可能需要很长的时间（测试大约需要3-4s）


## 使用方法
见test目录

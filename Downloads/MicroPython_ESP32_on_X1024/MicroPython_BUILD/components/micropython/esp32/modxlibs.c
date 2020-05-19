/*
 * This file is part of the 2019 X1024 Project
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 X1024
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * __author__:  Chen Chunhui cchhui@live.com
 * 
 * MicroPython-ESP32 on X1024
 *
 * Copyright (C) 2019 X1024 Project
 * 
 */
#include "sdkconfig.h"

#include <sys/stat.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "modxlibs.h"

#include "py/mphal.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/stream.h"
#include "extmod/vfs.h"
#include "extmod/vfs_native.h"

#include "dirent.h"

#include "esp_system.h"
#include "esp_spi_flash.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"


STATIC mp_obj_t xlibs_sstream(mp_obj_t fstream,mp_obj_t clk,mp_obj_t dout)
{
    uint8_t byte_buff[1024];
    int byte_len;
    uint8_t clk_pin,dout_pin;

    uint8_t byte;
    int i,j;

    clk_pin = mp_obj_get_int(clk);
    dout_pin = mp_obj_get_int(dout);

    mp_hal_pin_output(clk_pin);
    mp_hal_pin_output(dout_pin);
    mp_hal_pin_write(clk_pin,0);
    mp_hal_pin_write(dout_pin,0);
    
    byte_len=mp_stream_posix_read(fstream,byte_buff,1024);
    while ((byte_len!=0)&&(byte_len!=-1))
    {
        //printf("%d",byte_buff);
        //serial_sent_byte(byte_buff,_XFPGA_CCLK_,_XFPGA_DIN);
        for (i = 0;i < byte_len;i++)
        {
            byte = byte_buff[i];

            for(j = 0;j < 8;j++) 
            {
                mp_hal_pin_write(clk_pin,0);
                if ((byte&0x80) == 0x80)
                    mp_hal_pin_write(dout_pin,1);
                else
                    mp_hal_pin_write(dout_pin,0);
                byte = byte <<1;
                mp_hal_pin_write(clk_pin,1);
            } 
        }
        byte_len=mp_stream_posix_read(fstream,byte_buff,1024);     
    }
    mp_hal_pin_write(clk_pin,0);

    if(byte_len==-1)
        mp_raise_OSError(-1);
    return mp_const_none;
}

STATIC const MP_DEFINE_CONST_FUN_OBJ_3(xlibs_sstream_obj,xlibs_sstream);


//定义的xlibs全局字典，添加type和function就要添加在这里
STATIC const mp_rom_map_elem_t module_xlibs_globals_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_xlibs)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_sstream),MP_ROM_PTR(&xlibs_sstream_obj)},
};

//这个可以认为是把module_xlib_globals_table注册到 mp_module_modxlib.globals里面去
STATIC const MP_DEFINE_CONST_DICT(module_xlibs_globals, module_xlibs_globals_table); 

//这个是定义一个module类型
const mp_obj_module_t mp_module_xlibs = {
    .base = {&mp_type_module},    
    .globals = (mp_obj_dict_t *)&module_xlibs_globals,
};

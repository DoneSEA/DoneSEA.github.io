#__auther__ = 'CCHs,SWJTU'
import os
import time
import xlibs
from micropython import const
from machine import Pin


XFPGA_MODEL = '7s15ftgb196'

_XFPGA_CCLK_PIN = const(17)
_XFPGA_DIN_PIN = const(27)
_XFPGA_PROGRAM_PIN = const(25)
_XFPGA_INTB_PIN = const(26)
_XFPGA_DONE_PIN = const(34)


def bitstream_check(file_name):
    '''
    Check if the file is bitstream fil.
    :param file_name:
    :return: success:overlay_path ,fail:None
    '''

#    if (file_name.endswith('.bin') or file_name.endswith('.bit')) is False:
#       print('wrong name')
#       return None

    dir_list = os.listdir('/')
    overlay_list = os.listdir('/flash')
    if 'overlay' in overlay_list:
        overlay_list = os.listdir('/flash/overlay')
        if file_name in overlay_list:
            return '/flash/overlay/'
    elif 'sd' in dir_list:
        overlay_list = os.listdir('/sd')
        if 'overlay' in overlay_list:
            overlay_list = os.listdir('/sd/overlay')
            if file_name in overlay_list:
                return '/sd/overlay/'
    else:
        print('"' + file_name + '" does not exist in overlay folder.')
        return None



def overlay(file_name):
    '''
    Load the bitsteam file into the FPGA with serial configuration.
    :param file_name:
    :return: None
    '''

    overlay_path = bitstream_check(file_name)
    if  overlay_path == None:
        #raise ValueError('Wrong File')
        overlay_path=''

    # Soft SPI for serial output
#    xfpga_spi = SPI(1,baudrate=20000000,  polarity=0, phase=0,firstbit =SPI.MSB,\
#                    sck=Pin(_XFPGA_CCLK_PIN), mosi=Pin(_XFPGA_DIN_PIN),miso=Pin(_XFPGA_DONE_PIN))

    #GPIO Initialize
    xfpga_intb = Pin(_XFPGA_INTB_PIN,mode = Pin.OUT,pull=Pin.PULL_UP,value = 1)
    xfpga_program = Pin(_XFPGA_PROGRAM_PIN,mode=Pin.OUT,value=1)

    #FPGA configuration start sign
    xfpga_program.value(0)
    xfpga_intb.value(0)
    xfpga_program.value(1)
    xfpga_intb.value(1)

    #Sent Serial Configuration Data
    f = open(overlay_path+file_name,'rb')
    if(file_name.endswith('.bit')is True):
        f.seek(100,0)
    xlibs.sstream(f,_XFPGA_CCLK_PIN,_XFPGA_DIN_PIN)

    xfpga_done = Pin(_XFPGA_DONE_PIN)
    if xfpga_done.value() == 0:
        raise ValueError('FPGA Configuration Failed')







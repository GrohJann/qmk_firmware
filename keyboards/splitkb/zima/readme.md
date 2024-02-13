# The Vial keymap for zima

This keymap supports the configurator [vial](https://get.vial.today/). It is based on the default Zima keymap, but has the piezo buzzer and haptic sensor (which doesn't seem to work anyways) disabled. Furthermore the keylayout was edited and now unneccasary keys were removed.

This includes support for the OLED and Encoder.  However, the actual code is found in the `zima.c` file. This can be replaced by adding your own `oled_task_user(void)` and `encoder_update_user` functinons. These will replace what is in the keyboard, and allow you to customize these features. 

The screensaver image can be changed in keymap.c, and is standardly the SplitKB logo. If there is no screensaver image defined in keymap.c, then the qmk logo is used.

The reason that this is done this way, is so that this functionality will work on the [QMK Configurator](https://config.qmk.fm/#/splitkb/zima/LAYOUT_ortho_4x3)

For reference, the code used for the oled and encoder defaults is in [zima.c](https://github.com/qmk/qmk_firmware/tree/master/keyboards/splitkb/zima/zima.c).


# Setup

Paste this folder into splitkb/zima or replace all files in splitkb/zima with the contents of this folder

Change the VENDOR_ID in splitkb/zima/config.h to 0x8D1D

# Compile vial compatible firmware

compile the firmware in QMK MSYS with qmk compile -kb spiltkb/zima/vial -km default

you can replace default with eather ruvaak or doodsz
this changes the default keymap and screensaver image to the image inside thier folders

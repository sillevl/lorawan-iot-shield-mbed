# LoRaWAN IoT Shield library for mbed

Currently only support for Arm Mbed OS and C++ 11.

## Compiling with C++ 11

The library requires some things from C++ 11 so you will need to change the build profile which can be found in `mbed-os\tools\profiles\develop.json`. Change the settings of the compiler you use to enable C++ 11 support. For example for GCC_ARM:

```text
"cxx": ["-std=gnu++11", "-fno-rtti", "-Wvla"]
```

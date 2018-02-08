# LoRaWAN IoT Shield library for mbed

Currently only support for Arm Mbed OS and C++ 11.

## Starting

Clone the project and create a new Mbed OS project by executing (inside the project dir):

```shell
mbed new .
```

For the K64F and GCC_ARM add this to the `.mbed` file:

```shell
TARGET=K64F
TOOLCHAIN=GCC_ARM
ROOT=.
```

Make sure to configure the path to your compiler in `mbed_settings.py` to for example (depending on system):

```shell
GCC_ARM_PATH = "/usr/share/gcc-arm-none-eabi-7-2017-q4-major/bin/"
```

The library requires some things from C++ 11 so you will need to change the build profile which can be found in `mbed-os\tools\profiles\develop.json`. Change the settings of the compiler you use to enable C++ 11 support. For example for GCC_ARM:

```text
"cxx": ["-std=gnu++11", "-fno-rtti", "-Wvla"]
```

## Examples

To select an example application edit the file `examples/build_options.h`.

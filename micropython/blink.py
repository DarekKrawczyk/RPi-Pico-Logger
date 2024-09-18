from machine import Pin
from utime import sleep

import sys
import uos

# Get the script arguments (if passed)
script_arguments = sys.platform
print(f"Script arguments: {script_arguments}")

# Get the MicroPython version - dziala
micropython_version = sys.version
print(f"MicroPython version: {micropython_version}")

# List files in the current directory
files = uos.listdir()
#
print(f"Files in directory: {files}")

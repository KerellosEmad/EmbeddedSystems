ifeq ($(PLATFORM),HOST)

SOURCES = \
src/main.c \
src/memory.c

INCLUDES = \
-Iinclude/common

else

SOURCES = \
src/main.c \
src/memory.c \
src/startup_msp432p401r_gcc.c \
src/system_msp432p401r.c \
src/interrupts_msp432p401r_gcc.c

INCLUDES = \
-Iinclude/common \
-Iinclude/msp432 \
-Iinclude/CMSIS

endif


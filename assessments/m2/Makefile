# =========================
# Include sources
# =========================
include sources.mk

# =========================
# Default platform
# =========================
PLATFORM = HOST

# =========================
# Toolchain selection
# =========================
ifeq ($(PLATFORM),HOST)

CC = gcc

CPPFLAGS = -DHOST

CFLAGS = -Wall -Werror -g -O0 -std=c99

LDFLAGS =

else

CC = arm-none-eabi-gcc

CPPFLAGS = -DMSP432

CFLAGS = -Wall -Werror -g -O0 -std=c99 \
-mcpu=cortex-m4 \
-mthumb \
-march=armv7e-m \
-mfloat-abi=hard \
-mfpu=fpv4-sp-d16

# IMPORTANT: ABI MUST MATCH LINKER
LDFLAGS = -T msp432p401r.lds --specs=nosys.specs \
-mcpu=cortex-m4 \
-mthumb \
-mfloat-abi=hard \
-mfpu=fpv4-sp-d16

endif

# =========================
# Objects
# =========================
OBJECTS = $(SOURCES:.c=.o)
DEPFILES = $(SOURCES:.c=.d)

# =========================
# PHONY targets
# =========================
.PHONY: build compile-all clean

# =========================
# Preprocessing
# =========================
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@

# =========================
# Assembly
# =========================
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

# =========================
# Generic object rule
# =========================
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# =========================
# FIXED: Interrupt special rule (IMPORTANT)
# =========================
src/interrupts_msp432p401r_gcc.o: src/interrupts_msp432p401r_gcc.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -mgeneral-regs-only $(INCLUDES) -MMD -MP -c $< -o $@

# =========================
# Compile all (no linking)
# =========================
compile-all: $(OBJECTS)

# =========================
# Build executable
# =========================
build: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o c1m2.out
	size c1m2.out

# =========================
# Disassembly
# =========================
project.asm: c1m2.out
	objdump -d c1m2.out > project.asm

# =========================
# Clean
# =========================
clean:
	rm -f src/*.o src/*.d src/*.i src/*.asm *.out *.map project.asm

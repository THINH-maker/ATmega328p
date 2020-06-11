################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include user/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Led7Seg_FlashMemory.lss \

FLASH_IMAGE += \
Led7Seg_FlashMemory.hex \

EEPROM_IMAGE += \
Led7Seg_FlashMemory.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Led7Seg_FlashMemory.elf secondary-outputs

# Tool invocations
Led7Seg_FlashMemory.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Led7Seg_FlashMemory.map -mmcu=atmega328p -o "Led7Seg_FlashMemory.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Led7Seg_FlashMemory.lss: Led7Seg_FlashMemory.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Led7Seg_FlashMemory.elf  >"Led7Seg_FlashMemory.lss"
	@echo 'Finished building: $@'
	@echo ' '

Led7Seg_FlashMemory.hex: Led7Seg_FlashMemory.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Led7Seg_FlashMemory.elf  "Led7Seg_FlashMemory.hex"
	@echo 'Finished building: $@'
	@echo ' '

Led7Seg_FlashMemory.eep: Led7Seg_FlashMemory.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Led7Seg_FlashMemory.elf  "Led7Seg_FlashMemory.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Led7Seg_FlashMemory.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Led7Seg_FlashMemory.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Led7Seg_FlashMemory.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

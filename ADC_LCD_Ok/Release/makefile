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
ADC_LCD_Ok.lss \

FLASH_IMAGE += \
ADC_LCD_Ok.hex \

EEPROM_IMAGE += \
ADC_LCD_Ok.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC_LCD_Ok.elf secondary-outputs

# Tool invocations
ADC_LCD_Ok.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_LCD_Ok.map -mmcu=atmega328p -o "ADC_LCD_Ok.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_LCD_Ok.lss: ADC_LCD_Ok.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_LCD_Ok.elf  >"ADC_LCD_Ok.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC_LCD_Ok.hex: ADC_LCD_Ok.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ADC_LCD_Ok.elf  "ADC_LCD_Ok.hex"
	@echo 'Finished building: $@'
	@echo ' '

ADC_LCD_Ok.eep: ADC_LCD_Ok.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ADC_LCD_Ok.elf  "ADC_LCD_Ok.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_LCD_Ok.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ADC_LCD_Ok.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADC_LCD_Ok.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

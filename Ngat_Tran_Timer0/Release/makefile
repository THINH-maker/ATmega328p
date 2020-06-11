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
Dem_xung_T0.lss \

FLASH_IMAGE += \
Dem_xung_T0.hex \

EEPROM_IMAGE += \
Dem_xung_T0.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Dem_xung_T0.elf secondary-outputs

# Tool invocations
Dem_xung_T0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Dem_xung_T0.map -mmcu=atmega328p -o "Dem_xung_T0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Dem_xung_T0.lss: Dem_xung_T0.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Dem_xung_T0.elf  >"Dem_xung_T0.lss"
	@echo 'Finished building: $@'
	@echo ' '

Dem_xung_T0.hex: Dem_xung_T0.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Dem_xung_T0.elf  "Dem_xung_T0.hex"
	@echo 'Finished building: $@'
	@echo ' '

Dem_xung_T0.eep: Dem_xung_T0.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Dem_xung_T0.elf  "Dem_xung_T0.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Dem_xung_T0.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Dem_xung_T0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Dem_xung_T0.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

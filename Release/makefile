################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include server\subdir.mk
-include libraries\SPI\src\subdir.mk
-include driver\subdir.mk
-include core\core\libb64\subdir.mk
-include core\core\subdir.mk
-include application\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\labor\Documents\sloeber-workspace\OpenHR20\Release\arduino.ar \

ELF += \
OpenHR20.elf \

HEX += \
OpenHR20.hex \


# All Target
all: OpenHR20

# Tool invocations
OpenHR20: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-size" -A "C:/Users/labor/Documents/sloeber-workspace/OpenHR20/Release/OpenHR20.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\labor\Documents\sloeber-workspace\OpenHR20\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-ar" cru     C:/Users/labor/Documents/sloeber-workspace/OpenHR20/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

OpenHR20.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc" -nostdlib "-LC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/lib" "-LC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/ld" -T esp32_out.ld -T esp32.common.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.spiram_incompatible_fns.ld -u ld_include_panic_highint_hdl -u call_user_start_cpu0 -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception  -Wl,--start-group   $(LINK_OBJ)   C:/Users/labor/Documents/sloeber-workspace/OpenHR20/Release/arduino.ar  -lgcc -lopenssl -lbtdm_app -lfatfs -lwps -lcoexist -lwear_levelling -lesp_http_client -lprotobuf-c -lhal -lnewlib -ldriver -lbootloader_support -lpp -lfreemodbus -lmesh -lsmartconfig -ljsmn -lwpa -lethernet -lphy -lfrmn -lapp_trace -lfr_coefficients -lconsole -lulp -lwpa_supplicant -lfreertos -lbt -lmicro-ecc -lesp32-camera -lcxx -lxtensa-debug-module -ltcp_transport -lmdns -lvfs -lmtmn -lespcoredump -lesp_ringbuf -lsoc -lcore -lfb_gfx -lsdmmc -llibsodium -lcoap -ltcpip_adapter -lprotocomm -lesp_event -limage_util -lc_nano -lesp-tls -lasio -lrtc -lspi_flash -lwpa2 -lwifi_provisioning -lesp32 -lface_recognition -lapp_update -lnghttp -lspiffs -lface_detection -lefuse -lunity -lesp_https_server -lespnow -lnvs_flash -lesp_adc_cal -llog -ldl_lib -lsmartconfig_ack -lexpat -lfd_coefficients -lm -lmqtt -lc -lheap -lmbedtls -llwip -lnet80211 -lesp_http_server -lpthread -ljson -lesp_https_ota  -lstdc++ -Wl,--end-group -Wl,-EL -o "C:/Users/labor/Documents/sloeber-workspace/OpenHR20/Release/OpenHR20.elf"
	@echo 'Finished building: $@'
	@echo ' '

OpenHR20.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ..\makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\driver\RF12.cpp \
..\driver\hSPI.cpp 

LINK_OBJ += \
.\driver\RF12.cpp.o \
.\driver\hSPI.cpp.o 

CPP_DEPS += \
.\driver\RF12.cpp.d \
.\driver\hSPI.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
driver\RF12.cpp.o: ..\driver\RF12.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/config" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/app_trace" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/app_update" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/asio" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/bootloader_support" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/bt" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/coap" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/console" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/driver" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/efuse" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp-tls" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp32" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_adc_cal" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_event" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_http_client" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_http_server" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_https_ota" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_https_server" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_ringbuf" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/espcoredump" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/ethernet" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/expat" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/fatfs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/freemodbus" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/freertos" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/heap" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/idf_test" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/jsmn" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/json" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/libsodium" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/log" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/lwip" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mbedtls" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mdns" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/micro-ecc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mqtt" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/newlib" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/nghttp" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/nvs_flash" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/openssl" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/protobuf-c" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/protocomm" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/pthread" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/sdmmc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/smartconfig_ack" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/soc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/spi_flash" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/spiffs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/tcp_transport" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/tcpip_adapter" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/ulp" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/unity" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/vfs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wear_levelling" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wifi_provisioning" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wpa_supplicant" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/xtensa-debug-module" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp32-camera" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp-face" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/fb_gfx" -std=gnu++11 -fno-exceptions -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=240000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ARDUINO-ESP32-MASTER -DARDUINO_BOARD="ESP32_DEV" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\cores\esp32" -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\variants\esp32" -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

driver\hSPI.cpp.o: ..\driver\hSPI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/config" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/app_trace" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/app_update" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/asio" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/bootloader_support" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/bt" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/coap" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/console" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/driver" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/efuse" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp-tls" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp32" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_adc_cal" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_event" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_http_client" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_http_server" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_https_ota" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_https_server" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp_ringbuf" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/espcoredump" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/ethernet" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/expat" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/fatfs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/freemodbus" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/freertos" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/heap" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/idf_test" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/jsmn" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/json" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/libsodium" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/log" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/lwip" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mbedtls" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mdns" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/micro-ecc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/mqtt" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/newlib" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/nghttp" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/nvs_flash" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/openssl" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/protobuf-c" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/protocomm" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/pthread" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/sdmmc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/smartconfig_ack" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/soc" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/spi_flash" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/spiffs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/tcp_transport" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/tcpip_adapter" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/ulp" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/unity" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/vfs" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wear_levelling" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wifi_provisioning" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/wpa_supplicant" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/xtensa-debug-module" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp32-camera" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/esp-face" "-IC:/Users/labor/Desktop/ESP32-HR20-Projekt/Sloeber/arduino-esp32-master/tools/sdk/include/fb_gfx" -std=gnu++11 -fno-exceptions -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=240000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ARDUINO-ESP32-MASTER -DARDUINO_BOARD="ESP32_DEV" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\cores\esp32" -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\variants\esp32" -I"C:\Users\labor\Desktop\ESP32-HR20-Projekt\Sloeber\arduino-esp32-master\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '



add_executable(pid_boost main.c)

pico_set_program_name(pid_boost "pid_boost")
pico_set_program_version(pid_boost "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(pid_boost 0)
pico_enable_stdio_usb(pid_boost 1)

# Add the libraries to the build
target_link_libraries(pid_boost PRIVATE
    pico_stdlib
    pico_multicore
    hardware_adc
    # pico_async_context_freertos
    # FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(pid_boost PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(pid_boost)

add_custom_target(flash_pid_boost picotool load -f $<TARGET_FILE:pid_boost> DEPENDS pid_boost)

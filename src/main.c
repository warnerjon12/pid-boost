#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"

int main(int argc, char* argv[]) {
    while (true) {
        asm("wfi");
    }
}

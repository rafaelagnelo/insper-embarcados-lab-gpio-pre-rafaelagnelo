#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_RED = 28;
const int PIN_GREEN = 26;

const int LED_RED = 4;
const int LED_GREEN = 6;

int main() {
  stdio_init_all();

  gpio_init(PIN_RED);
  gpio_set_dir(PIN_RED, GPIO_IN);
  gpio_pull_up(PIN_RED);

  gpio_init(PIN_GREEN);
  gpio_set_dir(PIN_GREEN, GPIO_IN);
  gpio_pull_up(PIN_GREEN);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);

    while (true) {
    if (!gpio_get(PIN_RED)) {
      if (gpio_get(LED_RED) == 0) {
        gpio_put(LED_RED, 1);
      } else {
        gpio_put(LED_RED, 0);
      }
      while (!gpio_get(PIN_RED)) {
      };
    } else if (!gpio_get(PIN_GREEN)) {
        if (gpio_get(LED_GREEN) == 0) {
        gpio_put(LED_GREEN, 1);
      } else {
        gpio_put(LED_GREEN, 0);
      }
      while (!gpio_get(PIN_GREEN)) {
      };
    }
  }
}

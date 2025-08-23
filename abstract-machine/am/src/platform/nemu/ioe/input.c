#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  //kbd->keydown = 0;
  //kbd->keycode = AM_KEY_NONE;
  uint32_t key_data = inl(KBD_ADDR);
  if (key_data != AM_KEY_NONE) {
    kbd->keydown = (key_data & KEYDOWN_MASK) ? 1 : 0;
    kbd->keycode = key_data & ~KEYDOWN_MASK;
  } else {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  }
}

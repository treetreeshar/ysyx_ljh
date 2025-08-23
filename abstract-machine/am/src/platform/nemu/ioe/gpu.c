#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)//显存同步寄存器地址

void __am_gpu_init() {
  /*int i;
  uint32_t vga_ctl = inl(VGACTL_ADDR);
  int w = vga_ctl >> 16;
  int h = vga_ctl & 0xFFFF;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;//帧缓冲区地址
  for (i = 0; i < w * h; i ++) fb[i] = i;//清空帧缓冲区
  outl(SYNC_ADDR, 1);*/
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t vga_ctl = inl(VGACTL_ADDR);
  uint16_t width = vga_ctl >> 16;
  uint16_t height = vga_ctl & 0xFFFF;
  *cfg = (AM_GPU_CONFIG_T) {//结构体初始化
    .present = true, .has_accel = false,//存在，加速?
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t) //4字节：32位颜色00RRGGBB
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *vmem = (uint32_t *)FB_ADDR;
  uint32_t *pixels = (uint32_t *)ctl->pixels;//源像素数据

  uint32_t vga_ctl = inl(VGACTL_ADDR);
  uint32_t screen_width = vga_ctl >> 16;//读取宽度（用于计算线性地址）
  
  for (int y = 0; y < ctl->h; y++) {//行
    for (int x = 0; x < ctl->w; x++) {//列
      int dst_idx = (ctl->y + y) * screen_width + (ctl->x + x);//目的索引
      int src_idx = y * ctl->w + x;//源索引
      vmem[dst_idx] = pixels[src_idx];
    }
  }
  
  if (ctl->sync) {//若需要同步则刷新
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
